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
namespace UrFather {
    
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
} using namespace UrFather;

int n , k;

int a[N(2 , 5)] , r1 , r2 , l1 , l2;

vector<int> op(int l , int r){
    // vector<int> tmp(n + 1);
    vector<int> res;
    rep(i , r + 1 , n){
        res.pb(a[i]);
    }
    per(i , l , r){
        res.pb(a[i]);
    }
    rep(i , 1 , l - 1){
        res.pb(a[i]);
    }
    return res;
}

void solve() {
    in(n);
    rep(i ,1 , n){
        in(a[i]);
        if(a[i] == n){
            r1 = i;
            l1 = i;
        }
        if(a[i] == n - 1){
            r2 = i;
            l2 = i;
        }
    }
    if(n == 1){
        vreturn puts("1");
    }
    BUG(r1);
    BUG(r2);
    vector<vector<int>> ans;
    rep(i ,1 , r1 - 1)
        ans.pb(op(i , r1 - 1));
    rep(i , 1 , r2 - 1){
        ans.pb(op(i , r2 - 1));
    }
    ans.pb(op(1 , n));
    sort(ans.begin() , ans.end());
    rep(i , 0 , n - 1){
        out(ans[size(ans) - 1][i]);
    }
    putchar(10);
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
    while (tt--) {
        solve();
    }
    cerr << "Time:" << clock() - c1 << "ms" << endl;
    return 0;
}
