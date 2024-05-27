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

int n , m , mod = 1e9 + 7;
int col[N6] , siz0[N6] , siz1[N6] , cs[N6] , fa[N6] , sum1 , sum0;
struct edge{
    int to , val , nxt;
}e[N6];

int head[N6] , cnt;
ll ans;

void addedge(int u , int v , int w){
    e[++cnt] = (edge){v , w , head[u]};
    head[u] = cnt;
}

int findf(int x){
    return fa[x] == x ? x : fa[x] = findf(fa[x]);
}

ll qpow(ll a , ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = 1ll * ans * a % mod;
        }
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ans;
}

void dfs(int u , int fa){
    siz1[u] = col[u] == 1;
    siz0[u] = col[u] == 0;
    for(int i = head[u] ; i ; i = e[i].nxt){
        if(!cs[i] || e[i].to == fa) continue;
        dfs(e[i].to , u);
        siz1[u] += siz1[e[i].to];
        siz0[u] += siz0[e[i].to];
        ans = (ans + 1ll * qpow(2 , e[i].val) * ((1ll * (sum1 - siz1[e[i].to]) *  (siz0[e[i].to]) % mod + 1ll * (sum0 - siz0[e[i].to]) * (siz1[e[i].to]) % mod) % mod) % mod) % mod;
    }
}

void solve() {
    read(n , m);
    // BUG(n);
    // BUG(m);
    rep(i ,1 , n){
        read(col[i]);
        sum1 += col[i] == 1;
        sum0 += col[i] == 0;
    }
    vector<tuple<int,int,int , int, int>> v;
    rep(i ,1 , m){
        int u , vv;
        read(u , vv);
        addedge(u , vv , i);
        addedge(vv , u , i);
        v.pb(make_tuple(i , u , vv , cnt - 1 , cnt));
    }
    sort(v.begin() , v.end());
    rep(i ,1 , n){
        fa[i] = i;
    }
    rep(i , 0 , size(v) - 1){
        int uu = get<1>(v[i]) , vv = get<2>(v[i]);
        if(findf(uu) != findf(vv)){
            cs[get<3>(v[i])] = 1 , cs[get<4>(v[i])] = 1;
            fa[findf(uu)] = findf(vv);
        }
    }
    // rep(i ,1 , m){
    //     BUG(cs[i]);
    // }
    dfs(1 , 1);
    // rep(i ,1 , n){
    //     BUG(siz1[i]);
    //     BUG(siz0[i]);
    // }
    write_(ans);
    end:
    {}
    return ;
}
// #define LOCAL

signed main() {
#ifdef LOCAL
    freopen("summer.in", "r", stdin);
    freopen("summer.out", "w", stdout);
#endif
   // int tt = read<int>(_);
    // init();
    clock_t c1 = clock();
   // while (tt--) {
        solve();
   // }
    cerr << "Time:" << clock() - c1 << "ms" << endl;
    return 0;
}
