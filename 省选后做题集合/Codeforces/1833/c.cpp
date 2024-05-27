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

int a[N(2 , 5)] , odd , even;

void solve() {
    in(n);
    rep(i , 1 , n){
        in(a[i]);
        // odd[i] = even[i] = 0;
    }    
    odd = even = 0;
    sort(a + 1 , a + n + 1 , less<int>());
    int cnt1 = 0, cnt2 = 0;
    rep(i ,1 , n){
        if(i == 1){
            if(a[i] & 1){
                cnt1 ++ , odd ++;
            }else{
                cnt2 ++ , even ++;
            }
            continue;
        }
        if(a[i] & 1){
            int flag = 0;
            if(odd && cnt2){
                flag = 1;
                cnt2 ++;
            }
            if(even && cnt1){
                flag = 1;
                cnt1 ++;
            }
            if(cnt1){
                cnt1 ++;
                flag = 1;
            }
            odd ++;
            if(!flag){
                vreturn puts("NO");
            }
        }else{
            int flag = 0;
            if(odd && cnt1){
                flag = 1;
                cnt1 ++;
            }
            if(even && cnt2){
                flag = 1;
                cnt2 ++;
            }
            if(cnt2){
                cnt2 ++;
                flag = 1;
            }
            even ++;
            if(!flag){
                vreturn puts("NO");
            }
        }
    }
    vreturn puts("YES");
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
