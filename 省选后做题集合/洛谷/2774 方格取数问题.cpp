#include<bits/stdc++.h> 
using namespace std;
namespace Mikazuki_Munechika {
    typedef long long ll;
    typedef double db;
    #define lowbit(a) a&-a
    #define pii pair<int , int>
    #define rep(i , a , n ) for(int i (a); i <= n ; i++)
    #define per(i , a , n ) for(int i (n); i >= a ; i--)
    #define aper(i , a) for(auto i : a)
    #define pb push_back
    #define mp make_pair
    #define rs(x) x<<1|1
    #define ls(x) x<<1
    #define fi first
    #define se second
    #define YES puts("Yes")
    #define NO puts("No")
    #define gc getchar
    #define pc putchar
    #define size(x) (int)x.size()
    #define all(x) x.begin(),x.end()
    #define vreturn return (void)
    #define endl '\n'
    #define doret(x) {x;return;}
    #define brk(x) {x;break;}
    #define ctn(x) {x;continue;}
    #define reset(x, y) memset(x, y, sizeof(x))
    #define BUG(x) cerr << #x << " = " << (x) << endl
    #define BUGP(x) cout << #x << " = " << (x).first << ", " << (x).second << endl
    #define ix(l , r) ((l + r) | (l != r))
    int _;
    ll __;
    template<typename T , const T mod>
    struct mint {
        int v = 0;
        mint(int _v = 0) : v(_v) {}
        mint &operator += (const mint &X) { return (v += X.v) >= mod ? v -= mod : v, *this; }
            mint &operator -= (const mint &X) { return (v += mod - X.v) >= mod ? v -= mod : v, *this; }
            mint &operator *= (const mint &X) { return v = 1ll * v * X.v % mod, *this; }
            mint &operator /= (const mint &X) { return *this *= X.inv(); }
            mint qpow(int y) const { mint res = 1, x = *this; while (y) { if (y & 1) res *= x; x *= x; y >>= 1; } return res; }
            mint inv() const { return qpow(mod - 2); }
            friend mint operator + (const mint &A, const mint &B) { return mint(A) += B; }
            friend mint operator - (const mint &A, const mint &B) { return mint(A) -= B; }
            friend mint operator * (const mint &A, const mint &B) { return mint(A) *= B; }
            friend mint operator / (const mint &A, const mint &B) { return mint(A) /= B; }
    };
    typedef mint<int , 998244353> mi9; 
    typedef mint<int , 1000000007> mi1;
    template<typename T>inline T _gcd(T x, T y) {return y ? _gcd(y, x % y) : x;}
    template<typename T>inline T abs(T x) {return x > 0 ? x : -x;}
    template<typename T>inline T _abs(T x){return x = x > 0 ? x : -x;}
    template<typename T>inline T _max(T &x, T y) {return x = x > y ? x : y;}
    template<typename T>inline T _min(T &x, T y) {return x = x > y ? y : x;}
    template<typename T>inline void _ck(T x) {vreturn (x ? YES : NO);}
    template<typename T>inline T read(T &x) {T ch = gc(), ans = 0, fl = 1;for (; !isdigit(ch) ; ch = gc())if (ch == '-')fl = -1;for (; isdigit(ch) ; ch = gc())ans = (ans << 1) + (ans << 3) + (ch ^ 48);return x = fl * ans;}
    template<typename T, typename ...Args>inline void read(T &x, Args &...args) {read(x);read(args...);}
    template<typename T>inline void write(T x) {if(x < 0 ) {pc('-');x = -x;}static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top)pc(sta[--top] + 48);pc(' ');return ;}
    template<typename T, typename ...Args>inline void write(T x, Args ...args) {write(x);write(args...);return ;}
    template<typename T, typename ...Args>inline void write_(T x) {write(x);puts("");return ;}
    template<typename T, typename ...Args>inline void write_(T x, Args ...args) {write(x);write(args...);puts("");return ;}
    const int N6 = 1000100;
    const int N5 = 100010;
    const int _N5 = 500010;
    const int _N6 = 5000100;
} using namespace Mikazuki_Munechika;

int n , m , inf = 0x7fffffff;

struct edge{
    int val , to , nxt;
}e[N6];

int head[N6] , cnt = 1 , dis[N6] , s , t , cur[N6];

void addedge(int u , int v , int w){
    e[++cnt] = (edge){w , v , head[u]};
    head[u] = cnt;
}

int mark(int x , int y){
    return n * (x - 1) + y;
}

bool bfs(){
    rep(i ,1 , n * m + 2){
        dis[i] = 0 , cur[i] = head[i];
    }
    queue<int> q;
    q.push(s);
    dis[s] = 1;
    while(size(q)){
        int u = q.front();
        q.pop();
        for(int i = head[u] ; i ; i = e[i].nxt){
            if(!dis[e[i].to] && (e[i].val)){
                dis[e[i].to] = dis[u] + 1;
                q.push(e[i].to);
                if(e[i].to == t) return 1;
            }
        }
    }
    return 0;
}

inline int dfs(int u , int flow){
    if(u == t) return flow;
    int sum = 0;
    for(int &i = cur[u] ; i ; i = e[i].nxt){
        if((dis[e[i].to] == dis[u] + 1) && (e[i].val)){
            int sav = dfs(e[i].to , min(flow , e[i].val));
            if(sav){
                sum += sav , flow -= sav;
                e[i].val -= sav , e[i ^ 1].val += sav;
                if(!flow){
                    return sum;
                }
            }else dis[e[i].to] = -1;
        }
    }
    return sum;
}

void solve() {
    read(m , n);
    s = n * m + 1 , t = n * m + 2;
    ll ans = 0;
    rep(i , 1 , m){
        rep(j , 1 , n){
            int tmp;
            read(tmp);
            ans += tmp;
            if(!((i + j) & 1)){
                addedge(s , mark(i , j) , tmp);
                addedge(mark(i , j) , s , 0);
                if(i > 1){addedge(mark(i , j) , mark(i - 1 , j) , inf); addedge(mark(i - 1 , j) , mark(i , j) , 0);}
                if(i < m){addedge(mark(i , j) , mark(i + 1 , j) , inf); addedge(mark(i + 1 , j) , mark(i , j) , 0);}
                if(j > 1){addedge(mark(i , j) , mark(i , j - 1) , inf); addedge(mark(i , j - 1) , mark(i , j) , 0);}
                if(j < n){addedge(mark(i , j) , mark(i , j + 1) , inf); addedge(mark(i , j + 1) , mark(i , j) , 0);}
            }else{
                addedge(mark(i , j) , t , tmp);
                addedge(t , mark(i , j) , 0);
            }
        }
    }
    while(bfs()){
        ans -= dfs(s , inf);
    }
    write_(ans);
}

// #define LOCAL
signed main() {
#ifdef LOCAL
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
#endif
    // int tt = read<int>(_);
    // init();
    clock_t c1 = clock();
    // while (1) {
        solve();
    // }
    cerr << "Time:" << clock() - c1 << "ms" << endl;
    return 0;
}