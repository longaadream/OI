#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=5e5+5,inf=1e18;
i64 n,m,dis[N],vis[N];
vector<pii> E[N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void add(int u,int v,int w){
	E[u].push_back(make_pair(v,w));
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read(),m=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++)add(i,i+n,0);
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v+n,u+n,w);
	}
	priority_queue<pii> q;
	q.push(make_pair(0,1));
	for(int i=2;i<=n+n;i++)dis[i]=inf;
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;vis[x]=1;
		for(pii to:E[x]){
			int t=to.first,w=to.second;
			if(dis[t]>dis[x]+w){
				dis[t]=dis[x]+w;
				q.push(make_pair(-dis[t],t));
			}
		}
	}
	for(int i=n+2;i<=n+n;i++) cout<<((dis[i]==inf)?-1:dis[i])<<" ";
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
