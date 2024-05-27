#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
const int N=1e4+5,mod=1e9+7;
bool Mbe;
int n,m,a[N],f[N][N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	clock_t be=clock();
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt=read();
	while(tt--){
		n=read(),m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		memset(f,0x7f,sizeof f);
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-	1&&i-j+1>=1;j++){
				f[i][j]=f[i-j+1][m-j]+a[i];
			}
			for(int j=1;j<=m-1;j++){
				f[i][j]=min(f[i][j],f[i][j-1]);
			}
		}
		int ans=0x7fffffff;
		for(int i=1;i<=m-1;i++){
			ans=min(ans,f[n][i]);
		}
		cout<<ans<<endl;
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}