#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=65,mod=1e7+7;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
i64 qpow(i64 a,i64 b){int res=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)res=1ll*res*a%mod;return res;}
i64 n,x,y,z,bit[N],len,dp[N][2][N];
i64 dfs(int n,int top,int cur){
	if(cur<0) return 0;
	if(n>len) return 1;
	if(~dp[n][top][cur]) return dp[n][top][cur];
	
}
signed main(){
	memset(dp,-1,sizeof dp);
	n=read(),x=read(),y=read(),z=read();
	while(n){
		bit[++len]=n&1;
		n>>=1;
	}
	i64 ans=0;
	for(int i=len;i;i--){
		ans+=qpow(i,(dfs(1,0,i)+dfs(1,1,i))%mod);
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}