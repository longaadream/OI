#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=1e5+5,mod=1e9+7;
int a[N],n,buk[N],f[N][2],fac[N],inv[N];
map<int,int> pm;
bool Med;
inline int qpow(int a,int b){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
bool iq(int x){
	int rt=(int)sqrt(x);
	if((rt*rt)==x) return 1;return 0;
}
int C(int n,int m){
	if(n==m) return 1;
	if(n<m||m<0||n<0) return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
	// freopen("permutation.in","r",stdin);
	// freopen("permutation.out","w",stdout);
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();
	clock_t be=clock();
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--) inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(iq(a[i]*a[j])) a[j]=a[i];
		}
		pm[a[i]]++;
	}
	sort(a+1,a+n+1);
	int m=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=m;i++){
		buk[i]=pm[a[i]];
	}
	f[buk[1]][1]=fac[buk[1]];	
	for(int i=2;i<=m;i++){
		int len=buk[i];
		for(int j=1;j<=n;j++) f[j][i&1]=0;
		for(int j=1;j<=n;j++){
			if(!f[j][(i&1)^1]) continue;
			for(int k=0;k<=min(j-1,len);k++){
				int co=1ll*fac[len]*inv[len-k]%mod*C(j-1,k)%mod;
				int cur=(j-k)*2;
				for(int l=0;l<=min(cur,len-k);l++){
					int co2=1ll*co*C(cur,l)%mod*fac[len-k]%mod*inv[len-k-l]%mod*C(len-k-l+j-k,j-k)%mod*fac[len-k-l]%mod;
					f[j-k+len-k-l][i&1]=(f[j-k+len-k-l][i&1]+1ll*f[j][(i&1)^1]*co2%mod)%mod;
				}
			}
		}
	}
	cout<<f[1][m&1]<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}