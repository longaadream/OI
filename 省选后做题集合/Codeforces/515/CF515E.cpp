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

ll n , m , a[N6] , b[N6];

struct node{

ll mx , lmes , rmes;

}tr[N6];

int ix(int x , int y){
    return (x + y) | (x != y);
}

void pushup(int l , int r){
    int mid = (l + r) >> 1;
    int id = ix(l , r) , lid = ix(l , mid) , rid = ix(mid + 1 , r);
    tr[id].lmes = max(tr[rid].lmes , tr[lid].lmes);
    tr[id].rmes = max(tr[rid].rmes , tr[lid].rmes);
    tr[id].mx = max({tr[lid].mx , tr[rid].mx , tr[rid].rmes + tr[lid].lmes});      
}

void build(int l , int r){
    int id = ix(l , r);
    if(l == r){
        tr[id].lmes = 2 * b[l] - a[l - 1];
        tr[id].rmes = 2 * b[l] + a[l - 1];
        tr[id].mx = 2 * b[l]; 
        return ;
    }
    int mid = (l + r) >> 1;
    build(l , mid) , build(mid + 1 , r);
    pushup(l , r);
}

node add(node a , node b){
    node c;
    c.lmes = max(a.lmes , b.lmes);
    c.rmes = max(a.rmes , b.rmes);
    c.mx = max({a.mx , b.mx , b.rmes + a.lmes}); 
    return c;
}

node query(int L , int R , int l = 1 , int r = 2 * n){
    int id = ix(l , r);
    if(L <= l && r <= R){
        return tr[id];
    }
    int mid = (l + r) >> 1;
    if(L > mid){
        return query(L , R , mid + 1 , r);
    }
    if(mid + 1 > R){
        return query(L , R , l , mid);
    }
    return add(query(L , R , l , mid) , query(L , R , mid + 1 , r));
}

void solve() {
    read(n , m);
    rep(i ,1 , n){
        read(a[i]);
    }
    rep(i ,1 ,n){
        read(b[i]);
    }
    rep(i , n + 1 , 2 * n){
        a[i] = a[i - n];
        b[i] = b[i - n];
    }
    rep(i , 1 , 2 * n){
        a[i] += a[i - 1];
    }
    build(1 , 2 * n);
    while(m--){
        int x , y;
        read(x , y);
        if(x <= y){
            write_(query(y + 1 , x + n - 1).mx);
        }else write_(query(y + 1 , x - 1).mx);
    }
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