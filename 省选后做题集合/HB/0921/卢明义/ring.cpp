#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e2+5,inf=1e9;
int dis[N][N],n,m;
pii e[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10u+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt = read();
	clock_t be=clock();
	for(int _ = 1; _ <= tt; _++) {
		int ans = 0;
		n = read(), m = read();
		for(int i = 0; i < n; i ++) dis[i][i] = 0;
		for(int i = 0; i < m; i++) {
			int u = read(), v = read();
			e[i] = std::make_pair(u, v);
			dis[u][v] = dis[v][u] = 1;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					dis[i][j] = std::min(dis[i][j] , dis[i][k] + dis[k][j]);
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				int res = 0;
				for(int k = 0; k < m ; k++){
					int u = e[k].first, v = e[k].second;
					int Dis=std::min(dis[i][u] + dis[v][j], dis[i][v] + dis[u][j]) + 1;
					if(Dis==dis[i][j]) res++;
				}
				ans=std::max(ans, res);
			}
		}
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				dis[i][j] = inf;
			}
		}
		std::cout<<"Case #"<<_<<": "<<ans<<endl;
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
/*
4
2
1
0 1
3
3
0 1
1 2
2 0
6
6
0 1
0 5
1 3
5 4
3 2
4 2
6
7
0 1
0 5
1 3
1 4
5 4
3 2
4 2

*/