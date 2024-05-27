#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=105,mod=998244353,G=19491001; 
int n,m;
int hd[N],nxt[N],to[N],cnt,rt1,rt2,mx=0,has[N],dep[N],pw[N],siz[N],tot;
pair<int,int> hs[N],sav[N];
void add(int u,int v){
	nxt[++cnt]=hd[u];
	to[cnt]=v;
	hd[u]=cnt;	
}
void getrt(int u,int f){
	siz[u]=1;
	int maxn=0;
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f)continue;
		getrt(v,u);siz[u]+=siz[v];maxn=max(maxn,siz[v]);
	}
	maxn=max(maxn,n-siz[u]);
	if(maxn<mx){
		mx=maxn;rt1=u,rt2=0;
	}else if(maxn==mx){
		rt2=u;
	}
}
void dfs(int u,int f){
	has[u]=1ll*dep[u]*pw[1]%mod,siz[u]=1;
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dep[v]=dep[u]+1;dfs(v,u);
	}
	tot=0;
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		sav[++tot]=make_pair(has[v],siz[v]);
	}
	sort(sav+1,sav+tot+1);
	for(int i=1;i<=tot;i++){
		has[u]=(has[u]+1ll*sav[i].first*pw[siz[u]]%mod)%mod,siz[u]+=sav[i].second;
	}
}
signed main(){
	m=read();
	pw[0]=1;
	for(int i=1;i<=50;i++){
		pw[i]=1ll*pw[i-1]*G%mod;
	}
	for(int tt=1;tt<=m;tt++){
		n=read(),cnt=0,mx=0x7fffffff;
		for(int i=1;i<=n;i++){
			int u=read();
			if(u) add(i,u),add(u,i);
		}
		getrt(1,-1);
		dep[rt1]=1;dfs(rt1,-1);hs[tt].first=has[rt1];
		if(rt2) {dep[rt2]=1;dfs(rt2,-1);hs[tt].second=has[rt2];}
		if(hs[tt].first<hs[tt].second) swap(hs[tt].first,hs[tt].second);
		for(int i=1;i<=n;i++){
			hd[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;i<=i;j++){
			if(hs[i]==hs[j]){
				cout<<j<<'\n';
				break;
			}
		}
	}
	return 0;
}
