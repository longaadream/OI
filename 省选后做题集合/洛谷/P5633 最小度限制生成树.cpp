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
int n, m, s, k;
std::vector<std::array<i64, 3>> E;
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
    // freopen("cyc.in","r",stdin);
    // freopen("cyc.out","w",stdout);
    // int tt = read();
    n = read(); m = read(), s = read(), k = read();
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    for(int  i = 1; i <= m; i ++) {
        E.push_back({(int)read(), (int)read(), (int)read()});
    }
    i64 l = 0, r = 1e18, ans = 0;
    while(l <= r){
        i64 mid = (l + r) >> 1;
        for(auto i:E){if(i[0] == s || i[1] == s) i[2] += mid;}
        if(chk()){
            
        }
        for(auto i:E){if(i[0] == s || i[1] == s) i[2] -= mid;}
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}