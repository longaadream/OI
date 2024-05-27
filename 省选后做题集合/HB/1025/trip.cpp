#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 10, M = 2e6 + 5, mod = 998244353;
const int inf = 1e9;
int n, m, p, t, tot;
 // hd[N << 2], nxt[N << 2], to[N << 2], vl[N << 2], edcnt, dis[N << 2], vis[N << 2];
// struct node{
// 	int s, t, a, b, c, d;
// }a[N];
// std::vector<int> id[N],getpos[N];
// void addedge(int u, int v, int w){
// 	nxt[++ edcnt] = hd[u];
// 	to[edcnt] = v;
// 	vl[edcnt] = w;
// 	hd[u] = edcnt;
// }
// #define nx(v, val, u) for(int i = hd[u], v = to[i], val = vl[i]; i; i = nxt[i], v = to[i], val = vl[i])
struct node{
	int pos, tim, cost, id;
}a[N << 1];
int f[N << 1], g[N << 1];
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
signed main() {
	// freopen("P6329_1.in","r",stdin);
	// freopen("P6329.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
	// n = read(), m = read(), p = read(), t = read();
	// a[1] = (node){1, 1, 0, 0, 0, 0};
	// id[1].push_back(1);
	// getpos[1].push_back(0);
	// m ++;
	// for(int i = 2; i <= m; i ++){
	// 	a[i] = (node){(int)read(), (int)read(), (int)read(), (int)read(), (int)read(), (int)read()};
	// 	id[a[i].s].push_back(i);
	// 	getpos[a[i].s].push_back(a[i].a);
	// }
	// a[++ m] = (node){p, p, t, t, t, t};
	// id[p].push_back(m);
	// getpos[p].push_back(t);
	// for(int i = 1; i <= n; i ++){
	// 	if(!(int)id[i].size()) continue;
	// 	std::sort(id[i].begin(), id[i].end(), [](int x, int y){
	// 		return a[x].a < a[y].a;
	// 	});
	// 	std::sort(getpos[i].begin(), getpos[i].end());
	// 	if(id[i].size() == 1) continue;
	// 	for(int j = 0; j < (int)id[i].size() - 1; j ++){
	// 		addedge(id[i][j], id[i][j + 1], a[id[i][j + 1]].b - a[id[i][j]].b);
	// 		// std::cout << "st: " << id[i][j] << " ed: " << id[i][j + 1] << " val :" << a[id[i][j + 1]].b - a[id[i][j]].b << endl; 
	// 	}
	// }
	// // for(int i = 1; i <= n; i ++){
	// // 	std::cout << i << ": " << id[i].size() << endl;
	// // 	for(int j:id[i]) std::cout << j << " ";
	// // 	putchar(10);
	// // }
	// // for(int i = 1; i <= edcnt; i ++) std::cout << vl[i] << endl;
	// for(int i = 1; i <= m; i ++){
	// 	if(!(int)id[a[i].t].size()) continue;
	// 	if(a[i].d > getpos[a[i].t][getpos[a[i].t].size() - 1]) continue;
	// 	int pos = lower_bound(getpos[a[i].t].begin(), getpos[a[i].t].end(), a[i].d) - getpos[a[i].t].begin() + 1 - 1;
	// 	addedge(i, id[a[i].t][pos], a[id[a[i].t][pos]].b - a[i].c);
	// 	// std::cout << "st: " << i << " ed: " << id[a[i].t][pos] << " val :" << a[id[a[i].t][pos]].b - a[i].c << endl; 
	// }
	// memset(dis, 0x3f, sizeof dis);
	// std::priority_queue<pii, std::vector<pii>, std::less<pii>> pq;
	// pq.push(std::make_pair(dis[1] = 0, 1));
	// while(pq.size()){
	// 	int tp = pq.top().second, ds = pq.top().first;
	// 	pq.pop();
	// 	if(vis[tp]) continue;
	// 	vis[tp] = 1;
	// 	// std::cout << "tp : "<< tp << " " << dis[tp] << endl;
	// 	nx(v, val, tp){
	// 		// std::cout << "v: " << v << " val: " << val << " dis[v]: " << dis[v] << endl;
	// 		if(dis[v] > val + ds){
	// 			dis[v] = val + ds;
	// 			pq.push(std::make_pair(dis[v], v));
	// 		}
	// 	}
	// }
	// // for(int i = 1; i <= m; i ++) std::cout << dis[i] << endl;
	// if(dis[m] == 0x3f3f3f3f) std::cout << "-1" << endl; else std::cout << dis[m] << endl;
	n = read(), m = read(), p = read(), t = read();
	for(int i = 1; i <= m; i ++){
		int x = read(), y = read(), tt = read(), b = read(), c = read(), d = read();
		a[++tot] = (node){x, tt, -1, i};
		a[++tot] = (node){y, d, (c - b), i};
	}
	a[++tot] = (node){n + 1, t, -inf, m + 1};
	std::sort(a + 1, a + tot + 1, [](node x, node y){
		return x.tim^y.tim ? x.tim < y.tim : x.cost < y.cost;
	});
	f[1] = 0;
	for(int i = 2; i <= n; i ++) f[i] = -inf;
	for(int i = 1; i <= tot; i ++){
		if(a[i].pos == n + 1) break;
		if(a[i].cost == -1){
			g[a[i].id] = f[a[i].pos];
		}else{
			f[a[i].pos] = std::max(f[a[i].pos], g[a[i].id] + a[i].cost);
		}
	}
	std::cout << (f[p] < 0 ? -1 : t - f[p]) << endl;
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}