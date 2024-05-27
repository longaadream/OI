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

int l , r , mod = 1e9 + 7;

ll qpow(ll a , ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res = 1ll * res * a % mod;
        }
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

ll fac[N(1 , 7)] , inv[N(1 , 7)];

vector<int> p;
bool isprime[N(1 , 7)];
ll cnt;

void euler(){
    isprime[1] = 1;
    // p.pb(1);
    if(l == 1){
        cnt = 1; return;
    }
    rep(i , 2 , r){
        if(!isprime[i]){
            p.pb(i);
            if(i >= l) cnt ++;
        }
        rep(j , 0 , size(p) - 1){
            if(p[j] * i > r) break;
            isprime[p[j] * i] = 1;
            if(i < l && i * p[j] >= l) cnt ++;
            if(i % p[j] == 0) break;

        }
    }
}

void solve() {
    fac[0] = inv[0] = 1;
    read(l) , read(r);
    ll n = r - l + 1;
    rep(i ,1 , r){
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    inv[r] = qpow(fac[r] , mod - 2);
    // BUG(inv[r]);
    per(i , 1 , r - 1){
        inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
    }
    euler();
    ll ans = 0;
    rep(i , cnt - 1 , n - 1){
        ans = (ans + 1ll * fac[i] * inv[i - cnt + 1] % mod * (i + 1) % mod) % mod;
    }
    ans = 1ll * ans * cnt % mod * fac[n - cnt] % mod;
    outn(ans);
    end:
    {}
    return ;
}

// #define LOCAL

signed main() {
#ifdef LOCAL
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
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
