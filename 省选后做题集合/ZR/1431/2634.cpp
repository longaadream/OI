#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=5e5+10,mod=1e7+7;
bool Med;
inline i64 read(){
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int tt;
int n,l,r;
signed main(){
	tt=read();
	while(tt--){
		n=read(),l=0,r=1e9;
		int ori=read(),tmp=0;
		for(int i=2;i<=n;i++) {int t=read();tmp=t-tmp;if(i%2==0)r=min(r,tmp);else l=max(l,-tmp);}
		l=max(l,tmp-ori);
		if(l<=r) puts("1");else puts("0");
	}
	return 0;
}