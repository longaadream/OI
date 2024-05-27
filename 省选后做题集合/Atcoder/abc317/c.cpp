#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=15;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,m;
vector<pii> E[N];
int ans,vis[N];
void dfs(int rt,int cur,int dis){
	ans=max(ans,dis);
	for(pii v:E[cur]){
		if(vis[v.first]) continue;
		vis[v.first]=1;
		dfs(rt,v.first,dis+v.second);
		vis[v.first]=0;
	}
}
signed main(){
	n=read(),m=read();
	while(m--){
		int u=read(),v=read(),w=read();
		E[u].push_back(make_pair(v,w));
		E[v].push_back(make_pair(u,w));
	}
	ans=0;
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,i,0);
		vis[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}