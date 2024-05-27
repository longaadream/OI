#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 115,  M = 1e6 + 5, mod = 1e9 + 7;
const int inf = 1e9;
int n, k;
i64 l, r;
i64 dp[N][N][2][2];
int bitl[N], bitr[N];
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
i64 dfs1(int x, int sum, bool up, bool flg){
    // std::cout << x << " " << sum << " " << up << endl;
    if(x <= 0) {return sum >= 0;}
    if(~dp[x][sum + 50][up][flg]) return dp[x][sum + 50][up][flg];
    int lim = up ? bitr[x] : 1;
    i64 res = 0;
    for(int i = 0; i <= lim; i ++){
        res += dfs1(x - 1, ((flg || i == 1)? (i == 0 ? sum + 1 : sum - 1) : 0), up && i == lim, flg || i == 1);
    }
    // std::cerr << x << " " << sum << " " << up << " " << flg << " " << res << endl;
    return dp[x][sum + 50][up][flg] = res;
}
i64 dfs2(int x, int sum, bool up, bool flg){
    // std::cout << x << " " << sum << " " << up << endl;
    if(x <= 0) {return sum >= 0;}
    if(~dp[x][sum + 50][up][flg]) return dp[x][sum + 50][up][flg];
    int lim = up ? bitl[x] : 1;
    i64 res = 0;
    for(int i = 0; i <= lim; i ++){
        res += dfs2(x - 1, ((flg || i == 1) ? (i == 0 ? sum + 1 : sum - 1) : 0), up && i == lim, flg || i == 1);
    }
    // std::cout << x << " " << sum << " " << up << " " << res << endl;
    return dp[x][sum + 50][up][flg] = res;
}
signed main() {
    freopen("round.in","r",stdin);
    freopen("round.out","w",stdout);
    int tt = read();
    clock_t be = clock();
    // int tt = 1;
    while(tt --){
        l = read() - 1, r = read();
        i64 tmpl = l, tmpr = r;
        for(int i = 1; i <= 50; i ++){
            bitl[i] = tmpl % 2;
            tmpl /= 2;
        }
        for(int i = 1; i <= 50; i ++){
            bitr[i] = tmpr % 2;
            tmpr /= 2;
        }
        memset(dp, -1, sizeof dp);
        i64 rres = dfs1(50, 0, 1, 0);
        // std::cerr << rres << endl;
        memset(dp, -1, sizeof dp);
        i64 lres = dfs2(50, 0, 1, 0);
        // std::cerr << lres << endl;
        std::cout << rres - lres << endl;
    }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}