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

int n , m , maxn = 1e6;
bool is_Prime[N(2,6)];
vector<int> p;
ll mu[N(2, 6)] , phi[N(2 , 6)];
unordered_map<int , int> smu;
unordered_map<int , ll> sphi;
void euler(){
  mu[1] = 1;
  phi[1] = 1;
  rep(i , 2 , maxn){
    if(!is_Prime[i]){
        p.pb(i);
        mu[i] = -1;
        phi[i] = i - 1;
    }
    rep(j , 0 ,size(p) - 1){
      if(p[j] * i > maxn) break;
      is_Prime[p[j] * i] = 1;
      if(i % p[j] == 0){
        mu[i * p[j]] = 0;
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i * p[j]] = 1ll * phi[i] * phi[p[j]];
      mu[i * p[j]] = -mu[i];
    }
   }
    rep(i ,1 , maxn){
        phi[i] += phi[i - 1] , mu[i] += mu[i - 1];
    }
}

ll get_phi(ll x){
    if(x <= maxn){
        return phi[x];
    }
    if(sphi[x]){
        return sphi[x];
    }
    ll res = 1ll * x * (x + 1)/2;
    ll l = 2 ;
    while(l <= x){
        ll r = x / (x / l);
        res = res - 1ll * (r - l + 1) * get_phi(x/l);
        l = r + 1;
    }
    return sphi[x] = res; 
}

ll get_mu(ll x){
    if(x <= maxn){
        return mu[x];
    }
    if(smu[x]){
        return smu[x];
    }
    ll res = 1;
    ll l = 2;
    while(l <= x){
        ll r = x / (x / l);
        res = res - 1ll * (r - l + 1) * get_mu(x/l);
        l = r + 1;
    }
    return smu[x] = res; 
}

void solve() {
    in(n);
    out(get_phi(n));
    outn(get_mu(n));
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
    in(tt);
    // init();
    clock_t c1 = clock();
    euler();
    while (tt--) {
        solve();
    }
    cerr << "Time:" << clock() - c1 << "ms" << endl;
    return 0;
}
