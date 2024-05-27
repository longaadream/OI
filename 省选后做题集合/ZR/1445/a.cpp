#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=1e6+5,M=55,inf=1e9;
int n,m,tot;
int f[N],pos[N],a[N],g[N];
i64 sum[N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int gcd(int n,int m){return m?gcd(m,n%m):n;}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt=read();
	clock_t be=clock();
	while(tt--){
		int n=read(),m=read();
		int lcm=1ll*n*m/gcd(n,m);
		if((lcm/n)&1||(lcm/m)&1) cout<<lcm*2;else cout<<lcm;
		puts("");
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
