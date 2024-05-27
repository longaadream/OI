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
int n;
int nxt[N], hd[N], dfn[N], st[N][20], to[N], val[N], edcnt, a[N];
i64 dep[N];
int dfncnt;
i64 sum;
int id[N];
std::set<int> s;
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
inline void addedge(int u, int v){
    nxt[++ edcnt] = hd[u];
    to[edcnt] = v;
    hd[u] = edcnt;
}
inline int ckmx(int x, int y){return dfn[x] < dfn[y] ? x : y;}
#define nx(v, u) for(int i = hd[u], v = to[i]; i; i = nxt[i], v = to[i])
void dfs(int u, int f){
    dep[u] = dep[f] + a[u];
    st[dfn[u] = ++ dfncnt][0] = f;
    id[dfn[u]] = u;
    nx(v, u){
        if(v == f) continue; 
        dfs(v, u);
    }
}
inline int lca(int u, int v){
    if(u == v) return u;
    if((u = dfn[u]) < (v = dfn[v])) std::swap(u, v);
    int d = std::__lg(u -  v ++);
    return ckmx(st[v][d], st[u - (1 << d) + 1][d]);
}
inline i64 dis(int u, int v){
    return dep[u] + dep[v] - 2ll * dep[lca(u, v)] + a[lca(u, v)];
}
inline char reac(){
    char s = getchar();
    while(s != '+' && s != '-' && s != '?') s = getchar();
    return s;
}
inline void add(int k){
    if(s.size() == 2) s.insert(dfn[k]), sum = a[k];
    else if(s.size() == 3) sum = 0, sum += 2 * dis(k, id[*++s.begin()]),s.insert(dfn[k]);
    else{
        int dk = dfn[k];
        if(*s.upper_bound(dk) == inf){
            sum += dis(k, id[*++s.begin()]);
            sum += dis(k, id[*--s.lower_bound(dk)]);
            sum -= dis(id[*++s.begin()], id[*--s.lower_bound(dk)]);
            s.insert(dk);
            sum -= a[k];
        }else if(*--s.lower_bound(dk) == -inf){
            sum += dis(k, id[*----s.end()]);
            // std::cout << *----s.end() << endl;
            sum += dis(k, id[*s.upper_bound(dk)]);
            sum -= dis(id[*----s.end()], id[*s.upper_bound(dk)]);
            s.insert(dk);
            sum -= a[k];
        }else{  
            int up = id[*s.upper_bound(dk)], dw = id[*--s.lower_bound(dk)];
            sum -= dis(up, dw);
            sum += dis(up, k);
            sum += dis(dw, k);
            s.insert(dk);
            sum -= a[k];
        }
    }
}
inline void del(int k){
    if(s.size() == 3){
        s.erase(dfn[k]);
        sum = 0;
        return ;
    } 
    if(s.size() == 4){
        s.erase(dfn[k]);
        sum = a[*++s.begin()];
        return ;
    }
    int dk = dfn[k];
    if(*s.upper_bound(dk) == inf){
            sum -= dis(k, id[*++s.begin()]);
            sum -= dis(k, id[*--s.lower_bound(dk)]);
            sum += dis(id[*++s.begin()], id[*--s.lower_bound(dk)]);
            s.erase(dk);
            sum += a[k];
        }else if(*--s.lower_bound(dk) == -inf){
            sum -= dis(k, id[*----s.end()]);
            sum -= dis(k, id[*s.upper_bound(dk)]);
            sum += dis(id[*----s.end()], id[*s.upper_bound(dk)]);
            s.erase(dk);
            sum += a[k];
        }else{  
            int up = id[*s.upper_bound(dk)], dw = id[*--s.lower_bound(dk)];
            sum += dis(up, dw);
            sum -= dis(up, k);
            sum -= dis(dw, k);
            s.erase(dk);
            sum += a[k];
        }
}
signed main() {
    // freopen("tree.in","r",stdin);
    // freopen("tree.out","w",stdout);
    // int tt = read();
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    s.insert(inf), s.insert(-inf);
    // int tt = 1;
    // while(tt --){
    n = read();
    for(int i = 1; i <= n; i ++) a[i] = read();
    for(int i = 1; i <= n - 1; i ++){
        int u = read(), v = read();
        addedge(u, v), addedge(v, u);
    }
    dfs(1, 1);
    // for(int i = 1; i <= n; i ++) std::cout << dfn[i] << endl;
    for(int j = 1; (1 << j) <= n; j ++){
        for(int i = 1; i + (1 << j) - 1 <= n; i ++){
            st[i][j] = ckmx(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    int k = read();
    for(int i = 1; i <= k; i ++){
        int t = read();
        if(!s.count(t)) add(t);
    }
    std::cout << sum/2 << endl;
    int q = read();
    while(q --){
        int op = read();
        if(op == 1){
            int k = read();
            if(s.count(dfn[k])) goto end;
            add(k);
        }else{
            int k = read();
            if(!s.count(dfn[k])) goto end;
            del(k);
        }
        end:{};
        std::cout << sum / 2<< endl;
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}
