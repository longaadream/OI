#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();};
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=3005,mod=998244353;
i64 f[N][N];
i64 qpow(i64 a,i64 b){
	i64 res=1;
	while(b){
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	int a=read(),b=read(),c=read(),d=read();
	f[a][b]=1;
	for(int i=a;i<=c;i++){
		for(int j=b;j<=d;j++){
			f[i][j]=(f[i][j]+1ll*f[i-1][j]*j%mod)%mod;
			f[i][j]=(f[i][j]+1ll*f[i][j-1]*i%mod)%mod;
			f[i][j]=(f[i][j]-1ll*f[i-1][j-1]*(i-1)%mod*(j-1)%mod)%mod;
		}
	}
	cout<<(f[c][d]+mod)%mod<<endl;
	return 0;
}