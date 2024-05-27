#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=5e5+5;
int n,k,a[N],dp[N],res,cnt[N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
bool check(int x){
	memset(dp,0,sizeof dp);memset(cnt,0,sizeof cnt);
	for(int i=2;i<=n;i++){
		if(dp[i-2]+a[i]-a[i-1]-x<dp[i-1]){
			dp[i]=dp[i-2]+a[i]-a[i-1]-x,cnt[i]=cnt[i-2]+1;
		}else if(dp[i-2]+a[i]-a[i-1]-x>dp[i-1]){
			dp[i]=dp[i-1];cnt[i]=cnt[i-1];
		}else dp[i]=dp[i-1],cnt[i]=max(cnt[i-1],cnt[i-2]+1);
	}
	res=dp[n];
	return cnt[n]>=k;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	k=read(),n=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int l=0,r=a[n]-a[1],ans=0,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,r=mid-1;
		}else l=mid+1;
	}
	check(ans);
	cout<<res+k*ans<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
