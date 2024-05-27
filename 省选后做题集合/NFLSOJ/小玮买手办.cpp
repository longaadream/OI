#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e6+6;
int n,a[N],p;
int ans=0;
int tmp[N];
void merge(int l,int r){
	if(l>=r) return;
	int mid=(l+r)>>1;
	merge(l,mid);merge(mid+1,r);
	int ll=l,rr=mid+1,pt=l;
	while(ll<=mid&&rr<=r){
		if(a[ll]>=a[rr]){
			ans+=mid-ll+1;
			tmp[pt++]=a[rr++];
		}else{
			tmp[pt++]=a[ll++];
		}
	}
	while(ll<=mid) tmp[pt++]=a[ll++];
	while(rr<=r) tmp[pt++]=a[rr++];
	for(int i=l;i<=r;i++){
		a[i]=tmp[i];
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read()+a[i-1];
	}
	p=read();
	for(int i=1;i<=n;i++){
		a[i]-=i*p;
	}
	reverse(a,a+n+1);
	merge(0,n);
	cout<<ans;
	return 0;
}