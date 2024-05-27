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

int n , a[N6] , mx[N6] , mn[N6] , b[_N6];

ll ans;
/*
h和t表示了左、右端点可以在的区间，然后通过桶来计数
*/
void cdq(int l , int r){
    if(l == r){
        ans ++;
        return ;
    }
    int mid = (l + r) >> 1;
    cdq(l , mid) , cdq(mid + 1 , r);
    mx[mid] = mn[mid] = a[mid];
    mx[mid + 1] = mn[mid + 1] = a[mid + 1];
    per(i ,l , mid - 1){
        mx[i] = max(mx[i + 1] , a[i]) , mn[i] = min(mn[i + 1] , a[i]);
    }
    rep(i , mid + 2 , r){
        mx[i] = max(mx[i - 1] , a[i]) , mn[i] = min(mn[i - 1] , a[i]);
    }
    per(i , l , mid){
        int j = mx[i] - mn[i] + i;
        if(j >= mid + 1 && j <= r && mx[j] < mx[i] && mn[j] > mn[i]) ans ++;
    }
    rep(i , mid + 1 , r){
        int j = i - (mx[i] - mn[i]);
        if(j <= mid && j >= l && mx[j] < mx[i] && mn[j] > mn[i]) ans ++;
    }
    int h = mid + 1 , t = mid + 1;
    per(i , l , mid){
        while(t <= r && mn[t] > mn[i]){
            ++ b[mx[t] - t + n];
            ++ t;
        }
        while(h < t && mx[h] < mx[i]){
            -- b[mx[h] - h + n];
            ++ h;
        }
        ans += b[mn[i] - i + n];   
    }
    while(h < t){
        --b[mx[h] - h + n];
        ++ h;
    }
    h = t = mid;
    rep(i , mid + 1 , r){
        while(h >= l && mn[h] > mn[i]) {
            ++ b[mx[h] + h];
            -- h;
        }
        while(h < t && mx[t] < mx[i]) {
            -- b[mx[t] + t];
            -- t;
        }
        ans += b[mn[i] + i];
    }
    while(h < t){
        -- b[mx[t] + t];
        -- t;
    }
}

void solve() {
    read(n);
    rep(i ,1 , n){
        read(a[i]);
    }
    cdq(1 , n);
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