#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=2e5+5,M=205,inf=1e9;
int n;
int sum[M];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();i64 ans=0;
	clock_t be=clock();
	for(int i=1;i<=n;i++){
		int x=read();
		x=(x%200+200)%200;
		ans+=sum[x];
		sum[x]++;
	}
	cout<<ans<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
