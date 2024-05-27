#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
const int N=3e6+5,mod=998244353;
bool Mbe;
int a,b,c,d,f[N],fac[N],inv[N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int qpow(int a,int b){int res=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)res=1ll*res*a%mod;return res;}
int C(int n,int m){if(n<0||m<0||n<m) return 0;return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
signed main(){
	clock_t be=clock();
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	a=read(),b=read(),c=read(),d=read();
	int tot=a+b+c;
	fac[0]=1;
	for(int i=1;i<=tot;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	inv[tot]=qpow(fac[tot],mod-2);
	for(int i=tot;i;i--){
		inv[i-1]=1ll*inv[i]*i%mod;
	}
	i64 ans=0;
	for(int i=d;(a>=i)&&(b>=i);i++){
		ans=(ans+(((i-d)&1)?-1:1)*C(i,d)%mod*C(tot-i,i)%mod*C(tot-2*i,a-i)%mod*C(tot-i-a,b-i)%mod+mod)%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}