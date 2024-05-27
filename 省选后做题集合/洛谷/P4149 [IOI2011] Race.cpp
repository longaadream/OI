#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 4e5 + 4, M = 1e6 + 5, mod = 998244353;
const int inf = 1e9;
int n, k, rt, buk[M], siz[N], vis[N], cnt, hd[N], nxt[N], to[N], edcnt, vl[N];
pii tmp[N];
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline void Add(int u,int v, int w){
	nxt[++ edcnt] = hd[u];
	to[edcnt] = v;
	vl[edcnt] = w;
	hd[u] = edcnt;
	nxt[++ edcnt] = hd[v];
	to[edcnt] = u;
	vl[edcnt] = w;
	hd[v] = edcnt; 
}
#define nx(v, val, u) for(int i = hd[u], v = to[i], val = vl[i]; i; i = nxt[i], v = to[i], val = vl[i])
void getrt(int u, int f, int sz){
	siz[u] = 1;
	int mx = 0;
	nx(v, val, u){
		if(v == f || vis[v]) continue;
		getrt(v, u, sz);
		siz[u] += siz[v];
		mx = std::max(mx, siz[v]);
	}
	mx = std::max(mx, sz - siz[u]);
	if(2 * mx <= sz) rt = u;
}
void getsz(int u,int f){
	siz[u] = 1;
	nx(v, val, u){
		if(v == f || vis[v]) continue;
		siz[u] += siz[v];
	}
}
void getans(int u,int f,int ds, int step){
	if(ds <= k){
		tmp[++ cnt] = std::make_pair(ds, step);
	}else return ;
	nx(v, val, u){
		if(v == f || vis[v]) continue;
		getans(v, u, ds + val, step + 1);
	}
}
void clr(int u, int f, int ds){
	if(ds <= k){
		buk[ds] = inf;
	}else return ;
	nx(v, val, u){
		if(v == f || vis[v]) continue;
		clr(v, u, ds + val);
	}
}
int solve(int u, int sz){
	getrt(u, 0, sz);
	u = rt;
	vis[u] = 1;
	getsz(u, 0);
	int ans = inf;
	nx(v, val, u){
		cnt = 0;
		if(vis[v]) continue;
		getans(v, u, val, 1);
		for(int i = 1; i <= cnt; i ++){
			ans = std::min(ans, tmp[i].second + buk[k - tmp[i].first]);
		}
		for(int i = 1; i <= cnt; i ++){
			buk[tmp[i].first] = std::min(buk[tmp[i].first], tmp[i].second);
		}
	}
	nx(v, val, u){
		if(vis[v]) continue;
		clr(v, u, val);
	}
	nx(v, val, u){
		if(vis[v]) continue;
		ans = std::min(solve(v, siz[v]), ans);
	}
	return ans;
}
signed main() {
	// freopen("P6329_1.in","r",stdin);
	// freopen("P6329.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
		n = read(), k = read();
		for(int i = 1; i <= k; i ++){
			buk[i] = inf;
		}
		for(int i = 1; i < n; i ++){
			int u = read() + 1, v = read() + 1, w = read();
			Add(u, v, w);
		}
		int res = solve(1, n);
		std::cout << (res == inf ? -1 : res) << endl;
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}