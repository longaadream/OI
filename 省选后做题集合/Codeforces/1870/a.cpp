#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;

bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt=read();
	clock_t be=clock();
	while(tt--){
		int n=read(),k=read(),x=read();
		if(k-1>x) {puts("-1");continue;}
		if(n<k) {puts("-1");continue;}
		if(k==x){
			cout<<1ll*k*(k-1)/2+1ll*(n-k)*(x-1)<<endl;
			continue;
		}else{
			cout<<1ll*k*(k-1)/2+1ll*(n-k)*x<<endl;
			continue;
		}
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}