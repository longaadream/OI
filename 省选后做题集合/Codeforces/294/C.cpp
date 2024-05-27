#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e5+5,mod=1e9+7;
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
int n,m,pos[N],bl[N];
signed main(){
	fac[0]=1;
	for(int i=1;i<=1000;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	inv[1000]=qpow(fac[1000],1e9+5);
	for(int i=1000;i;i--){
		inv[i-1]=1ll*inv[i]*i%mod;
	}
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		pos[i]=read();
	}
	sort(pos+1,pos+m+1);
	int lst=0,tot=0;
	for(int i=1;i<=m;i++){
		bl[++tot]=pos[i]-lst-1;
		lst=pos[i];
	}
	bl[++tot]=n-pos[m];
	int ans=1;
	n-=m;
	for(int i=1;i<=tot;i++){
		ans=1ll*ans*C(n,bl[i])%mod;
		n-=bl[i];
		if(bl[i]&&i!=tot&&i!=1){
			ans=1ll*ans*qpow(2,bl[i]-1)%mod;
		}
	}
	cout<<ans;
	return 0;
}
