#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=15;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	int n=read(),h=read(),x=read();
	for(int i=1;i<=n;i++){
		int t=read();
		if(t+h>=x) return cout<<i<<endl,0;	 
	}
	return 0;
}