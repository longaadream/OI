#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e3 + 5,  B = 5e2 + 5, mod = 1e9 + 7;
const int inf = 0x7fffffff;
int n, m, dp[N][N], buk[30], nxt[N][30];
char s[N], t[N];
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
std::mt19937 rnd(time(0));
signed main() {
    // freopen("stringdp.in","w",stdout);
    // freopen("string.out","w",stdout);
    // int tt = read();
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    int cnt = 0;
    while(1){
        std::cout << "case:" << ++cnt << endl;
        system("dtmk.exe");
        system("stringdp.exe");
        system("string.exe");
        if(system("fc stringdp.out string.out")){
            break;
        }
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}