#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e5+5;
int n, q, fa[N][20], dep[N], len[N], mx[N], son[N], top[N];
std::vector<int> E[N], up[N], down[N];
bool Med;
namespace gen{
#define ui unsigned int
ui s;
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}
}using namespace gen;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
void dfs1(int x,int f){
	dep[x] = dep[f] + 1;
	mx[x] = dep[x];
	for(int i = 0; i <= 19; i ++){
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for(int v:E[x]){
		if(v == f) continue;
		fa[v][0] = x,dfs1(v, x);
		if(mx[v] > mx[son[x]]){
			mx[x] = mx[v];
			son[x] = v;
		}
	}  
}
void dfs2(int x,int topf){
	top[x] = topf, len[x] = mx[x] - dep[top[x]] + 1;
	if(!son[x]) return;
	dfs2(son[x],son[x]);
	for(int v:E[x]){
		if(fa[x][0] == v || v == son[x]) continue;
		dfs2(v, v);
	}
}
int query(int p, int k) {
	if(!k) return p;
	int lg = log(k)/log(2);
	p = fa[p][lg], k -= (1 << lg), p = top[p], k -= mx[p] - dep[top[p]];
	if(!k) return p;
	return k < 0 ? down[p][-k - 1] : up[p][k - 1];
}
signed main() {
	// freopen("link.in","r",stdin);
	// freopen("link.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), q = read(), s = read();
	clock_t be=clock();
	int rt = 0;
	for(int i = 1; i <= n; i ++){
		int t = read();
		if(!t) {rt = i; continue;}
		E[t].push_back(i), E[i].push_back(t);
	}
	dfs1(rt,0);dfs2(rt,rt);
	for(int i = 1; i <= n; i ++){
		if(top[i] != i) continue;
		for(int j = 1, cur = i; j <= len[i]; j ++){
			cur = fa[cur][0], up[i].push_back(cur);
		}
		for(int j = 1, cur = i; j <= len[i]; j ++){
			cur = son[cur], down[i].push_back(cur);
		}
	}
	int ans = 0;
	for(int i = 1; i <= q; i ++) {
		int p = get(s) % n + 1, k = get(s) % dep[s] + 1;
		ans ^= i * query(p, k);
	}
	std::cout << ans << endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}