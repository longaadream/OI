#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=5e5+5;
int n,a[N],b[N],tr[N<<1];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
#define lowbit(x) x&(-x)
void add(int x,int k){
	while(x<=n){
		tr[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x){
	int res=0;
	while(x){
		res+=tr[x];
		x-=lowbit(x);
	}
	return res;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();
	clock_t be=clock();
	int mx=0;
	for(int i=1;i<=n;++i){
		a[i]=read()+a[i-1];
		if(a[i]<0) return puts("-1"),0;
		if(n!=i)mx=max(mx,a[i]);
		b[i]=a[i];
	}
	if(mx>a[n]) return puts("-1"),0;
	int ans=0;
	sort(b,b+n+1);
	int tot=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){a[i]=lower_bound(b+1,b+tot+1,a[i])-b;}
	for(int i=n;i;i--){
		ans+=query(a[i]-1);
		add(a[i],1);
	}		
	cout<<ans<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
