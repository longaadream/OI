#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 16, M = 65, mod = 1e9 + 7;
const int inf = 1e9;
i64 n, m, dp[1 << N][N], a[N][N], sum[1 << N], ans;
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
    int tt = read();
    clock_t be = clock();
    // int tt = 1;
    n = read(), m = read();
    for(int i = 1; i <= m; i ++){
        int x = read(), y = read(), w = read();
        sum += (a[x][y] = a[y][x] = w);
    }
    int full = (1 << n) - 1;
    for(int bt = 0; bt <= full; bt ++){
        for(int i = 1; i <= n; i ++){
            if(!((1 << (i - 1)) & bt)){
                for(int j = 1; j <= n; j ++){
                    if((1 << (j - 1)) & bt) sum[bt | (1 << (i - 1))] += a[i][j];
                }
            }
        }
    }
    for(int bt = 1; bt <= full; bt ++){
        for(int i = 1; i <= n; i ++){
            if((1 << (i - 1)) & bt){
                for(int sbt = bt & (bt - 1); sbt; sbt = sbt & (sbt - 1)){

                }
            }
        }
    }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}