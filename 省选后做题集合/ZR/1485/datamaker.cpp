#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
int n, a[35];
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
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    freopen("in.in", "w", stdout);
    n = 10;
    std::cout << n << endl;
    for(int i = 1; i <= n; i ++) a[i] = a[i + n] = a[i + 2 * n] = i; 
    for(int tt = rnd() % 100; tt; tt --) std::random_shuffle(a + 1, a + 3 * n + 1);
    for(int i = 1; i <= 3 * n; i ++) std::cout << a[i] << " ";
    // std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}