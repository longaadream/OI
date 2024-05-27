#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 4e4 + 4, M = 26, mod = 998244353;
const i64 inf = 1e18;
int n, k, rt, siz[N], tot, vis[N], dis[N], cnt, buk[N];
std::vector<pii> E[N];
struct BIT
{
	int tr[N << 1];
	#define lowbit(x) x&(-x)
	void modify(int x,int det){
		while(x <= k){
			tr[x] += det;
			x += lowbit(x);
		}
	}
	int query(int x){
		int res = 0;
		while(x){
			res += tr[x];
			x -= lowbit(x);
		}
		return res;
	}
}T;
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
void getrt(int u,int f){
	siz[u] = 1;
	int mx = 0;
	for(pii to:E[u]){
		int v = to.first;
		if(v == f || vis[v]) continue;
		getrt(v, u);
		siz[u] += siz[v];
		mx = std::max(mx, siz[v]);
	}
	mx = std::max(mx, tot - siz[u]);
	if(2 * mx <= tot) rt = u;
}
void getsiz(int u,int f){
	siz[u] = 1;
	for(pii to:E[u]){
		int v = to.first;
		if(v == f || vis[v]) continue;
		getsiz(v, u);
		siz[u] += siz[v];
	}
}
void getdis(int u,int f,int ds){
	dis[u] = ds;
	if(ds <= k){
		buk[++cnt] = ds;
	}else return ;
	for(pii to:E[u]){
		int v = to.first, val = to.second;
		if(v == f || vis[v]) continue;
		getdis(v, u, ds + val);
	}
}
void clr(int u,int f, int ds){
	if(ds <= k){
		T.modify(ds, -1);
	}else return ;
	for(pii to:E[u]){
		int v = to.first, val = to.second;
		if(v == f || vis[v]) continue;
		clr(v, u, ds + val);
	}
}
int solve(int u,int sz){
	tot = sz;
	getrt(u, 0);
	u = rt;
	vis[u] = 1;
	// std::cout << u << endl;
	getsiz(u, 0);
	int ans = 0;
	for(pii to:E[u]){
		int v = to.first, val = to.second;
		if(vis[v]) continue;
		cnt = 0;
		getdis(v, u, val);
		ans += cnt;
		for(int i = 1; i <= cnt; i ++){
			ans += T.query(k - buk[i]);
		}
		for(int i = 1; i <= cnt; i ++){
			T.modify(buk[i], 1);
		}
	}
	for(pii to:E[u]){
		int v = to.first, val = to.second;
		if(vis[v]) continue;
		clr(v, u, val);
	}
	for(pii to:E[u]){
		int v = to.first;
		if(vis[v]) continue;
		ans += solve(v, siz[v]);
	}
	return ans;
}
signed main() {
	// freopen("ex_buy2.in","r",stdin);
	// freopen("buy.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	int tt = 1;
   	while(tt --){
		n = read();
		for(int i = 1; i < n; i ++){
			int u = read(), v = read(), w = read();
			E[u].push_back(std::make_pair(v, w));
			E[v].push_back(std::make_pair(u, w));
		}
		k = read();
		std::cout << solve(1, n) << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}