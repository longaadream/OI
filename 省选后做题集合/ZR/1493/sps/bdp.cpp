#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 5,  B = 5e2, mod = 1e9 + 7;
const int inf = 1e9;
int n, m ,sum[N];
pii a[N];
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
signed main(){
    freopen("bb.in","r",stdin);
    freopen("b1.out","w",stdout);
    // int tt = read();
    n = read(), m = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    for(int i = 1; i <= n; i ++) a[i].first = read(), a[i].second = read();
    while(m --){
        int x = read(), det = read();
        int mx = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i].first <= x && x <= a[i].second){
                sum[i] += det;
            }
            mx = std::max(mx, sum[i]);
        }
        std::cout << mx << endl;
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}