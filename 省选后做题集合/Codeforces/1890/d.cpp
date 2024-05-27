#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5,  M = 65, mod = 1e9 + 7;
const int inf = 1e9;
i64 n;
std::pair<i64, int> a[N];
i64 sum;
int c, vis[N];
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
    while(tt --){
        n = read(), sum = 0, c = read();
        // memset(vis, 0, sizeof vis);
        sum = read();
        for(int i = 1; i <= n - 1; i ++) a[i] = std::make_pair(read(), i + 1);
        std::sort(a + 1, a + n, [](std::pair<i64,int> a, std::pair<i64,int> b){
            return a.first - 1ll * a.second * c > b.first - 1ll * b.second * c;
        });
        int flg = 1;
        for(int i = 1; i <= n - 1; i ++){
            if((sum + a[i].first) >= 1ll * a[i].second * c){
                sum += a[i].first;
            }else{
                // std::cout << sum + a[i].first << a[i].second << endl;
                flg = 0;
                break;
            }
            // std::cout << a[i].second << " ";
        }
        std::cout << (flg ? "Yes" : "No") << endl;
    }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}