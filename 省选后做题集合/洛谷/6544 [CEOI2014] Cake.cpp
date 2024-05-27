#include<bits/stdc++.h>
using i64=long long;
using namespace std;
const int N=250050;
int tr[N<<2],a[N],n,q,st,rk[N],tot;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
void pushup(int x){
	tr[x]=max(tr[x<<1],tr[x<<1|1]);
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int pos,int aim){
	if(l==r&&l==pos){
		tr[x]=aim;
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) modify(x<<1,l,mid,pos,aim);
	else modify(x<<1|1,mid+1,r,pos,aim);
	pushup(x);
}
int query(int x,int l,int r,int ll,int rr){
	if(l>=ll&&r<=rr){
		return tr[x];
	}
	int mid=(l+r)>>1,res=0;
	if(ll<=mid) res=max(query(x<<1,l,mid,ll,rr),res);
	if(rr>=mid+1) res=max(query(x<<1|1,mid+1,r,ll,rr),res); 
	return res;
}
int lowerbound_l(int x,int l,int r,int ll,int rr,int lim){
	if(l>rr||r<ll) return -1;
	if(tr[x]<lim) return -1;
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	int rres=lowerbound_l(x<<1|1,mid+1,r,ll,rr,lim);	
	if(~rres){
		return rres;
	}else return lowerbound_l(x<<1,l,mid,ll,rr,lim);
}
int lowerbound_r(int x,int l,int r,int ll,int rr,int lim){
	if(r<ll||l>rr) return -1;
	if(tr[x]<lim) return -1;
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	int lres=lowerbound_r(x<<1,l,mid,ll,rr,lim);	
	if(~lres){
		return lres;
	}else return lowerbound_r(x<<1|1,mid+1,r,ll,rr,lim);
}
signed main(){	
	n=read(),st=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		rk[n-a[i]+1]=i;
	}
	build(1,1,n);
	tot=n;
	q=read();
	while(q--){
		char s[3];
		cin>>s;
		if(s[0]=='E'){
			int pos=read(),aim=read(),end=min(10,n);
			for(int i=1;i<=10;i++){
				if(rk[i]==pos) end=i;
			}
			for(int i=end-1;i>=aim;i--){
				rk[i+1]=rk[i];
			}
			rk[aim]=pos;
			for(int i=aim;i>=1;i--){
				modify(1,1,n,rk[i],++tot);		
			}
		}else{
			int b=read();
			if(b==st){
				puts("0");
				continue;
			}
			if(b>st){
				int pos=lowerbound_l(1,1,n,1,st-1,query(1,1,n,st+1,b));
				if(pos==-1) pos=0;
				cout<<b-pos-1<<'\n';
			}else{
				int pos=lowerbound_r(1,1,n,st+1,n,query(1,1,n,b,st-1));
				if(pos==-1) pos=n+1;
				cout<<pos-b-1<<'\n';
			}
		}	
	}
	return 0;
}
