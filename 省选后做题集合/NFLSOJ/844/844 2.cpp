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

int n , op;

int a[N6] , mod = 1e9 + 7 , inv2 = 5e8 + 4 , inv6 = 166666668;
ll ans , sum1 , sum2;

int fa[N6] , siz1[N6] , siz2[N6] , siz[N6];

int findf(int x){
    return fa[x] == x ? x : fa[x] = findf(fa[x]);
}

ll cs2(ll x){
    if(x < 2) return 0;
    return x * (x - 1) % mod * inv2 % mod;
}

ll cs3(ll x){
    if(x < 3) return 0; 
    return x * (x - 1) % mod * (x - 2) % mod * inv6 % mod;
}

void solve() {
    read(n);
    rep(i , 1 , n){
        read(a[i]);
        sum1 += a[i] == 1;
        sum2 += a[i] == 2;
    }    
    rep(i ,1 , n){
        fa[i] = i , siz[i] = 1 , siz1[i] = a[i] == 1 , siz2[i] = a[i] == 2;
    }
    ans += cs3(sum2);
    ans %= mod;
    ans += cs2(sum2) % mod * sum1 % mod;
    ans %= mod; 
    rep(tmp , 0 , n - 2){
        write_(ans);
        int x , y;
        read(x , y);
        x = findf(x) , y = findf(y);
        ans = (ans - 1ll * siz1[x] * siz2[y] * (sum2 - siz2[x] - siz2[y]) % mod);
        (ans += mod )%= mod;
        ans = (ans - 1ll * siz2[x] * siz1[y] * (sum2 - siz2[x] - siz2[y]) % mod);
        (ans += mod )%= mod;
        ans = (ans - 1ll * siz2[x] * siz2[y] * (sum1 - siz1[x] - siz1[y]) % mod);
        (ans += mod )%= mod;
        ans = (ans - 1ll * siz2[x] * siz2[y] * (sum2 - siz2[x] - siz2[y]) % mod);
        (ans += mod )%= mod;
        if(siz[x] < siz[y]) swap(x , y);
        siz[x] += siz[y];
        siz1[x] += siz1[y];
        siz2[x] += siz2[y];
        fa[y] = x; 
    }
    write_(ans);    
    end:
    {}
    return ;
}
#define LOCAL

signed main() {
#ifdef LOCAL
    freopen("failure.in", "r", stdin);
    freopen("failure.out", "w", stdout);
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
