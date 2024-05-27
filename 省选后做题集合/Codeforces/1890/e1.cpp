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
int l[N], r[N], n, m, k;
std::vector<int> g[N],t[N];
std::set<int> s;
std::map<std::set<int>,int> cnt;
std::vector<std::set<int>> ca;
std::vector<pii> aa;
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
        n = read(), m = read(), k = read();
        cnt.clear(), ca.clear(), s.clear(), aa.clear();
        for(int i = 1; i <= n; i ++) g[i].clear(), t[i].clear();
        for(int i = 1; i <= m; i ++){
            l[i] = read(), r[i] = read();
            g[l[i]].push_back(i), t[r[i]+1].push_back(i);
        }
        for(int i = 1; i <= n; i ++){
            for(int u:g[i]){
                s.insert(u);
            }
            for(int u:t[i]){
                s.erase(u);
            }
            if(s.size() < 3){
                cnt[s] ++;
                ca.push_back(s);
            }
        }
        int mn = n;
        for(auto u:ca){
            if(u.size() == 2){
                mn = std::min(mn, n - cnt[u] - cnt[{*u.begin()}]-cnt[{*u.rbegin()}]-cnt[{}]);
            }else if(u.size() == 1){
                mn = std::min(mn, n - cnt[u] - cnt[{}]);
            }else{
                mn = std::min(mn, n - cnt[{}]);
            }
        }
        // std::cout << "orz" << endl;
        for(int i = 1; i <= m; i ++){
            aa.push_back({cnt[{i}], i});
        }
        sort(aa.begin(), aa.end());
        if(aa.size() >= 2){
            mn = std::min(mn, n - aa[aa.size() - 1].first - aa[aa.size() - 2].first - cnt[{}]);
        }
        n -= mn;
        std::cout << n << endl;
    }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}