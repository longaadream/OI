#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline i64 read(){
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e5+10;
int n,m,val[N<<6],ls[N<<6],rs[N<<6],dep[N],node,id[N],topf[N],son[N],siz[N],dfncnt,fa[N],mx[N<<6],ans[N];
vector<int> E[N];
void dfs1(int u,int f){
	dep[u]=dep[f]+1;
	siz[u]=1;
	fa[u]=f;
	int mx=0; 
	for(int v:E[u]){
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>mx){
			son[u]=v,mx=siz[v];
		}
	}
}
void dfs2(int u,int tpf){
//	id[u]=++dfncnt;
	topf[u]=tpf;
	if(!son[u]) return; 
	dfs2(son[u],tpf);
	for(int v:E[u]){
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int u,int v){
	while(topf[u]!=topf[v]){
		if(dep[topf[u]]>dep[topf[v]]) u=fa[topf[u]]; else v=fa[topf[v]];
	}
	return dep[u]>dep[v]? v:u;
}
void pushup(int x){
	val[x]=max(val[rs[x]],val[ls[x]]);
	mx[x]=(val[x]==val[ls[x]]?mx[ls[x]]:mx[rs[x]]);
	if(val[rs[x]]==val[ls[x]]) mx[x]=min(mx[ls[x]],mx[rs[x]]);
}
void modify(int &x,int l,int r,int p,int det){
	if(!x) x=++node;
	if(l==r){
		val[x]+=det,mx[x]=p;
		if(!val[x]) mx[x]=0;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) modify(ls[x],l,mid,p,det);else modify(rs[x],mid+1,r,p,det);
	return pushup(x);
}
int merge(int l,int r,int x,int y){
	if(!x||!y) return x|y;
	if(l==r) return val[x]+=val[y],mx[x]=l,x;
	int mid=(l+r)>>1;
	ls[x]=merge(l,mid,ls[x],ls[y]),rs[x]=merge(mid+1,r,rs[x],rs[y]);
	return pushup(x),x;
}
void calc(int u,int f){
	for(int v:E[u]){
		if(v==f) continue;
		calc(v,u);
		id[u]=merge(1,N,id[u],id[v]);
	}
	ans[u]=val[id[u]]? mx[id[u]]:0;
}
signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		E[u].push_back(v),E[v].push_back(u);
	}	
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1,u,v,w;i<=m;i++){	
		u=read(),v=read(),w=read();
		int d=lca(u,v);
		modify(id[u],1,N,w,1);
		modify(id[v],1,N,w,1);
		modify(id[d],1,N,w,-1);
		if(fa[d]) modify(id[fa[d]],1,N,w,-1);
	}
	calc(1,0);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
