#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e6 + 5, M = 30, inf = 0x7fffffff;
int n, m, key[N], k, deg[N], ik[N], cl[N];
std::vector<int> E[N];
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
signed main() {
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	while(tt --){
		n = read(), m = read();
		for(int i = 1; i <= n; i ++) ik[i] = 0, E[i].clear(), deg[i] = 0;
		for(int i = 1; i <= m; i ++){
			int u = read(), v = read();
			E[u].push_back(v);
			deg[v] ++;
		}
		k = read();
		for(int i = 1; i <= k; i ++) ik[key[i] = read()] = 1;
		std::queue<pii> q;
		for(int i = 1; i <= n; i ++) if(!deg[i]) q.push(std::make_pair(i, 0));
		while(!q.empty()){
			int tp = q.front().first, col = q.front().second;
			cl[tp] = col;
			q.pop();
			if(ik[tp]) col = tp;
			for(int v: E[tp]){
				deg[v] --;
				if(!deg[v]) q.push(std::make_pair(v, col));
			}
		}
		int flag = 1;
		std::set<int> s;
		for(int i = 1; i <= k; i ++) s.insert(cl[key[i]]);
		if((int)s.size() != k) flag = 0;
		if(flag) std::cout << "Yes" << endl; else std::cout << "No" << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}