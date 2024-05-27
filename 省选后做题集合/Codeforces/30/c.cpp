#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e3 + 5,  M = 1e6 + 5, mod = 1e9 + 7;
const int inf = 1e9;
struct node{
    int x, y, t;double p;
}a[N];
int n;
double dp[N];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
    i64 x = 0,f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
    while(isdigit(c)){ x = x * 10 + (c ^ 48); c = getchar();}
    return x * f;
}
bool check(int x, int y){
    i64 dis1 = 1ll * (a[x].x - a[y].x) * (a[x].x - a[y].x) + 1ll * (a[x].y - a[y].y) * (a[x].y - a[y].y);
    i64 dis2 = 1ll * (a[x].t - a[y].t) * (a[x].t - a[y].t);
    return dis1 <= dis2;
}
signed main() {
    // freopen("round3.in","r",stdin);
    // freopen("round.out","w",stdout);
    // int tt = read();
    n = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    for(int i = 1; i <= n; i ++){
        a[i].x = read(), a[i].y = read(), a[i].t = read(); std::cin >> a[i].p;
    }
    std::sort(a + 1, a + n + 1, [](node a, node b){return a.t < b.t;});
    #define sqr(x) 1ll * x * x
    double ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j < i; j ++){
            if(check(i, j)){
                dp[i] = std::max(dp[i], dp[j]);
            }
        }
        dp[i] += a[i].p;
        ans = std::max(ans, dp[i]);
    }
    std::cout << std::fixed << std::setprecision(6) << ans << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}