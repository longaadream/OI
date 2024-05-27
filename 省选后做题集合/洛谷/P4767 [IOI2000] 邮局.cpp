#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int M=305,N=3e3+5;
int n,m,l,T,a[N];
int dp[N][M],d[N][M],w[N][N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	// int tt=read();
	n=read(),m=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			w[i][j]=w[i][j-1]+a[j]-a[i+j>>1];
		}
	}
	memset(dp,0x7f,sizeof dp);
	dp[0][0]=0;
	for(int j=1;j<=m;j++){
		d[n+1][j]=n;
		for(int i=n;i;i--){
			int minid,minval=0x7fffffff;
			for(int pos=d[i][j-1];pos<=d[i+1][j];pos++){
				if(minval>dp[pos][j-1]+w[pos+1][i]){
					minval=dp[pos][j-1]+w[pos+1][i];
					minid=pos;
				}
			}
			d[i][j]=minid;
			dp[i][j]=minval;
		}
	}
	cout<<dp[n][m]<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
