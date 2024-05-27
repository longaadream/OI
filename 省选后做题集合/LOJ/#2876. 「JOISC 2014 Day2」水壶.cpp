#include<bits/stdc++.h>
using namespace std;
const int M=2005;
const int N=400005;
struct edge{int u,v,w;};
int A[M][M],dis[M][M],cnt[M*M];
int Fa[N],w[N],sz[N],top[N],par[N],son[N],dep[N];
int H,W,P,Q,n,m,mx;
char S[M][M];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int find(int p){
	return p==Fa[p]?p:Fa[p]=find(Fa[p]);
}
int lca(int u,int v){
	while(top[u]!=top[v]){
	if(dep[top[u]]<dep[top[v]]) v=par[top[v]];
	else u=par[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
int main(){
	// freopen("kettle.in","r",stdin);freopen("kettle.out","w",stdout);
	H=read(),W=read(),P=read(),Q=read();
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
			dis[i][j]=-1;
	for(int i=1;i<=H;++i) scanf("%s",S[i]+1);
	queue<pair<int,int>> q;
	for(int i=1;i<=P;++i){
		int a=read(),b=read();
		A[a][b]=i;
		dis[a][b]=0;
		q.push(make_pair(a,b));
	}
	vector<edge> e;
	while(q.size()){
		static int rx[]={1,0,-1,0},ry[]={0,1,0,-1};
		auto p=q.front();q.pop();
		for(int k=0;k<4;++k){
			int x=p.first+rx[k];
			int y=p.second+ry[k];
			if(x<1||y<1||H<x||W<y||S[x][y]=='#') continue;
			if(~dis[x][y]){
				if(A[x][y]!=A[p.first][p.second]){
					e.push_back((edge){A[x][y],A[p.first][p.second],dis[x][y]+dis[p.first][p.second]});
				}
			}else dis[x][y]=dis[p.first][p.second]+1,A[x][y]=A[p.first][p.second],q.push(make_pair(x,y));
		}
	}
	sort(e.begin(),e.end(),[](edge a,edge b){
		return a.w<b.w;
	});
	for(int i=1;i<=P;++i) sz[i]=1,Fa[i]=i;
	for(edge i:e){
		int u=find(i.u);
		int v=find(i.v);
		if(u==v) continue;
		++P;
		w[P]=i.w;
		sz[P]=sz[u]+sz[v]+1;
		son[P]=sz[u]<sz[v]?v:u;
		Fa[P]=par[u]=Fa[u]=par[v]=Fa[v]=P;
	}
	for(int u=P;u;--u){
		int v=par[u];
		dep[u]=dep[v]+1;
		top[u]=son[v]==u?top[v]:u;
	}
	w[0]=-1;
	while(Q--){
		int u=read(),v=read();
		cout<<w[lca(u,v)]<<'\n';
	}
	return 0;
}