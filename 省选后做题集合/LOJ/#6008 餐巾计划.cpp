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

int n , m , need[N6] , s  ,t , p , f , nn , ss , inf = 0x7fffffff;

struct edge{
    int val , to , nxt , cap;
}e[N6];
int head[N6] , cnt = 1;
void addedge(int u , int v , int w , int cap){
    e[++cnt] = (edge){w , v , head[u] , cap};
    head[u] = cnt;
}

void add(int u , int v , int w , int cap){
    addedge(u , v , w , cap);
    addedge(v , u , -w , 0);
}

int dis[N6] , vis[N6] , pre[N6] , fl[N6];

bool spfa(){
    rep(i ,0 , 2 * n + 1){
        dis[i] = fl[i] = 0x7fffffff;
    }
    queue<int> q;
    vis[s] = 1;
    dis[s] = 0;
    q.push(s);
    while(size(q)){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u] ; i ; i = e[i].nxt){
            if(dis[u] + e[i].val < dis[e[i].to] && e[i].cap){
                fl[e[i].to] = min(fl[u] , e[i].cap);
                // e[i].val -= fl[e[i].to] , e[i ^ 1].val += fl[e[i].to];
                dis[e[i].to] = e[i].val + dis[u];
                if(!vis[e[i].to])
                    q.push(e[i].to) , vis[e[i].to] = 1;
                pre[e[i].to] = i;
            }
        }
    }
    if(dis[t] == 0x7fffffff) return false;
    return true;
}

ll update(){
    int ans = 1ll * fl[t] * dis[t];
    for(int i = t ; i != s ; i = e[pre[i] ^ 1].to){
        e[pre[i]].cap -= fl[t] , e[pre[i] ^ 1].cap += fl[t];
    }
    return ans;
}

ll flowe(){
    ll ans = 0;
    while(spfa()){
        ans += update();
    }
    return ans;
}

void solve() {
    read(n);
    s = 0 , t = 2 * n + 1;
    read(p,m,f,nn,ss);
    rep(i ,1 , n){
        read(need[i]);
    }
    rep(i , 1 , n){
        int mor = 2 * i - 1 , nig = mor + 1;
        add(s , nig , 0 , need[i]);
        add(mor , t , 0 ,need[i]);
        add(s , mor , p , inf);
        if(i < n){
            add(nig , nig + 2 , 0 , inf);
        }
        if(i + m <= n){
            add(nig , mor + m * 2 , f , inf);
        }
        if(i + nn <= n){
            add(nig , mor + nn * 2 , ss , inf);
        }
    }
    write_(flowe());
    end:
    {}
    return ;
}
//#define LOCAL

signed main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
#endif
//    int tt = read<int>(_);
    // init();
    clock_t c1 = clock();
   // while (1) {
        solve();
   // }
    cerr << "Time:" << clock() - c1 << "ms" << endl;
    return 0;
}