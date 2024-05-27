#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=405,mod=1e9+7;
int n,a[N][N],b[N][N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int inv(int a,int b=mod-2){
	int res=1;
	while(b){
		if(b&1){
			res=1ll*res*a%mod;
		}
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
void gauss(){
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]>a[i][i]) swap(a[i],a[j]),swap(b[i],b[j]);
			mx=max(mx,a[i][i]);
			while(a[j][i]){
				int r=a[i][i]/a[j][i];
				for(int k=i;k<=n;k++) a[i][k]=(a[i][k]+1ll*(mod-r)*a[j][k]%mod)%mod,b[i][k]=(b[i][k]+1ll*(mod-r)*b[j][k]%mod)%mod;
				swap(a[i],a[j]),swap(b[i],b[j]);
			}
		}
		if(!mx) {puts("No Solution");exit(0);}
	}
	for(int i=1;i<=n;i++){
		int iv=inv(a[i][i]);
		for(int j=1;j<=n;j++){
			b[i][j]=b[i][j]*iv%mod;
		}
	}
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=read();
	for(int i=1;i<=n;i++) b[i][i]=1;
	gauss();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
