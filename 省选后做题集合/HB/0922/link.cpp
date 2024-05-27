#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e6+5;
int n, q, dfn[N], topf[N], dfncnt, son[N], fa[N], siz[N], dep[N], id[N], idcnt, ret[N], st[N][25];
std::vector<int> E[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
void dfs1(int x, int f){
	st[dfn[x] = ++dfncnt][0] = f;
	siz[x] = 1;
	fa[x] = f;
	dep[x] = dep[f] + 1;
	int mx = 0;
	for(int v:E[x]){
		if(v == f) continue;
		dfs1(v, x);
		siz[x] += siz[v];
		if(siz[v] > mx) {mx = siz[v], son[x] = v;}
	}
}
void dfs2(int x, int f){
	id[x] = ++idcnt, ret[idcnt] = x;
	topf[x] = f;
	if(!son[x]) return ;
	dfs2(son[x], f);
	for(int v:E[x]){
		if(v == fa[x] || v == son[x]) continue;
		dfs2(v, v);
	}
}
int ckmx(int a, int b){return dfn[a] < dfn[b] ? a : b;}
int lca(int u,int v){
	if(u == v) return u;
	if((u = dfn[u]) < (v = dfn[v])) std::swap(u, v);
	int leg = std::__lg(u - v ++);
	return ckmx(st[v][leg], st[u - (1 << leg) + 1][leg]);
}
pii a[N];
int dis(int u,int v){
	return dep[u] + dep[v] - 2 * dep[lca(u, v)]; 
}
struct seg
{
	int mx[2];	
	void erase(){
		mx[0] = mx[1] = 0;
	}
	bool isnull(){
		return !mx[0] && !mx[1];
	}
	seg operator+(const seg &b)const{
		if(!mx[0] && !mx[1]) return b;
		seg c;
		int mxx = 0;
		for(int i = 0; i <= 1; i ++){
			for(int j = 0; j <= 1; j ++){
				if(dis(mx[i],b.mx[j]) > mxx){
					c.mx[0] = mx[i], c.mx[1] = b.mx[j]; 
					mxx = dis(mx[i],b.mx[j]);
				}
			}	
		}
		if(dis(mx[1],mx[0])>mxx){c.mx[0]=mx[0],c.mx[1]=mx[1];mxx=dis(mx[1],mx[0]);}
		if(dis(b.mx[1],b.mx[0])>mxx){c.mx[0]=b.mx[0],c.mx[1]=b.mx[1];mxx=dis(b.mx[1],b.mx[0]);}
		return c;
	}
}tr[N<<2];
void pushup(int x){
	tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
void build(int x,int l,int r){
	if(l == r){tr[x].mx[0] = a[ret[l]].first, tr[x].mx[1] = a[ret[l]].second; return;}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	pushup(x);
}
void modify(int x,int l,int r,int pos,int y,int z){
	if(l == r){
		tr[x].mx[0] = y, tr[x].mx[1] = z;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) modify(x << 1, l, mid, pos, y, z);
	else modify(x << 1 | 1, mid + 1, r, pos, y, z);
	pushup(x);
}
seg query(int x,int l,int r,int ll,int rr){
	// std::cout<< x << " " << l << " " << r << " " << ll << " " << rr << endl;
	if(ll <= l && r <= rr){
		return tr[x];
	}
	int mid = (l + r) >> 1;
	seg ret;
	ret.erase();
	if(ll <= mid) {
		ret = ret + query(x << 1, l, mid, ll, rr);
	}
	if(mid + 1 <= rr){
		ret = ret + query(x << 1 | 1, mid + 1, r, ll, rr);
	}
	// std::cout<<"orz\n";
	return ret;
}
int query_chain(int u,int v){
	seg tmp;
	tmp.erase();
	while(topf[u] != topf[v]){
		if(dep[topf[u]] < dep[topf[v]]) std::swap(u, v);
		tmp = tmp + query(1, 1, n, id[topf[u]], id[u]);
		u = fa[topf[u]];
		// std::cout<<"orz\n";
	}
	// std::cout<<"orz\n";
	if(dep[u] < dep[v]) std::swap(u, v);
	tmp = tmp + query(1, 1, n, id[v], id[u]);	
	return dis(tmp.mx[0],tmp.mx[1]);
}
signed main() {
	// freopen("link.in","r",stdin);
	// freopen("link.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), q = read();
	clock_t be=clock();
	for(int i = 1; i < n; i ++){
		int u = read(), v = read();
		E[u].push_back(v), E[v].push_back(u);
	}
	dfs1(1, 1);
	dfs2(1, 1);
	for(int j = 1; (1 << j) <= n; j ++){
		for(int i = 1; i + (1 << j) - 1 <= n; i ++){
			st[i][j] = ckmx(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	for(int i = 1; i <= n; i ++){
		a[i].first = read(), a[i].second = read();
	}
	build(1, 1, n);
	while(q --){
		int op = read();
		if(op == 1) {
			int x = read(), y = read(), z = read();
			modify(1, 1, n, id[x], y, z);
		} else {
			int x = read(), y = read();
			// std::cout<<"orz\n";
			std::cout << query_chain(x, y) << endl;
		}
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}