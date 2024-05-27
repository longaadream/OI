#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=2e3+5,inf=1e9;
int n,d,x[N],y[N];
bool chk[N][N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10u+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read(),d=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for(int i=1;i<=n;i++){
		double k1=inf,k2=-inf;
		for(int j=i+1;j<=n;j++){
			
		}
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}