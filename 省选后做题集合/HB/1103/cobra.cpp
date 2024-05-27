#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e6 + 5,  M = 1e6 + 5, mod = 1e9 + 7;
const int inf = 1e9;
int n, q, A[N];
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
    freopen("cobra.in","r",stdin);
    freopen("cobra.out","w",stdout);
    // int tt = read();
    n = read(), q = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    for(int i = 1; i <= n; i ++) A[i] = read() - i;
    while(q --){
        int a = read(), b = read(), c = read(), d = read();
        std::cout << (c - b & 1 ? "B" : "A") << endl;
    } 
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}