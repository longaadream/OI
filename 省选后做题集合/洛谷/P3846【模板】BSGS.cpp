#include<bits/stdc++.h>
using namespace std;
#define int long long	
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
map<int,int> pm;
int a,b,mod;
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
signed main(){
	mod=read(),a=read(),b=read();
	int inv=qpow(a,mod-2),T=0,pw=1;
	while(T*T<mod) T++;
	// cout<<T<<endl;
	for(int i=0;i<T;i++){
		pm[b*pw%mod]=i;
		// cout<<pw<<endl;
		pw=1ll*pw*inv%mod;
	}
	inv=qpow(a,T),pw=1;
	for(int i=0;i<T;i++){
		if(pm[pw]){
			return cout<<(i*T+pm[pw])%(mod-1),0;
		}
		pw=1ll*pw*inv%mod;
	}return cout<<"no solution",0;
}