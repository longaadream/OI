#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=65,mod=1e7+7;
bool Med;
inline i64 read(){
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
map<int,vector<i64>[2]> pm;
signed main(){
	int n=read(),x=read(),y=read(),z=read();i64 m=read();
	for(int i=1;i<=n;i++){pm[1ll*i*x%y][0].push_back(1ll*i*x+y),pm[1ll*i*x%y][1].push_back(1ll*i*x+1ll*n*y+1);}
	i64 ans=0;
	for(int i=1;i<=n;i++){
		i64 xx=m-1ll*i*z;
		if(xx<=0) break;
		ans+=upper_bound(pm[xx%y][0].begin(),pm[xx%y][0].end(),xx)-pm[xx%y][0].begin();
		ans-=upper_bound(pm[xx%y][1].begin(),pm[xx%y][1].end(),xx)-pm[xx%y][1].begin();
	}
	cout<<ans<<endl; 
	return 0;
}