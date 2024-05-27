#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 3e4 + 5, M = 105, B = 5e2 + 5, mod = 998244353;
const int inf = 0x7fffffff;
int n, V, m, dp[N][M];
pii a[N];
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
signed main() {
    // freopen("game.in","r",stdin);
    // freopen("game.out","w",stdout);
    // int tt = read();
    n = read();
    std::cerr << (1. * (&Med - &Mbe)/1024/1024) << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    for(int i = 1; i <= n; i ++) a[i].first = read();
    for(int i = 1; i <= n; i ++) a[i].second = read(), V += a[i].first, m += a[i].second;
    sort(a + 1, a + n + 1, [](pii a, pii b){
        return a.second > b.second;
    });
    int tot = 0, ans = 0;
    for(int i = 1; i <= n; i ++) {tot += a[i].second;ans = i;if(tot >= V) break;}
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = m; j >= a[i].second; j --){
            for(int k = 1; k <= n; k ++){
            dp[j][k] = std::max(dp[j][k], dp[j - a[i].second][k - 1] + a[i].first);
            // std::cout << i << " " << j << " " << k << " " << dp[j][k] << " " << dp[j - a[i].second][k - 1] + a[i].first << endl; 
            }
        }
    }
    int mx = 0;
    for(int i = tot; i <= m; i ++){
        mx = std::max(mx, dp[i][ans]);
    }
    std::cout << ans << ' ' << V - mx << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}
