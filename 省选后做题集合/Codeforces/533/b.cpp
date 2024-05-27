#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5,  M = 1e6 + 5, mod = 1e9 + 7;
const int inf = 1e9;
i64 dp[N][2], a[N], n;
std::vector<int> E[N];
void dfs(int u){
    dp[u][1] = -inf;
    for(int v:E[u]){
        dfs(v);
        i64 x = dp[u][0], y = dp[u][1];
        dp[u][0] = std::max(dp[v][0] + x, dp[v][1] + y);
        dp[u][1] = std::max(dp[v][1] + x, dp[v][0] + y);
    }
    dp[u][1] = std::max(dp[u][1], dp[u][0] + a[u]);
    // std::cout << u << " " << dp[u] << endl;
}
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
    for(int i = 1; i <= n; i ++){
        int p = read();a[i] = read();
        if(~p) E[p].push_back(i);
    }
    dfs(1);
    std::cout << std::max(dp[1][0], dp[1][1]) << endl;
    // int tt = 1;
    // while(tt --){
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}