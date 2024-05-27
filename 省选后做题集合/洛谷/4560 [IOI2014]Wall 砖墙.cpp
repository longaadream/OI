#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=2e6+5,inf=1e9;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,mx[N<<2],mn[N<<2],k; 
void pushdown(int x){
	if(mx[x]){
	mx[x<<1]=max(mx[x],mx[x<<1]);
	mx[x<<1|1]=max(mx[x],mx[x<<1|1]);
	mn[x<<1]=max(mx[x],mn[x<<1]);
	mn[x<<1|1]=max(mx[x],mn[x<<1|1]);
	mx[x]=0;
	}
	if(mn[x]!=inf){
	mx[x<<1]=min(mn[x],mx[x<<1]);
	mn[x<<1]=min(mn[x],mn[x<<1]);
	mx[x<<1|1]=min(mn[x],mx[x<<1|1]);
	mn[x<<1|1]=min(mn[x],mn[x<<1|1]);
	mn[x]=inf;
	}
}
void modify(int x,int l,int r,int ll,int rr,int h,int op){
	if(l>=ll&&r<=rr){
		if(op==1){
			mn[x]=max(mn[x],h);
			mx[x]=max(mx[x],h);
		}else{
			mn[x]=min(mn[x],h);
			mx[x]=min(mx[x],h);
		}
		return;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	if(ll<=mid){
		modify(x<<1,l,mid,ll,rr,h,op);
	}
	if(rr>=mid+1){
		modify(x<<1|1,mid+1,r,ll,rr,h,op);
	}
}
void out(int x,int l,int r){
	if(l==r){
		cout<<mx[x]<<'\n';
		return;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	out(x<<1,l,mid);
	out(x<<1|1,mid+1,r);
}
signed main(){
	freopen("wall.in","r",stdin);
	freopen("wall.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=(n<<2);i++){
		mn[i]=inf;
	}
	for(int i=1,op,l,r,h;i<=k;i++){
		op=read(),l=read()+1,r=read()+1,h=read();
			modify(1,1,n,l,r,h,op);
	}
	out(1,1,n);
	return 0;
}
