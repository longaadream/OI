#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=5e5+5;
int n,k,a[N],dp[N][2],res,cnt[N][2];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
bool check(int x){
	memset(dp,0,sizeof dp);memset(cnt,0,sizeof dp);
	for(int i=1;i<=n;i++){
		dp[i][1]=dp[i-1][0]+a[i]-x,cnt[i][1]=cnt[i-1][0]+1;
		if(dp[i-1][1]>dp[i-1][0]) dp[i][0]=dp[i-1][1],cnt[i][0]=cnt[i-1][1];
		else if(dp[i-1][1]<dp[i-1][0]) dp[i][0]=dp[i-1][0],cnt[i][0]=cnt[i-1][1];
		else dp[i][0]=dp[i-1][1],cnt[i][0]=max(cnt[i-1][1],cnt[i-1][0]);
	}
	if(dp[n][0]>dp[n][1]) {res=dp[n][0];return cnt[n][0]>=k;} res=dp[n][1];return cnt[n][1]>=k;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read(),k=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(!check(0)){
		return cout<<res<<endl,0;
	}
	int l=0,r=1e18,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;else l=mid+1;
	}
	check(ans);
	cout<<res+ans*k<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
