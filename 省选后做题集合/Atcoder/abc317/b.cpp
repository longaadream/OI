#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=1005;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,a[N];
signed main(){
	n=read();for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i]+1<a[i+1]) return cout<<a[i]+1<<endl,0;		
	}
	return 0;
}