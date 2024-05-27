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
const int mod=1e9+7,N=1e6+5;
int fac[N],inv[N];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1){res=1ll*res*a%mod;}
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int C(int n,int m){
	if(m<0||n<m) return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
char s[N];
int pre[N],suf[N];
signed main(){
	fac[0]=1;
	for(int i=1;i<=1e6;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	int tmp=1e6;
	inv[tmp]=qpow(fac[tmp],1e9+5);
	for(int i=1e6;i;i--){
		inv[i-1]=1ll*inv[i]*i%mod;
	}
	cin>>(s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+(s[i]=='(');
	}
	for(int i=n;i;i--){
		suf[i]=suf[i+1]+(s[i]==')');
	}
	i64 ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') ans=(ans+C(pre[i]+suf[i]-1,pre[i]))%mod;
	}
	cout<<ans;
	return 0;
}
