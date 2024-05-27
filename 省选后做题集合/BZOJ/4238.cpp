#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=4e5+5;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int nxt[N],to[N],hd[N],n,m,dep[N],vis[N],cnt=1,odd[N],even[N],otot,etot;
void add(int u,int v){
	nxt[++cnt]=hd[u];
	to[cnt]=v;
	hd[u]=cnt;
}
void dfs(int u){
	for(int i=hd[u];i;i=nxt[i]){
		if(vis[i]) continue;
		vis[i]=vis[i^1]=1;
		if(!dep[to[i]]){
			dep[to[i]]=dep[u]+1;
			dfs(to[i]);
			odd[u]+=odd[to[i]],even[u]+=even[to[i]];
		}else{	
			if((dep[u]-dep[to[i]]+1)&1) otot++,odd[to[i]]--,odd[u]++; else etot++,even[to[i]]--,even[u]++;
		}	
	}
}
signed main(){
//	freopen("voltage2.in","r",stdin);
//	freopen("voltage.out","w",stdout);
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!dep[i]){
			dep[i]=1;
			dfs(i);
		}
	}
	int ans=0;
	for(int i=2;i<=cnt;i+=2){
		int u=to[i],v=to[i^1];
		if(dep[u]<dep[v]) swap(u,v);
		if(dep[u]==dep[v]+1){if(odd[u]==otot&&!even[u]) ans++;}
		else if(((dep[u]-dep[v]+1)&1)&&otot==1) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
