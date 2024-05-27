#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e6 + 5,  M = 65, mod = 1e9 + 7;
const int inf = 1e9;
int n, a[N][4], cnta[N], l[N], r[N];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
    i64 x = 0,f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
    while(isdigit(c)){ x = x * 10 + (c ^ 48); c = getchar();}
    return x * f;
}
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    freopen("in.in","r",stdin);
    freopen("1.txt","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read();
    for(int i = 1; i <= 3 * n; i ++){
        int t = read();
        a[t][++cnta[t]] = i;
    }
    int ans = 0;
    for(int bt = 0; bt < qpow(3, n); bt ++){
        int copy = bt;
        for(int i = 1; i <= n; i ++){
            int get = copy % 3;
            l[i] = a[i][get + 1], r[i] = a[i][(get + 2) % 3 == 0 ? 3 : (get + 2) % 3];
            copy /= 3;
            // std::cout << i << " " << l[i] << " " << r[i] << endl;
        }
        int flg = 1;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i == j) continue;
                // std::cout << l[i] << " " << l[j] << " " << r[j] << " " << r[i] << endl;
                if(l[i] < r[i]){
                    if((l[i] <= l[j] && l[j] <= r[i]) || (l[i] <= r[j] && r[j] <= r[i])) flg = 0;
                }else{
                    if((l[j] <= r[i] || l[j] >= l[i]) || (r[j] <= r[i] || r[j] >= l[i])) flg = 0;
                }
            }
        }
        ans += flg;
    }
    std::cout << ans << endl;
    // }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}