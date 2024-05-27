#include<bits/stdc++.h>
#define int long long
using namespace std;
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=2e5+5,mod=998244353;
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int n,m,a[N];
signed main(){
	int tt=read();
	while(tt--){
		n=read(),m=0;
		int tmp=0;
		for(int i=1;i<=n;i++){
			a[i]=read(),tmp+=(a[i]==0);
		}
		for(int i=1;i<=tmp;i++){
			m+=(a[i]==1);
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			ans=(i64)(ans+qpow(1ll*i*i%mod,mod-2))%mod;
		}
		ans=1ll*ans*qpow(2,mod-2)%mod;
		ans=1ll*ans*n%mod*(n-1)%mod;
		cout<<ans<<"\n";
	}
}
