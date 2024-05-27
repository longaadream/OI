#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1005, M = 65, mod = 998244353;
const int inf = 1e9;
int n, m, q, dis[M][M][M], dp[M][M][N];
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
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    // freopen("set03.in","r",stdin);
    // freopen("set.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
        n = read(), m = read(), q = read();
        memset(dp, 0x3f, sizeof dp);
        memset(dis, 0x3f, sizeof dis);
        for(int num = 1; num <= m; num ++){
            for(int i = 1; i <= n; i ++){
                for(int j = 1; j <= n; j ++){
                    dis[num][i][j] = read();
                }
            }
            for(int  k = 1; k <= n; k ++){
                for(int i = 1; i <= n; i ++){
                    for(int j = 1; j <= n; j ++){
                        dis[num][i][j] = std::min(dis[num][i][j], dis[num][i][k] + dis[num][k][j]);
                    }
                }
            }
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                for(int num = 1; num <= m; num ++){
                    dp[i][j][0] = std::min(dp[i][j][0], dis[num][i][j]);
                }
            }
        }
        for(int times = 1; times <= 1000; times ++){
            for(int k = 1; k <= n; k ++){
                for(int i = 1; i <= n; i ++){
                    for(int j = 1; j <= n; j ++){
                        dp[i][j][times] = std::min(dp[i][j][times], dp[i][k][times - 1] + dp[k][j][0]);
                    }
                }
            }
        }
        while(q--){
            int s = read(), t = read(), k = read();
            std::cout << dp[s][t][k] << endl;
        }
    // }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}