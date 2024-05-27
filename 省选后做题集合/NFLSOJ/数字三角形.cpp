#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=3e5+5;
const int M=105;
bitset<N> dp[M];
int n,a[M][M],f[M][M],k;
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++) f[n][i]=a[n][i],dp[i][a[n][i]]=1;
	for(int i=n-1;i;i--){
		for(int j=1;j<=i;j++){
			dp[j]=dp[j]<<a[i][j]|dp[j+1]<<a[i][j],f[i][j]=min(f[i+1][j+1],f[i+1][j])+a[i][j];
		}
	}
	int ans=0x7fffffff;
	// for(int i=0;i<=3e5;i++){
	// 	if(dp[1][i]) ans=min(ans,abs(k-i));
	// }
	if(dp[1]._Find_next(k)!=dp[1].size()||dp[1][dp[1].size()]) ans=min(ans,(i64)dp[1]._Find_next(k)-k);
	for(int i=k;i;i--){
		if(dp[1][i]) {ans=min(ans,k-i);break;}
	}
	ans=min(ans,abs(f[1][1]-k));
	cout<<ans;
	return 0;
}
/*
5 62
23
12 56
45 12 12
32 1 23 10
1 2 3 4 5
*/