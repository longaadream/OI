#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e3 + 5,  M = 65, mod = 1e9 + 7;
const i64 inf = 1e18;
int n, y[N];
pii a[N];
i64 dp[N][N];
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
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
    freopen("ex_pairs3.in","r",stdin);
    freopen("pairs.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read();
    for(int i = 1; i <= n; i ++) a[i].first = read(), a[i].second = read(), y[i] = a[i].second;
    std::sort(y + 1, y + n + 1);
    std::sort(a + 1, a + n + 1);
    memset(dp, 0x7f, sizeof dp);
    dp[1][0] = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= n; j ++){
            int pos = std::lower_bound(y + 1, y + n + 1, a[i].second) - y;
            if(pos > j) down(dp[i + 1][pos], dp[i][j] + a[i].first);
            if(j > pos) down(dp[i + 1][j], dp[i][j] + a[i].first);
            if(pos > j) down(dp[i + 1][j], dp[i][j] + a[i].second);
        }
    }
    i64 res = inf;
    for(int i = 0; i <= n; i ++){
        down(res, dp[n + 1][i]);
    }
    std::cout << res << endl;
    // }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}