#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 3e5 + 5, M = 105, B = 5e2 + 5, mod = 998244353;
const int inf = 0x7fffffff;
int n, dfn[N], dep[N], dfncnt, st[N][25], son[N], buk[N];
i64 ans[N];
int vis[N], rt, rtmx, siz[N], tmpbuk[N], tp, D;
std::vector<int> E[N], vt;
std::vector<pii> vE[N];
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
inline int chmx(int a, int b){return dfn[a] > dfn[b] ? b : a;}
void dfs(int u, int f){
    st[dfn[u] = ++ dfncnt][0] = f;
    dep[u] = dep[f] + 1;
    for(int v:E[u]){
        if(v == f) continue;
        dfs(v, u);
    }
}
inline int lca(int u, int v){
    if(u == v) return u;
    if((u = dfn[u]) < (v = dfn[v])) std::swap(u, v);
    int d = std::__lg(u - v ++);
    return chmx(st[v][d], st[u - (1 << d) + 1][d]);
}
inline int dis(int u, int v){
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
void findrt(int u, int f, int sz){
    // std::cout << "fu: " << u << endl; 
    siz[u] = 1;
    int mx = 0;
    // std::cout << "u:" << u << endl;
    for(pii to:vE[u]){
        int v = to.first;
        // std::cout << "v:" << v << endl;
        if(v == f || vis[v]) continue;
        findrt(v, u, sz);
        siz[u] += siz[v];
        mx = std::max(mx, siz[v]);
    }
    mx = std::max(mx, sz - siz[u]);
    if(mx <= rtmx) rt = u, rtmx = mx;
}
void getsiz(int u, int f){
    siz[u] = 1;
    for(pii to:vE[u]){
        int v = to.first;
        if(v == f || vis[v]) continue;
        getsiz(v, u);
        siz[u] += siz[v];
    }
}
void getans(int u, int f, int ds){
    if(u % D == 0) {tmpbuk[++tp] = ds % D;
    // std::cerr << "tp :" << u << " " << ds % D << endl;
    }
    for(pii to:vE[u]){
        int v = to.first, dist = to.second;
        if(v == f || vis[v]) continue;
        getans(v, u, ds + dist); 
    }
}

void erase(int u, int f, int ds){
    if(u % D == 0) buk[ds % D] --;
    for(pii to:vE[u]){
        int v = to.first, dist = to.second;
        if(v == f || vis[v]) continue;
        erase(v, u, ds + dist); 
    }
}
void solve(int u, int sz){
    // std::cout << "orz" << endl;
    rtmx = 1e9, rt = -1;
    findrt(u, u, sz);
    u = rt;
    // std::cerr << "u: " << u << endl;
    vis[u] = 1;
    getsiz(u, u);
    if(u % D == 0) buk[0] = 1; else buk[0] = 0;
    for(pii to:vE[u]){
        int v = to.first, ds = to.second;
        if(vis[v]) continue;
        // std::cerr << "v :" << v << endl;
        tp = 0;
        getans(v, u, ds);
        for(int i = 1; i <= tp; i ++){
            // ans[D] += buk[D - tmpbuk[i]];
            if(tmpbuk[i]) ans[D] += buk[D - tmpbuk[i]]; else ans[D] += buk[0];
            // std::cerr << buk[D - tmpbuk[i]] << " " << D - tmpbuk[i] << endl;
            // std::cerr << buk[0] << endl;
        }
        for(int i = 1 ; i <= tp; i ++){
            buk[tmpbuk[i]] ++; 
        }
    }
    for(pii to:vE[u]){
        int v = to.first, ds = to.second;
        if(vis[v]) continue;
        erase(v, u, ds);
    }
    for(pii to:vE[u]){
        int v = to.first;
        if(vis[v]) continue;
        solve(v, siz[v]);
    }
}
signed main() {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    // int tt = read();
    n = read();
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << "MB" << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    for(int i = 1; i < n; i ++){
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(1, 1);
    for(int j = 1; (1 << j) <= n; j ++){
        for(int i = 1; i + (1 << j) - 1 <= n; i ++){
            st[i][j] = chmx(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }   
    std::vector<int> tmp;
    for(int d = 2; d <= n; d ++){
        // std::cerr << "d:" << d << endl;
        tmp.clear();vt.clear();
        for(int j = d; j <= n; j +=d){
            tmp.push_back(j);
        }
        sort(tmp.begin(), tmp.end(), [](int a, int b){
            return dfn[a] < dfn[b];
        });
        for(int i = 0; i < (int)tmp.size() - 1; i ++){
            vt.push_back(tmp[i]), vt.push_back(lca(tmp[i], tmp[i + 1]));
        }
        vt.push_back(tmp.back());
        sort(vt.begin(), vt.end(), [](int a, int b){
            return dfn[a] < dfn[b];
        });
        vt.erase(std::unique(vt.begin(), vt.end()), vt.end());
        // for(int i:vt) std::cout << i << " ";
        for(int i = 0, lc; i < (int)vt.size() - 1; i ++){
            lc = lca(vt[i], vt[i + 1]);
            // std::cerr << lc << " " << vt[i + 1] << endl;
            vE[lc].push_back(std::make_pair(vt[i + 1], dis(vt[i + 1], lc)));
            vE[vt[i + 1]].push_back(std::make_pair(lc, dis(vt[i + 1], lc)));
            // std::cerr << vt[i + 1] << " " << lc << endl;
        }
        D = d;
        solve(d, n/d);
        for(int i:vt) vE[i].clear(), vis[i] = 0;
    }
    ans[1] = 1ll * n * (n - 1) /2;
    for(int i = n; i; i --){
        for(int j = (i << 1); j <= n; j += i){
            ans[i] -= ans[j];
        }
        // std::cerr << ans[i] << endl;
    }
    i64 sum = 0;
    for(int i = 1; i <= n; i ++){
        sum += 2ll * i * ans[i] + i;
    }
    std::cout << sum << endl;
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}
