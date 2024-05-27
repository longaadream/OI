#include<bits/stdc++.h> 
using namespace std;
namespace IO {
char buf[1<<21], *p1 = buf, *p2 = buf, buf1[1<<21];
inline char gc () {return p1 == p2 && (p2 = (p1 = buf) + fread (buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;}

#ifndef ONLINE_JUDGE
#endif

#define gc getchar

template<class I>
inline void read(I &x) {
    x = 0; I f = 1; char c = gc();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = gc(); }
    while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = gc(); }
    x *= f;
}

template<class I>
inline void write(I x) {
    if(x == 0) {putchar('0'); return;}
    I tmp = x > 0 ? x : -x;
    if(x < 0) putchar('-');
    int cnt = 0;
    while(tmp > 0) {
        buf1[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while(cnt > 0) putchar(buf1[--cnt]);
}

#define in(x) read(x)
#define outn(x) write(x), putchar('\n')
#define out(x) write(x), putchar(' ')

} using namespace IO;
namespace Mikazuki_Munechika {
    
    typedef long long ll;
    typedef double db;
    typedef pair<int , int> pii;
    #define lowbit(a) a&-a
    #define rep(i , a , n ) for(int i (a); i <= n ; ++i)
    #define per(i , a , n ) for(int i (n); i >= a ; --i)
    #define pb push_back
    #define mp make_pair
    #define ix(l , r) ((l + r)|(l == r))
    #define gc getchar
    #define pc putchar
    #define size(x) (int)x.size()
    #define all(x) x.begin(),x.end()
    #define vreturn return (void)
    #define endl '\n'
    #define BUG(x) cerr << #x << " = " << (x) << endl
    #define BUGP(x) cout << #x << " = " << (x).first << ", " << (x).second << endl
    #define N(x , y) ((int)(x##e##y)+5)
    #define MAX(x, y) ({        \
    typeof(x) _max1 = (x);      \
    typeof(y) _max2 = (y);      \
    (void) (&_max1 == &_max2);    \
    _max1 > _max2 ? _max1 : _max2; })
    #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))
    #define __must_be_array(a)  BUILD_BUG_ON_ZERO(__same_type((a), &(a)[0]))
    # define __same_type(a, b) __builtin_types_compatible_p(typeof(a), typeof(b))
    template<typename T>inline T _gcd(T x, T y) {return y ? _gcd(y, x % y) : x;}
    template<typename T>inline T abs(T x) {return x > 0 ? x : -x;}
    template<typename T>inline T _abs(T x){return x = x > 0 ? x : -x;}
    template<typename T>inline T _max(T &x, T y) {return x = x > y ? x : y;}
    template<typename T>inline T _min(T &x, T y) {return x = x > y ? y : x;}
} using namespace Mikazuki_Munechika;

int n , m , k , inf = 0x7fffffff;

char ch[205][205] , loc[205][205];

struct edge{
    int to , val , nxt;
}e[N(2 , 6)];

int head[N(2 , 6)] , cnt = 1, s ,t , all;

void addedge(int u , int v , int w){
    e[++cnt] = (edge){v , w , head[u]};
    head[u] = cnt;
    e[++cnt] = (edge){u , 0 , head[v]};
    head[v] = cnt;
}

int pos(int x , int y){
    return (y - 1) * n + x;
}

int dist(int xx , int yy , int xxx , int yyy){
    return (xx - xxx) * (xx - xxx) + (yy - yyy) * (yy - yyy);
}

int dis[N(2 , 6)] , now[N(2 , 6)];

bool bfs(){
    rep(i ,1 , m * n * 2 + 2){
        dis[i] = 0 , now[i] = head[i];
    }
    queue<int> q;
    q.push(s);
    dis[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u] ; i ; i = e[i].nxt){
            if(!dis[e[i].to] && e[i].val){
                dis[e[i].to] = dis[u] + 1;
                if(e[i].to == t){
                    return 1;
                }
                q.push(e[i].to);
            }
        }
    }
    return 0;
}

int dfs(int u , int lim){
    if(u == t){
        return lim;
    }
    int res = 0;
    for(int &i = now[u] ; i ; i = e[i].nxt){
        if(dis[e[i].to] == dis[u] + 1 && e[i].val){
            int tmp = dfs(e[i].to , min(e[i].val , lim));
            if(tmp){
                res += tmp , lim -= tmp;
                e[i].val -= tmp , e[i ^ 1].val += tmp;
                if(!lim){
                    return res;
                }
            }else dis[e[i].to] = -1;
        }
    }
    return res;
}

int flowe(){
    int ans = 0;
    while(bfs()){
        ans += dfs(s , inf);
    }
    return ans;
}

void solve() {
    read(n) , read(m) , read(k);
    s = 2 * m * n + 1 , t = s + 1;
    rep(i ,1 , n){
        cin >> (ch[i] + 1);
    }
    rep(i ,1 , n){
        cin >> (loc[i] + 1);
    }
    rep(i ,1 , n){
        rep(j ,1 , m){
            if(loc[i][j] == 'L'){
                all ++;
                addedge(s , pos(i , j) , 1);
            }
        }
    }
    // BUG(all);
    rep(i ,1 , n){
        rep(j ,1 ,m){
            if(ch[i][j] != '0'){
                if(i + k > n || i - k < 1 || j + k > m || j - k < 1){
                    addedge(pos(i , j) + m * n , t , inf);
                }
            }
        }
    }
    rep(i ,1 , n){
        rep(j , 1 , m){
            if(ch[i][j] != '0')
                addedge(pos(i , j) , pos(i , j) + m * n, ch[i][j] - '0');
        }
    }
    rep(i ,1 , n){
        rep(j ,1 , m){
            rep(v , 1 , n){
                rep(l , 1 , m){
                    if(i == v && j == l){
                        continue;
                    }
                    if(dist(i , j , v , l ) <= k * k){
                        addedge(pos(i , j) + m * n , pos(v , l) , inf);
                    }
                }
            }
        }
    }
    outn(all - flowe());
    end:
    {}
    return ;
}


signed main() {
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int tt;
    // in(tt);
    // init();
    clock_t c1 = clock();
    // euler();
    // while (tt--) {
        solve();
    // }
    cerr << "Time:" << clock() - c1 << "ms" << endl;
    return 0;
}
