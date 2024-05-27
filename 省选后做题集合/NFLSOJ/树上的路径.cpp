#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii; 
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=5e5+5;
int n,k;
int siz[N],rt,mx=0x7fffffff;
vector<pii> E[N];
void getrt(int u,int f){
	siz[u]=1;
	int mmx=0x7fffffff;
	for(pii i:E[u]){
		if(i.fi==f) continue;
		getrt(i.fi,u);
		siz[u]+=siz[i.fi];
		mmx=max(mmx,siz[i.fi]);
	}
	mmx=max(mmx,n-siz[u]);
	if(mmx<mx){
		rt=u,mmx=mx;
	}
}
void dfs(int u,int f){
	for(pii i:E[u]){
		if(i.fi==f) continue;
		dfs(i.fi,u);
	}
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read(),w=read();
		E[u].pb(mp(v,w));E[v].pb(mp(u,w));
	}
	getrt(1,0);
	dfs(rt,0);
	return 0;
}