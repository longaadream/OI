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
bool chk(std::string &a, std::string &b){
    int sza = (int)a.size(), szb = (int)b.size();
    if(sza >= szb){
        for(int i = 0; i < szb; i ++){
            if(a[i] > b[i]) return 0;
            if(a[i] < b[i]) return 1;
        }
        return 0;
    }else{
        for(int i = 0; i < sza; i ++){
            if(a[i] > b[i]) return 0;
            if(a[i] < b[i]) return 1;
        }
        return 1;
    }
}
signed main() {
    freopen("stringdp.in","r",stdin);
    freopen("stringdp.out","w",stdout);
    // int tt = read();
    scanf("%s%s", s + 1, t + 1);
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = strlen(s + 1), m = strlen(t + 1);
    std::string ss;
    for(int i = 1; i <= n; i ++) ss.push_back(s[i]);
    int ans = inf;
    for(int i = 0; i <= m; i ++){
        int flg = 0;
        for(int bt = 0; bt <= (1 << m) - 1; bt ++){
            if(__builtin_popcount(bt) != i) continue;
            std::string tmp;
            for(int j = 1; j <= m; j ++){
                if((1 << (j - 1)) & bt) continue;
                tmp.push_back(t[j]);
            }
            if(chk(tmp, ss)) flg = 1;
        }
        if(flg) ans = std::min(ans, i);
    }
    std::cout << ans << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}