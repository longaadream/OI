#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=720720,mod=998244353;
int f[N],g[N],pw[N];
signed main(){
	int n=read(),tmp=read(),x=read(),y=read(),k=read(),m=read();
	for(int i=1;i<=n;i++){
		g[tmp%N]++;
		tmp=(1ll*tmp*x%m+y)%m;		
	}	
	int ans=0; 
	pw[0]=1;
	for(int i=1;i<=k;i++){
		pw[i]=1ll*pw[i-1]*n%mod;
	}
	for(int i=1;i<=k;i++){
		memcpy(f,g,sizeof f);memset(g,0,sizeof g);
		for(int j=0;j<N;j++){
			g[(j/i)*i]=(g[(j/i)*i]+f[j])%mod;
			g[j]=(g[j]+1ll*(n-1)*f[j]%mod)%mod;
			ans=(ans+1ll*f[j]*j%mod*pw[k-i]%mod)%mod;
		}
	}
	cout<<ans;
	return 0;
}
