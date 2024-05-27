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
		int n=read(),m=read();
		int res=0;
		for(int i=1;i<=n;i++){
			res^=read();
		}
		int mx=res,mn=res;
		auto chkmx=[&](int a,int b){
			int res=a;
			for(int i=0;i<=30;i++){
				if(b&(1<<i)){
					if(n&1) res|=(1<<i);
					else {res|=(1<<i),res^=(1<<i);} 
				}
			}
			return res;
		};
		for(int i=1;i<=m;i++){
			int t=read();
			mx=max(mx,chkmx(mx,t));
			mn=min(mn,chkmx(mn,t));
		}
		cout<<mn<<" "<<mx<<endl;
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}