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

int n , m , k;

char mat[2005][2005];
int dis[2005][2005];
int dx[] = {0 , 1 , 0 , -1};
int dy[] = {1 , 0 , -1 , 0};

int cheque(int sx , int sy){
    int ans;
    if(sx == 1 || sx == n || sy == 1 || sy == m) return ans = 0;
    return (min({n - sx , sx - 1 , m - sy , sy - 1})+ k - 1)/k;
}

void solve() {
    memset(dis , 0x3f , sizeof dis);
    memset(mat , 0 , sizeof mat);
    read(n , m , k);
    map<pii , bool> pm;
    rep(i , 1 , n){
        cin >> (mat[i] + 1);
    }
    int sx , sy;
    rep(i ,1 , n){
        rep(j ,1 , m){
            if(mat[i][j] == 'S'){
                sx = i , sy = j;
            }
        }
    }
    if(cheque(sx , sy) == 0){
        vreturn puts("0");
    }
    queue<pii> q;
    q.emplace(mp(sx , sy));
    dis[sx][sy] = 0;
    int ans = 0x7fffffff;
    while(!q.empty()){
        // cerr << "orz" << endl;
        pii top = q.front();
        // BUGP(top);
        q.pop();
        pm[top] = 0;
        if(dis[top.first][top.second] <= k)_min(ans , cheque(top.first , top.second));
        if(dis[top.first][top.second] >= k) continue;
        for(int i = 0 ; i <= 3 ; i ++){
            int xx = top.first + dx[i] , yy = top.second + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if(mat[xx][yy] == '#') continue;
            if(dis[xx][yy] > dis[top.first][top.second] + 1){
                dis[xx][yy] = dis[top.first][top.second] + 1;
                if(!pm[mp(xx , yy)]){    
                    q.emplace(mp(xx , yy));
                    pm[mp(xx,yy)] = 1;
                }
            }
         }
    }
    write_(ans + 1);
    end:
    {}
    return ;
}
// #define LOCAL

signed main() {
#ifdef LOCAL
    freopen("escape.in", "r", stdin);
    freopen("escape.out", "w", stdout);
#endif
   int tt ;
   scanf("%d" , & tt);
    // init();
    clock_t c1 = clock();
   while (tt--) {
        solve();
   }
    cerr << "Time:" << clock() - c1 << "ms" << endl;
    return 0;
}
