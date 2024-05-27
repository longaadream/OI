#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5, M = 105, B = 5e2 + 5, mod = 998244353;
const int inf = 0x7fffffff;
int n, m, k, a[N];
std::set<int> s;
std::map<int, int> mp;
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
int solve(int pos, int &rem){
    int cur = std::min(rem, mp[pos]);
    rem = cur;
    int tot = 0, nxt = pos;
    while(s.upper_bound(nxt) != s.end() && cur){
        int tmp = solve(*s.upper_bound(nxt), cur);
        tot += tmp, cur -= tmp;
        nxt = *s.upper_bound(nxt);
    }
    mp[pos] -= tot;
    if(mp[pos] == 0) s.erase(pos);
    return tot;
}
signed main() {
    // freopen("game.in","r",stdin);
    // freopen("game.out","w",stdout);
    // int tt = read();
    n = read(), m = read(), k = read();
    std::cerr << (1. * (&Med - &Mbe)/1024/1024) << endl;
    clock_t be = clock();
    for(int i = 1; i <= n; i ++){
        int t = read(), t1 = read();
        s.insert(t), mp[t] = t1;
    }
    i64 ans = 0;
    for(pii i : mp){
        // std::cout << i.first << i.second << endl;
        if(!k) continue;
        if(i.second == 0) continue;
        int tmp = solve(i.first, k);
        ans += tmp;
    }
    std::cout << ans << endl;
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}
