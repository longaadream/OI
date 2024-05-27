#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 5e4 + 5, M = 105, mod = 998244353;
const int inf = 1e9;
int fa[N << 2], n, m, ans;
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
inline int findf(int x){
    return fa[x] == x ? x : fa[x] = findf(fa[x]);
}
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    // freopen("set03.in","r",stdin);
    // freopen("set.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read(), m = read();
    for(int i = 1; i <= 3 * n; i ++) fa[i] = i;
    while(m --){
        int op = read(), x = read(), y = read();
        if(x > n || y > n) {ans ++; continue;}
        int x1 = findf(x), x2 = findf(x + n), x3 = findf(x + 2 * n);
        int y1 = findf(y), y2 = findf(y + n), y3 = findf(y + 2 * n);
        if(op == 1){
            if(x2 == y1 || x3 == y1){
                ans ++;
                continue;
            }
            fa[x1] = y1, fa[x2] = y2, fa[x3] = y3;
        }else{
            if(y1  == x1 || x2 == y1){
                ans ++;
                continue;
            }
            fa[x1] = y2, fa[x3] = y1, fa[x2] = y3;
        }
        // putchar(10);
        // for(int i = 1; i <= 3; i ++){
        //     for(int j = 1; j <= 3; j ++){
        //         std::cout << findf(i + (j - 1) * n) << " ";
        //     }
        //     putchar(10);
        // }
    }
    std::cout << ans << endl;
    // }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}