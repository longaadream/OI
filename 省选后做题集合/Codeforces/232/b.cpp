#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 105,  M = 1e6 + 5, mod = 1e9 + 7;
const int inf = 1e9;
int n, k;
i64 m;
int fac[N], inv[N], dp[N][N * N], c[N][N];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
    i64 x = 0,f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
    while(isdigit(c)){ x = x * 10 + (c ^ 48); c = getchar();}
    return x * f;
}
inline int C(int n, int m){
    if(n < m || n < 0 || m < 0) return 0;
    return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
    // freopen("set03.in","r",stdin);
    // freopen("set.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read(), m = read(), k = read();
    i64 tms = m / n, rem = m % n;
    fac[0] = 1;
    for(int i = 1; i <= n; i ++){
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    inv[n] = qpow(fac[n], mod - 2);
    for(int i = n; i; i --){
        inv[i - 1] = 1ll * inv[i] * i % mod;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) for(int j = 0; j <= n; j ++) c[i][j] = qpow(C(n, j), tms + (i <= rem)) % mod; 
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= std::min(k, i * n); j ++){
            for(int det = 0; det <= std::min(j, n); det ++){
                dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][j - det] * c[i][det]) % mod;
            }
        }
    }
    std::cout << dp[n][k] << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}