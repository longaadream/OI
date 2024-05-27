#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=5e3 + 5, inf = 1e18;
int n, m, a[N], dp[N][N], val, num[N], siz[N], g[N];
std::vector<pii> E[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
void dfs(int u, int f){
	dp[u][0] = 0, dp[u][1] = 0, siz[u] = 1, num[u] = a[u];
	for(pii ed:E[u]){
		int v = ed.first, w = ed.second;
		if(v == f) continue;
		dfs(v, u);
		siz[u] += siz[v], num[u] += num[v];
		for(int i = 0; i <= siz[u]; i ++){g[i] = dp[u][i], dp[u][i] = inf;}
		for(int i = 0; i <= siz[u]; i ++){
			for(int j = 0; j <= siz[v]; j ++){
				if(i + j > siz[u]) continue; 
				dp[u][i + j] = std::min(dp[u][i + j], g[i] + dp[v][j] + w * abs(num[v] - siz[v] * val - j));
			}
		}
	}
}
signed main() {
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt = read();
	clock_t be=clock();
	while(tt --){
		n = read(), m = 0;
		for(int i = 1; i <= n; i ++){
			a[i] = read(), m += a[i];
			E[i].clear();
		}
		for(int i = 1; i < n; i ++){
			int u = read(), v = read(), w = read();
			E[u].push_back(std::make_pair(v, w));
			E[v].push_back(std::make_pair(u, w));
		}
		val = m / n, m %= n;
		dfs(1, 1);
		std::cout << dp[1][m] << endl;
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}