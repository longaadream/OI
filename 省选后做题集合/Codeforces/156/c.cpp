#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e2 + 5, M = 65, mod = 1e9 + 7;
const int inf = 1e9;
int n, m;
i64 dp[N][26 * N];
char s[N];
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
    dp[0][0] = 1;
    for(int i = 1; i <= 100; i ++){
        for(int j = i; j <= 26 * i; j ++){
            for(int k = 1; k <= 26 && k <= j; k ++){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
            }
        }
    }
    while(tt --){
        scanf("%s", s + 1);
        n = strlen(s + 1);
        int sum = 0;
        for(int i = 1; i <= n; i ++){
            sum += s[i] - 'a' + 1;
        }
        std::cout << (dp[n][sum] - 1 + mod) % mod << endl;
    }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}