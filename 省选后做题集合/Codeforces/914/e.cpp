#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 4e5 + 4, M = 6e7 + 5, mod = 998244353;
const int inf = 1e9;
int n, k, rt, buk[M], siz[N], vis[N], cnt, hd[N], nxt[N], to[N], edcnt;
int tmp[N], ans[N];
char s[N];
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
inline void Add(int u, int v){
	nxt[++ edcnt] = hd[u];
	to[edcnt] = v;
	hd[u] = edcnt;
	nxt[++ edcnt] = hd[v];
	to[edcnt] = u;
	hd[v] = edcnt; 
}
#define nx(v, u) for(int i = hd[u], v = to[i]; i; i = nxt[i], v = to[i])
void getrt(int u, int f, int sz){
	siz[u] = 1;
	int mx = 0;
	nx(v, u){
		if(v == f || vis[v]) continue;
		getrt(v, u, sz);
		siz[u] += siz[v];
		mx = std::max(mx, siz[v]);
	}
	mx = std::max(mx, sz - siz[u]);
	if(mx * 2 <= sz) rt = u;
}
void getsz(int u,int f){
	siz[u] = 1;
	nx(v, u){
		if(v == f || vis[v]) continue;
		getsz(v, u);
		siz[u] += siz[v];
	}
}
void getans(int u, int f, int ds){
	tmp[++cnt] = ds;
	nx(v, u){
		if(v == f || vis[v]) continue;
		getans(v, u, ds ^ (1 << (s[v] - 'a')));
	}
}
void clr(int u, int f, int ds){
	tmp[ds] --;
	nx(v, u){
		if(v == f || vis[v]) continue;
		clr(v, u, ds ^ (1 << (s[v] - 'a')));
	}
}
void solve(int u, int sz){
	getrt(u, 0, sz);
	u = rt;
	vis[u] = 1;
	getsz(u, 0);
	buk[0] = 1;
	ans[u] = 0;
	nx(v, u){
		if(vis[v]) continue;
		cnt = 0;
		getans(v, u, (1 << (s[v] - 'a')));
		for(int i = 1; i <= cnt; i ++){
			for(int chs = 0; chs < 26 ; chs ++){
				ans[u] += buk[tmp[i]^(1 << chs)];
			}
		}
		for(int i = 1; i <= cnt; i ++){
			buk[tmp[i]] ++;
		}
	}
	nx(v, u){
		if(vis[v]) continue;
		clr(v, u, (1 << (s[v] - 'a')));
	}
	nx(v, u){
		if(vis[v]) continue;
		solve(v, siz[v]);
	}
}
signed main() {
	// freopen("P6329_1.in","r",stdin);
	// freopen("P6329.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
		n = read();
		for(int i = 1; i < n; i ++){
			int u = read(), v = read();
			Add(u, v);
		}
		std::cin >> (s + 1);
		solve(1, n);
		for(int i = 1; i <= n; i ++){
			std::cout << ans[i] + 1<< " ";
		}
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}