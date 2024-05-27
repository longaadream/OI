#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 4, M = 1e7 + 5, mod = 998244353;
const i64 inf = 1e18;
int n, rt, siz[N], vis[N], cnt, q, dep[N], dfn[N], dfncnt, a[N], mi[20][N], mxd, fa[N], id[N], hd[N], nxt[N], to[N], edcnt;
struct BIT
{
	std::vector<int> tr;
	#define lowbit(x) x&(-x)
	void modify(int x, int det){
		x ++;
		while(x <= (int)tr.size()){
			tr[x - 1] += det;
			x += lowbit(x);
		}
	}
	int query(int x){
		int res = 0;
		x = std::min(x + 1, (int)tr.size());
		while(x){
			res += tr[x - 1];
			x -= lowbit(x);
		}
		return res;
	}
}T[N][2];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline void Add(int u,int v){
	nxt[++ edcnt] = hd[u];
	to[edcnt] = v;
	hd[u] = edcnt;
	nxt[++ edcnt] = hd[v];
	to[edcnt] = u;
	hd[v] = edcnt; 
}
#define nx(v, u) for(int i = hd[u], v = to[i]; i; i = nxt[i], v = to[i])
inline int get(int x,int y){return dep[x] < dep[y] ? x : y;}
int lca(int u, int v){
	if(u == v) return u;
	if((u = dfn[u]) < (v = dfn[v])) std::swap(u, v);
	int leg = std::__lg(u - v ++);
	return get(mi[leg][v], mi[leg][u - (1 << leg) + 1]);
}
int dis(int u,int v){return dep[u] + dep[v] - 2 * dep[lca(u, v)];}
void dfs(int u,int f){
	dep[u] = dep[f] + 1;
	mi[0][dfn[u] = ++dfncnt] = f;
	// std::cerr << u << endl;
	nx(v, u){
		if(v == f) continue;
		dfs(v, u);
	}
}
void getrt(int u,int f, int tot){
	siz[u] = 1;
	int mx = 0;
	nx(v, u){
		if(v == f || vis[v]) continue;
		getrt(v, u, tot);
		siz[u] += siz[v];
		mx = std::max(mx, siz[v]);
	}
	mx = std::max(mx, tot - siz[u]);
	if(mx * 2 <= tot) rt = u;
}
void getsiz(int u,int f){
	siz[u] = 1;
	mxd = std::max(mxd, dis(rt, u));
	nx(v, u){
		if(v == f || vis[v]) continue;
		getsiz(v, u);
		siz[u] += siz[v];
	}
}
void solve(int u,int f, int sz){
	getrt(u, 0, sz);
	u = rt, mxd = 0;
	vis[u] = 1;
	fa[u] = f;
	getsiz(u, 0);
	T[u][1].tr.resize(mxd + 1), T[u][0].tr.resize(mxd + 1 + dis(fa[u], u));
	nx(v, u){
		if(vis[v]) continue;
		solve(v, u, siz[v]);
	}
	return ;
}
void add(int u,int det){
	int x = u;
	while(x){
		T[x][1].modify(dis(u, x), det);
		if(fa[x]) T[x][0].modify(dis(fa[x], u), det);
		x = fa[x];
	}
}
int query(int u,int k){
	int x = u, res = 0;
	while(x){
		if(dis(u, x) <= k)res += T[x][1].query(k - dis(u, x));
		if(fa[x] && dis(u, fa[x]) <= k) res -= T[x][0].query(k - dis(u, fa[x]));
		x = fa[x];
	}
	return res;
}
signed main() {
	freopen("P6329_1.in","r",stdin);
	freopen("P6329.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
		n = read();
		q = read();
		for(int i = 1; i <= n; i ++) a[i] = read();
		for(int i = 1; i < n; i ++){
			int u = read(), v = read();
			Add(u, v);
		} 
		dfs(1, 0);
		// std::cerr << "orz" << endl;
		for(int j = 1;(1 << j) <= n; j ++){
			for(int i = 1; i + (1 << j) - 1 <= n; i ++){
				mi[j][i] = get(mi[j - 1][i], mi[j - 1][i + (1 << (j - 1))]);
			}
		}
		solve(1, 0, n);
		int lst = 0;
		for(int i = 1; i <= n; i ++) add(i, a[i]);
		while(q --){
			int op = read(), x = read() ^ lst, y = read() ^ lst;
			if(op == 0){
				std::cout << (lst = query(x, y))  << endl;
			}else{
				add(x, y - a[x]); a[x] = y;
			}
		}
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}