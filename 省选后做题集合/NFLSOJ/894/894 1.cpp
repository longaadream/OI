#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=8388608,mod=1e9+7;
int n,m,f[N],pw[N],ans;
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		int t=read(),tmp=(1<<m)-1;
		for(int j=1;j<=t;j++){
			int x=read();
			tmp^=(1<<(x-1));
		}
		f[tmp]++;
	}
	pw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=2ll*pw[i-1]%mod;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<(1<<m);j++){
			if((1<<i)&j){
				f[j^(1<<i)]=(f[j]+f[j^(1<<i)])%mod;
			}
		}
	}
	for(int i=0;i<(1<<m);i++){
//		cout<<i<<" "<<f[i]<<__builtin_popcount(i)<<endl;
		ans=(ans+1ll*(pw[f[i]]-1)*((__builtin_popcount(i)&1)?mod-1:1)%mod)%mod;
	}
	cout<<(ans+mod)%mod;
	return 0;
}
