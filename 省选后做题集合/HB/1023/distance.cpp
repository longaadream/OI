#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5, M = 70, inf = 0x7fffffff;
int n, m, dep[N], dis[N], fa[N], topf[N], son[N], siz[N];
std::vector<pii> E[N];
std::set<pii> s;
struct node{
	int op, x, y;
}q[N];
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
void dfs1(int u, int f){
	// std::cout << u << " " << f << endl;
	dep[u] = dep[f] + 1;
	fa[u] = f;
	siz[u] = 1;
	for(pii to:E[u]){
		int v = to.first, val = to.second;
		if(v == f) continue;
		dis[v] = dis[u] + val;
		dfs1(v, u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]){
			son[u] = v;
		}
	}
}
void dfs2(int u,int tpf){
	topf[u] = tpf;
	if(!son[u]) return ;
	dfs2(son[u], tpf);
	for(pii to:E[u]){
		int v = to.first;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);		
	}
}
int lca(int x,int y){
	while(topf[x] != topf[y]){
		if(dep[topf[x]] < dep[topf[y]]){
			std::swap(x, y);
		}
		y = fa[topf[y]];
	}
	return dep[x] < dep[y] ? x : y; 
}
i64 Dis(int x,int y){
	return dis[x] + dis[y] - 2ll * dis[lca(x, y)];
}
namespace Subtask1{
	void solve(){
		for(int i = 1; i <= m; i ++){
			int op = q[i].op, x = q[i].x, y = q[i].y;
			if(op == 1){
				s.insert(std::make_pair(x, y));
			}else{
				if(!(int)s.size()){
					puts("-1");
					goto end;
				}
				i64 ans = 1e18;
				for(pii val:s){
					ans = std::min(ans, Dis(x, val.first) + Dis(val.second, y));
				}
				std::cout << ans << endl;
			}
			end:{}
		}
	}
}
// namespace Subtask2{
// 	void solve(){
// 		for(int i = 1; i <= m; i ++){
// 			int op = q[i].op, x = q[i].x, y = q[i].y;
// 			if(op == 1){
// 				s.insert(std::make_pair(x, y));
// 			}else{
// 				if(!(int)s.size()){
// 					puts("-1");
// 					goto end;
// 				}
// 				i64 ans = 1e18;
// 				for(pii val:s){
// 					ans = std::min(ans, Dis(x, val.first) + Dis(val.second, y));
// 				}
// 				std::cout << ans << endl;
// 			}
// 			end:{}
// 		}
// 	}
// }
signed main() {
	freopen("distance.in","r",stdin);
	freopen("distance.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	int tt = 1;
   	while(tt --){
   		int flg = 1;
		n = read(), m = read();
		for(int i = 1; i < n; i ++){
			int u = read(), v = read(), w = read();
			E[u].push_back(std::make_pair(v, w));
			E[v].push_back(std::make_pair(u, w));
		}
		dfs1(1, 0);
		dfs2(1, 1);
		for(int i = 1; i <= m; i ++) {q[i] = (node){(int)read(), (int)read(), (int)read()};if(q[i].y != 1 && q[i].op != 1) flg = 0;}
		Subtask1::solve();
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}