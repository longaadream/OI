#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int Lim=3e5+5,M=105;
char s[M];
int a[M];
int dp[Lim][M],lim;
int n,m;
map<int,bool> pm;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	clock_t be=clock();
	cin>>(s+1);n=strlen(s+1);for(int i=1;i<=n;i++){a[i]=s[i]-'0';}m=read();
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(pm[a[i]]) continue;pm[a[i]]=1;
			dp[1<<(i-1)][a[i]%m]=1;
		}
	}
	lim=(1<<n)-1;
	for(int bit=1;bit<=lim;bit++){
		pm.clear();
		for(int i=1;i<=n;i++){
			if(!(bit&(1<<(i-1)))){
				if(pm[a[i]]) continue;pm[a[i]]=1;
				for(int j=0;j<m;j++)
					dp[bit|(1<<(i-1))][(j*10+a[i])%m]+=dp[bit][j];
			}
		}
	}
	cout<<dp[lim][0]<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
