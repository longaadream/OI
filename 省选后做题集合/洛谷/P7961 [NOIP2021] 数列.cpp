n#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 35, M = 105, B = 5e2 + 5, mod = 998244353;
const int inf = 0x7fffffff;
int n, v[M][N], m, K, dp[N][M][N][2], fac[M], inv[M];//在第几位，选了几个，有几位是1，这一层堆叠了多少个1 （滚动数组）
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
    if(n < 0 || m < 0 || n < m) return 0;
    return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
    // freopen("game.in","r",stdin);
    // freopen("game.out","w",stdout);
    // int tt = read();
    n = read(), m = read(), K = read();
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    fac[0] = 1;
    for(int i = 1; i <= n; i ++){
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    inv[n] = qpow(fac[n], mod - 2);
    for(int i = n; i; i --){
        inv[i - 1] = 1ll * inv[i] * i % mod; 
    }
    for(int i = 0; i <= m; i ++){v[i][0] = 1; v[i][1] = read() % mod;for(int j = 2; j <= n; j ++) v[i][j] = 1ll * v[i][j - 1] * v[i][1] % mod;}
    // for(int i = 0; i <= m + 5; i ++) v[i][0] = 1;
    dp[0][0][0][0] = 1;
    for(int i = 0; i <= m; i ++){
        for(int j = 0; j <= n; j ++){
            for(int k = 0; k <= i; k ++){
                for(int sta = 0; sta <= n; sta ++){
                    dp[j][k][sta][1 ^ (i & 1)] = 0;
                }
            }
        }
        for(int j = 0; j <= n; j ++){
            for(int k = 0; k <= i; k ++){
                for(int sta = 0; sta <= n; sta ++){
                    for(int l = 0; l <= n - j; l ++){
                        dp[j + l][k + ((sta + l) & 1)][(sta + l)/2][1 ^ (i & 1)] = (dp[j + l][k + ((sta + l) & 1)][(sta + l)/2][1 ^ (i & 1)] + 1ll * C(l + j, j) * dp[j][k][sta][i & 1] % mod * v[i][l] % mod) % mod;
                    }
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i <= K; i ++){
        for(int j = 0; j <= n; j ++){
            if(__builtin_popcount(j) + i <= K) sum = (sum + dp[n][i][j][((m + 1) & 1)]) % mod;
        }
    }
    std::cout << sum << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}
