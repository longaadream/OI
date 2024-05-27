#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=605;
int n,a[N][N],mod;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int det(){
	int w=1,res=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j][i]>a[i][i]) swap(a[i],a[j]),w*=-1;
			while(a[j][i]){
				int r=a[i][i]/a[j][i];
				for(int k=i;k<=n;k++) a[i][k]=(a[i][k]+1ll*(mod-r)*a[j][k]%mod)%mod;
				swap(a[i],a[j]);w*=-1;
			}
		}
		res=1ll*res*a[i][i]%mod;
	}
	return (res*w+mod)%mod;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();mod=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=read();
	cout<<det()<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
