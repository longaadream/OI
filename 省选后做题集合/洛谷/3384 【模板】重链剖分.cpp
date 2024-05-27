#include<bits/stdc++.h>
#define i64 long long
#define ix(l,r) ((l+r)|(l!=r))
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,m,r,p;
const int N=200006;
int hd[N<<1],nxt[N<<1],to[N<<1],cnt;
i64 a[N],val[N<<1],b[N],laz[N<<1];
void add(int u,int v){
	nxt[++cnt]=hd[u];
	to[cnt]=v;
	hd[u]=cnt;
}
int tp[N],siz[N],dep[N],fa[N],son[N],id[N],dfncnt;
void dfs1(int u,int f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	siz[u]=1;
	int mx=0;
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>mx){
			son[u]=v,mx=siz[v];
		}		
	}
}
void dfs2(int u,int tpf){
	id[u]=dfncnt++;
	b[dfncnt]=a[u];
	tp[u]=tpf;
	if(!son[u]) return ;
	dfs2(son[u],tpf);
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}

void pushup(int l,int r){
	int x=ix(l,r);
	int mid=(l+r)>>1;
	int lx=ix(l,mid),rx=ix(mid+1,r);
	val[x]=(val[lx]+val[rx])%p;
}
void build(int l,int r){
	int x=ix(l,r);
	if(l==r){
		val[x]=b[l];
		if(val[x]>p) val[x]%=p;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid);
	build(mid+1,r);
	pushup(l,r);
}
void pushdown(int l,int r){
	int x=ix(l,r);
	int mid=(l+r)>>1;
	int lx=ix(l,mid),rx=ix(mid+1,r);
	laz[lx]+=laz[x],laz[rx]+=laz[x];
	val[lx]+=laz[x]*(mid-l+1)%p,val[rx]+=laz[x]*(r-mid)%p;
	val[lx]%=p,val[rx]%=p;
	laz[x]=0;
}	
i64 query(int ll,int rr,int l=1,int r=n){
	i64 res=0;
	int x=ix(l,r);
	if(l>=ll&&rr<=r){res+=val[x];res%=p;return res;}
	int mid=(l+r)>>1;
	if(laz[x]) pushdown(l,r);
	if(ll<=mid) res+=query(ll,rr,l,mid),res%=p;
	if(rr>=mid+1) res+=query(ll,rr,mid+1,r),res%=p;
	return res;
}
void update(int ll,int rr,int k,int l=1,int r=n){
	int x=ix(l,r),mid=(l+r)>>1;
//	cerr<<ll<<" "<<rr<<" "<<l<<" "<<r<<endl;	
	if(ll<=l&&r<=rr){
		laz[x]+=k;
		a[x]+=k*(r-l+1);
		a[x]%=p;
		return ;
	}
	if(laz[x]) pushdown(l,r);
	if(ll<=mid) update(ll,rr,k,l,mid);
	if(mid+1<=rr) update(ll,rr,k,mid+1,r);
	return pushup(l,r);
}
i64 qrange(int x,int y){
	i64 ans=0;
//	cerr<<"orz"<<endl;
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		ans+=query(id[tp[x]],id[x]);
		ans%=p;
		x=fa[tp[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	ans+=query(id[x],id[y]);
	return ans%p;
}
void qupd(int x,int y,int k){
	k%=p;
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		update(id[tp[x]],id[x],k);
		x=fa[tp[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return update(id[x],id[y],k);
}
i64 sumson(int x){
	return query(id[x],id[x]+siz[x]-1);
}
void updson(int x,int k){
	return update(id[x],id[x]+siz[x]-1,k);
}

signed main(){
	n=read(),m=read(),r=read(),p=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(r,0);
	dfs2(r,r);
	build(1,n);
	while(m--){
		int op=read();
		if(op==1){
			int x=read(),y=read(),z=read();
			qupd(x,y,z);
		}else if(op==2){
			int x=read(),y=read();
			cout<<qrange(x,y)<<"\n";
		}else if(op==3){
			int x=read(),z=read();
			updson(x,z);
		}else if(op==4){
			int x=read();
			cout<<sumson(x)<<"\n";
		}
	}
	return 0;
} 
