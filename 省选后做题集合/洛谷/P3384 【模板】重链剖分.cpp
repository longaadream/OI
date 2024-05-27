#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 1e5 + 5;
int n, m, r, p, fa[N], topf[N], siz[N], son[N], id[N], idcnt, ori[N],dep[N], a[N];
std::vector<int> E[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline void dfs1(int u, int f){
	// std::cout << u << endl;
	fa[u] = f;
	siz[u] = 1;
	dep[u] = dep[f] + 1;
	int mx = 0;
	for(int to:E[u]){
		if(to == f) continue;
		dfs1(to, u);
		siz[u] += siz[to];
		if(mx < siz[to]){
			mx = siz[to];
			son[u] = to;
		}
	}
}
inline void dfs2(int u,int f){
	// std::cout << u << endl;
	id[u] = ++ idcnt;
	ori[idcnt] = u;
	topf[u] = f;
	if(!son[u]) return ;
	dfs2(son[u], f);
	for(int to:E[u]){
		if(to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
int tr[N << 2], tag[N << 2];
void pushup(int x){
	tr[x] = (tr[x << 1] + tr[x << 1 | 1]) % p;
}
void pushdown(int x,int l,int r){
	if(!tag[x]) return ;
	tag[x << 1] += tag[x];
	tag[x << 1] %= p;
	tag[x << 1 | 1] += tag[x];
	tag[x << 1 | 1] %= p;
	int mid = (l + r ) >> 1;
	tr[x << 1] += 1ll * (mid - l + 1) * tag[x] % p;
	tr[x << 1] %= p;
	tr[x << 1 | 1] += 1ll * (r - (mid + 1) + 1) * tag[x] % p;
	tr[x << 1 | 1] %= p;
	tag[x] = 0;
}
void build(int x,int l,int r){
	if(l == r){
		tr[x] = a[ori[l]];
		return;
	}
	int mid = (l + r ) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	pushup(x);
}
void modify(int x,int l,int r,int ll,int rr,int det){
	if(ll <= l && r <= rr){
		tag[x] += det;
		tag[x] %= p;
		tr[x] += 1ll * det * (r - l + 1) % p;
		tr[x] %= p;
		return ;  
	}
	int mid = (l + r) >> 1;
	pushdown(x, l, r);
	if(mid >= ll) modify(x << 1, l, mid, ll, rr ,det);
	if(mid + 1 <= rr) modify(x << 1 | 1, mid + 1, r, ll, rr, det);
	pushup(x);
}
int query(int x,int l,int r,int ll,int rr){
	if(ll <= l && r <= rr){
		return tr[x];
	}
	int mid = (l + r) >> 1, res = 0;
	pushdown(x, l, r);
	if(mid >= ll) res = (res + query(x << 1, l, mid, ll, rr)) % p;
	if(mid + 1 <= rr) res = (res + query(x << 1 | 1, mid + 1, r, ll, rr)) % p;
	return res;
}
inline void chain_modify(int x, int y, int z){
	while(topf[x] != topf[y]){
		if(dep[topf[x]] < dep[topf[y]]) std::swap(x, y);
		modify(1, 1, n, id[topf[x]], id[x], z);
		x = fa[topf[x]];	
	}
	if(dep[x] > dep[y]) std::swap(x, y);
	modify(1, 1, n, id[x], id[y], z);
}
inline int chain_query(int x,int y){
	int res = 0;
	while(topf[x] != topf[y]){
		if(dep[topf[x]] < dep[topf[y]]) std::swap(x, y);
		res = (res + query(1, 1, n, id[topf[x]], id[x])) % p;
		x = fa[topf[x]];	
	}
	if(dep[x] > dep[y]) std::swap(x, y);
	res = (res + query(1, 1, n, id[x], id[y])) % p;
	return res;
}
inline void subtree_modify(int x,int z){
	modify(1, 1, n, id[x], id[x] + siz[x] - 1, z);
}
inline int subtree_query(int x){
	return query(1, 1, n, id[x], id[x] + siz[x] - 1);
}
signed main() {
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), m = read(), r = read(), p = read();
	clock_t be=clock();
	for(int i = 1; i <= n;i ++) a[i] = read();
	for(int i = 1; i < n; i ++){
		int x = read(), y = read();
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs1(r,r);
	dfs2(r,r);
	build(1, 1, n);
	while(m --){
		int op = read();
		if(op == 1){
			int x = read(), y = read(), z = read();
			z %= p;
			chain_modify(x, y, z);
		}else if(op == 2){
			int x = read(), y = read();
			std::cout << (p == 1? 0 : chain_query(x, y)) << endl;
		}else if(op == 3){
			int x = read(), z = read();
			z %= p;
			subtree_modify(x, z);
		}else{
			int x = read();
			std::cout << (p == 1? 0 : subtree_query(x)) << endl;
		}
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}