#include<bits/stdc++.h>
using namespace std;
#define int __int128	
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
void write(int a){
	if(!a) return puts("0"),void();
	static int st[60],top=0;
	while(a){
		st[++top]=a%10;
		a/=10;
	}
	while(top){
		putchar('0'+st[top--]);
	}
	return ;
}
signed main(){
	a=10,b=(9ll*read()+1),mod=read();
	b%=mod;
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
			return write(((i*T+pm[pw])%(mod-1)+mod)%mod),0;
		}
		pw=1ll*pw*inv%mod;
	}return cout<<"no solution",0;
}