#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e4 + 5,  M = 65, mod = 1e9 + 7;
const int inf = 1e9;
int V, q;
int nxt[N], to[N], hd[N], edcnt, siz[N], fa[N], son[N], ans[N], ord[N];
pii a[N];
std::map<int, std::vector<int>> dp;
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
void addedge(int u, int v){
	nxt[++edcnt] = hd[u];
	to[edcnt] = v;
	hd[u] = edcnt;
}
#define nx(v, u) for(int i = hd[u], v = to[i]; i; i = nxt[i], v = to[i])
void dfs1(int u){
	siz[u] = 1;
	nx(v, u){
		dfs1(v);
		siz[u] += siz[v];
		if(siz[son[u]] < siz[v]) son[u] = v; 
	}
	// std::cerr << u << " " << siz[u] << endl;
}
void dfs2(int u, int topf, int lst, bool reset){
	if(reset) dp[topf].resize(V + 1), std::fill(dp[topf].begin(), dp[topf].end(), 0);
	// std::cerr << u << " " << topf << " " << lst << endl;
	for(int i = 0; i < a[u].first; i ++) dp[topf][i] = dp[lst][i]; 
	for(int i = a[u].first; i <= V; i ++){
		dp[topf][i] = std::max(dp[lst][i], dp[lst][i - a[u].first] + a[u].second);
	}
	int mx = 0;
	for(int i = 0; i <= V; i ++) mx = std::max(mx, dp[topf][i]);
	ans[u] = mx;
	// std::cerr << u << " " << ans[u] << endl;
	nx(v, u){
		if(v == son[u]) continue;
		dfs2(v, v, topf, 1);
	}
	if(!son[u]) return ;
	dfs2(son[u], topf, topf, 0);
}
signed main() {
    // freopen("set03.in","r",stdin);
    // freopen("set.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    q = read(), V = read();
    int lst = 1, cur, all = 1;
    for(int id = 1; id <= q; id ++){
    	std::string op;
    	std::cin >> op;
    	if(op[0] == 'a'){
    		cur = ++all;
    		addedge(lst, cur);
    		a[cur].first = read(), a[cur].second = read();
    		fa[cur] = lst;
    		lst = cur;
    	}else{
    		cur = fa[cur];
    		lst = cur;
    	}
    	ord[id] = cur;
    }
    dfs1(1);
    dfs2(1, 1, 1, 1);
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    for(int i = 1; i <= q; i ++){
    	std::cout << ans[ord[i]] << endl;
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}