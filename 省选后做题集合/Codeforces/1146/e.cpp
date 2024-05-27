#include<bits/stdc++.h>
using namespace std;
using i64=long long;
#define int long long
const int inf=1e5;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline char reac(){
	char c=getchar();
	while(c!='<'&&c!='>') c=getchar();
	return c;
}
const int N=1e5+5;
int a[N],cov[N<<5],rev[N<<5],cnt=1,n,q;
map<int,int> msk;
void build(int rt,int l,int r){
	if(l==r){
		cov[rt]=0,rev[rt]=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
}
void pushdown(int rt){
	if(cov[rt]){
		rev[rt<<1]=0,cov[rt<<1]=cov[rt];rev[rt<<1|1]=0,cov[rt<<1|1]=cov[rt<<1|1];
		cov[rt]=0;	
	}
	if(rev[rt]){
		rev[rt<<1]^=1,rev[rt<<1|1]^=1;
		rev[rt]=0;
	}
}
void modify_cov(int rt,int l,int r,int ll,int rr,int det){
	if(ll<=l&&r<=rr){
		cov[rt]=det;
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(mid>=ll) modify_cov(rt<<1,l,mid,ll,rr,det);
	if(mid+1<=rr) modify_cov(rt<<1|1,mid+1,r,ll,rr,det);
}
void modify_rev(int rt,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr){
		rev[rt]^=1;
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(mid>=ll) modify_rev(rt<<1,l,mid,ll,rr);
	if(mid+1<=rr) modify_rev(rt<<1|1,mid+1,r,ll,rr);
}
void get_ans(int rt,int l,int r){
	if(l==r){
		msk[l]=l;
		if(cov[rt]){
			msk[l]=(l-inf)*cov[l]+inf;
		}
		if(rev[rt]){
			msk[l]=-(l-inf)+inf;
		}
		msk[l]-=inf;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt);
	get_ans(rt<<1,l,mid);get_ans(rt<<1|1,mid+1,r);
}
signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read()+inf;
	}
	build(1,0,2*inf);
	while(q--){
		char c=reac();
		int x=read();
		if(c=='>'){
			if(x>0){
				modify_cov(1,1,n,x+1+inf,2*inf,-1);
			}else{
				modify_rev(1,1,n,x+1+inf,-x-1+inf);
				modify_cov(1,1,n,-x+inf,2*inf,-1);
			}
		}else{
			if(x<0){
				modify_cov(1,1,n,0,x-1+inf,1);
			}else{
				modify_rev(1,1,n,x-1+inf,-x+1+inf);
				modify_cov(1,1,n,0,-x+inf,1);
			}
		}
	}
	get_ans(1,1,2*inf);
	for(int i=1;i<=n;i++){
		cout<<msk[a[i]]<<" ";
	}
	return 0;	
}