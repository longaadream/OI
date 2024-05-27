#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=(1<<16)+5,M=55,inf=1e9,mod=1e9+7;
int u[M],v[M],deg[M],ans[M];
map<pii,int> pm;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int n=read(),m=read();
	clock_t be=clock();
	for(int i=1;i<=m;i++){
		u[i]=read(),v[i]=read();
		// if(u[i]>v[i]) swap(u[i],v[i]);
		// if(pm[make_pair(u[i],v[i])]) u[i]=v[i]=0;
		// pm[make_pair(u[i],v[i])]=1;
	}
	for(int bt=0;bt<(1<<m);bt++){
		for(int i=1;i<=n;i++) deg[i]=0;
		for(int i=1;i<=m;i++){
			if(bt&(1<<(i-1))) {deg[u[i]]++,deg[v[i]]++;}
		}
		int flg=0;
		for(int i=1;i<=n;i++) if(deg[i]&1) flg=1;
		if(!flg) ans[__builtin_popcount(bt)]++;
	}
	i64 res=0;
	for(int i=1;i<=m;i++){
		res+=1ll*i*i%mod*ans[i]%mod;
		res%=mod;
	}
	cout<<res<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}