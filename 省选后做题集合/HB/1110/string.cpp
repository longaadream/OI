#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5,  B = 5e2 + 5, mod = 1e9 + 7;
const int inf = 0x7fffffff;
int n, m, nxt[N][30], buk[N], ans = inf;
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
signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    // int tt = read();
    scanf("%s%s", s + 1, t + 1);
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = strlen(s + 1), m = strlen(t + 1);
    for(int i = 'a'; i <= 'z'; i ++) buk[i - 'a'] = inf;
    std::memset(nxt, 0x7f, sizeof nxt);
    int mn = 1e9;
    for(int i = m; i; i --){
        for(int j = 'a'; j <= 'z'; j ++){
            for(int k = 'a'; k < j; k ++){
                nxt[i][j - 'a'] = std::min(nxt[i][j - 'a'], buk[k - 'a']);
            }
        }
        buk[t[i] - 'a'] = i;
        mn = std::min(mn, t[i] - 'a');
    }
    if(mn > s[1]-'a') return std::cout << m << endl, 0;
    for(int i = 1, j = 1; i <= n; i ++){
        while(s[i] < t[j] && j + 1 <= m){
            j ++;
        }
        // std::cerr << i << " " << j << endl;
        if(s[i] > t[j]) ans = std::min(ans, j - i);
        else if(s[i] == t[j]) ans = std::min(ans, nxt[j][s[i] - 'a'] - i);
        if(s[i] == t[j] && i != n) ans = std::min(ans, m - i);
        j ++;
        // std::cerr << i << " " << ans << " " << j << endl;
        if(j > m) {ans = std::min(ans, m - i + 1); break;}
    }  
    // std::cout << ans << endl;
    std::cout << std::max(ans, 0) << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}