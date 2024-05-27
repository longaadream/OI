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
inline int nxt(int x,int y)
{
	x+=y;
	if(x>n) x-=n;
	else if(x<1) x+=n;
	return x;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read(),m=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
	for(int i=1;i<=2*n-1;i++) f[i]=inf;
	f[n]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*n-1;j++) g[j]=inf; 
		for(int j=-n+1;j<=n-1;j++) if(f[j+n]!=inf)
		{
			int now=nxt(pos[i],j);
			int dis=max(now-m,0ll);
			int i1=j-dis;
			if(i1<(1-n)) i1+=n;
			g[i1+n]=min(g[i1+n],f[j+n]+dis);
			dis=max(n-now+1,0ll);
			int i2=j+dis;
			if(i2>(n-1)) i2-=n;
			g[i2+n]=min(g[i2+n],f[j+n]+dis); 
		}
		for(int j=-n+1;j<=n-1;j++) f[j+n]=g[j+n];
	}
	int ans=inf;
	for(int j=-n+1;j<=n-1;j++) ans=min(ans,f[j+n]);
	cout<<ans<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
