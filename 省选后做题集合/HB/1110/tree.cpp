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
const int inf = 0x7fffffff;
int n, st[N][20], dfn[N], cnt, dep[N];
std::vector<int> E[N];
bool isp[N];
    int mu[N];
    std::vector<int> p;

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
namespace sub1{
    int chmx(int a, int b){return dfn[a] > dfn[b] ? b : a;}
    void dfs(int u, int f){
        st[dfn[u] = ++cnt][0] = f;
        dep[u] = dep[f] + 1;
        for(int v:E[u]){
            if(v == f) continue;
            dfs(v, u);
        }
    }
    inline int lca(int u, int v){
        if(u == v) return u;
        if((u = dfn[u]) < (v = dfn[v])) std::swap(u, v);
        int lg = std::__lg(u - v ++);
        return chmx(st[v][lg], st[u - (1 << lg) + 1][lg]);
    }
    inline int dis(int u, int v){
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    void solve(){
        for(int i = 2; i <= n; i ++){
            int u = read(), v = read();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        dfs(1, 1);
        for(int j = 1; (1 << j) <= n; j ++){
            for(int i = 1; i + (1 << j) - 1 <= n; i ++){
                st[i][j] = chmx(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
        i64 ans = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                ans += std::__gcd(std::__gcd(i, j), dis(i, j));
            }
        }
        std::cout << ans << endl;
    }
};
namespace sub2{
    void solve(){
        i64 ans = 0;
        ans = 2 * n - 2 + 1ll * n * (n + 1)/2;
        for(int i = 2; i <= n; i ++){
            if(i & 1) {
                ans += n - 2;
            }else ans += (n/2 - 1) * 2 + (n - 1 - n/2);
        }
        std::cout << ans << endl;
    }
};
namespace sub3{
    i64 f(int x,int y){
        i64 ans = 0;
        for(int l=1,r;l<=x;l=r+1){
            r = std::min(x/(x/l),y/(y/l));
            ans += (mu[r]-mu[l-1])*(x/l)*(y/l);
        }
        return ans;
    }
    void solve(){
        memset(mu,-1,sizeof mu);
        mu[1] = 1;
        for(int i=2;i<=n;++i){
            if(isp[i]==0) p.push_back(i);
            for(int j=0;j<=(int)p.size()&&i*p[j]<=n;++j){
                isp[i*p[j]] = 1;
                mu[i*p[j]] = -mu[i];
                if(i%p[j]==0){
                    mu[i*p[j]] = 0;
                    break;
                }
            }
        }
        for(int i=1;i<=n;++i) mu[i] = mu[i-1] + mu[i];
        i64 ans = 0;
        for(int l=1,r;l<=n;l=r+1){
            r = n/(n/l);
            ans += (l+r)*(r-l+1)/2*f(n/l,n/l);
        }
        std::cout << ans << endl;
    }
};
signed main() {
    // freopen("tree.in","r",stdin);
    // freopen("tree.out","w",stdout);
    // int tt = read();
    n = read();
    // sub3::solve();
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    if(n <= 5000){
        sub1::solve();
        return 0;
    }
    int flg1 = 0, flg2 = 0;
    for(int i = 1; i <= n - 1; i ++){
        int u = read(), v = read();
        if(u != 1) flg1 = 1;
        if(u != i || v != i + 1) flg2 = 1;
    }
    if(!flg1){
        sub2::solve();
        return 0;
    }
    if(!flg2){
        sub3::solve();
        return 0;
    }
    // int tt = 1;
    // while(tt --){
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}