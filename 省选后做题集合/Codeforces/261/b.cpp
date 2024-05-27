#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 55,  M = 1e6 + 5, mod = 1e9 + 7;
const int inf = 1e9;
i64 n, k, dp[N][N], a[N];
double fac[N];
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
    // freopen("round3.in","r",stdin);
    // freopen("round.out","w",stdout);
    // int tt = read();
    n = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    fac[0] = 1;
    for(int i = 1; i <= n; i ++) fac[i] = fac[i - 1] * i;
    for(int i = 1; i <= n; i ++) a[i] = read();    
    k = read();
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = i; j; j --){
            for(int l = k; l; l --){
                if(a[i] <= l) dp[j][l] += dp[j - 1][l - a[i]];
            }
        }
    }
    double ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= k; j ++){
            ans += 1. * fac[i] * fac[n - i] * dp[i][j] / fac[n]; 
        }
    }
    std::cout << std::fixed << std::setprecision(4) << ans << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}