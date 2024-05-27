#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=1e6+5,M=55,inf=1e9;
int n,m,tot;
int buk[N][M],a[N];
i64 sum[N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read(),m=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++) {a[i]=read();buk[i][a[i]]++;}
	for(int i=1;i<=50;i++){
		for(int j=1;j<=n;j++){
			buk[j][i]+=buk[j-1][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=50;j++){
			sum[i]+=buk[i-1][j];
		}
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		int ans=sum[r]-sum[l-1];
		for(int i=50,now=0;i;i--){
			ans-=(buk[r][i]-buk[l-1][i])*now;
			now+=buk[l-1][i];
		}
		cout<<ans<<endl;
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
