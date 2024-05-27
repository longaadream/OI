#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 5,  M = 1e6 + 5, mod = 1e9 + 7;
const int inf = 1e9;
int n, a[N], dp[N], lst[M];
struct BIT
{
    int tr[M];
    #define lowbit(x) x&(-x)
    void modify(int pos, int det){
        while(pos <= 1e6){
            tr[pos] = (tr[pos] + det) % mod;
            pos += lowbit(pos);
        }
    }
    int query(int pos){
        int res = 0;
        while(pos){
            res = (res + tr[pos]) % mod;
            pos -= lowbit(pos);
        }
        return res;
    }
}T;
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
    // freopen("set03.in","r",stdin);
    // freopen("set.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read();
    for(int i = 1; i <= M; i ++){
        lst[i] = 0;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        int t = read();
        T.modify(t, dp[i] = 1ll * ((1 + T.query(t)) % mod) * t % mod);
        if(lst[t]){
            T.modify(t, mod - dp[lst[t]]);
            dp[lst[t]] = 0;
        }
        lst[t] = i;
    }
    for(int i = 1; i <= n; i ++) ans = (ans + dp[i]) % mod;
    std::cout << ans << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}