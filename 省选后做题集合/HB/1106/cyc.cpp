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
const int inf = 1e9;
int n, m;
i64 op[N];
std::vector<i64> a;
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
i64 dfs(int dep, const std::vector<i64> &a){
    if(!(int)a.size()) {return 0;}
    if(dep == m + 1) {
        i64 sum = 0;
        for(i64 i:a) sum += i;
        return sum;
    }
    std::vector<i64> l, r;
    for(i64 i:a){ if((std::abs(i) % op[dep]) == 0) l.push_back(i); else r.push_back(i);}
    if(dep & 1){
        return std::min(dfs(dep + 1, l), dfs(dep + 1, r));
    }else return std::max(dfs(dep + 1, l), dfs(dep + 1, r));
}
signed main() {
    freopen("cyc.in","r",stdin);
    freopen("cyc.out","w",stdout);
    // int tt = read();
    n = read(); m = read();
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    a.resize(n);
    for(int i = 0; i <= n - 1; i ++) a[i] = read();
    for(int i = 1; i <= m; i ++) op[i] = read();
    if(m > 30) std::cout << 0 << endl;
    std::cout << dfs(1, a) << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}