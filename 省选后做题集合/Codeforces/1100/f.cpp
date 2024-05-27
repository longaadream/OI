#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
struct lb{
	int bt[21];
	void init(){
		memset(bt,0,sizeof bt);
	}
	void insert(int x){
		for(int i=20;~i;i--){
			if(!((1<<i)&x)) continue;
			if(bt[i]) x^=bt[i]; else return (void)(bt[i]=x);
		}
	}
	int query(int x){
		int ans=x;
		for(int i=20;~i;i--){
			ans=max(ans,ans^bt[i]);
		}
		return ans;
	}
};
const int N=5e5;
int n,m,a[N];
lb tr[N<<2];
void merge(lb &a,lb b){
	for(int i=20;~i;i--){
		a.insert(b.bt[i]);
	}
}
void pushup(int x){
	merge(tr[x],tr[x<<1]);merge(tr[x],tr[x<<1|1]);
}
void build(int x,int l,int r){
	tr[x].init();
	if(l==r){
		tr[x].insert(a[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x);
}
lb query(int x,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr){
		return tr[x];
	}
	int mid=(l+r)>>1;
//	cout<<l<<" "<<r<<" "<<mid<<" "<<ll<<" "<<rr<<endl;
	lb tmp;
	tmp.init();
	if(ll<=mid) merge(tmp,query(x<<1,l,mid,ll,rr));
	if(mid+1<=rr) merge(tmp,query(x<<1|1,mid+1,r,ll,rr));
	return tmp;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	build(1,1,n);
	m=read();
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		cout<<query(1,1,n,l,r).query(0)<<"\n";
	}
	return 0;
}
