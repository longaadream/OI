#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=5e5+5;
int n,k,wh[N],dp[N],cnt[N],sec[N][2];
char s[N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();cin>>(s+1);k=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++){
		wh[i]=wh[i-1]+(s[i]=='?');
		dp[i]=dp[i-1],cnt[i]=cnt[i-1];
		if(s[i]!='a') sec[i][0]=sec[i-1][1]+1;
		if(s[i]!='b') sec[i][1]=sec[i-1][0]+1;
		if(sec[i][k&1]>=k){
			if(dp[i]<dp[i-k]+1) dp[i]=dp[i-k]+1,cnt[i]=cnt[i-k]+wh[i]-wh[i-k];
			else if(dp[i]==dp[i-k]+1) cnt[i]=min(cnt[i],cnt[i-k]+wh[i]-wh[i-k]);
		}
	}
	cout<<cnt[n]<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
