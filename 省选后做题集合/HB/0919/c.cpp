#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e5+5;
u32 n,p,q,c[N];
bool Med;
inline u32 read(){
	u32 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10u+(c^48);c=getchar();}
	return x*f;
}
inline void down(u32 &a,u32 b){a>b?a=b:0;}
inline u32 gcd(u32 a,u32 b){return b?gcd(b,a%b):a;}
u32 calc(u32 x){
	std::vector<u32> a,b;
	for(u32 i=1;i<=x;i++){a.push_back(n-i+1);b.push_back(i);}
	for(u32 &x:a) for(u32 &y:b){u32 com=gcd(x,y);x/=com,y/=com;}
	u32 res=1;
	for(u32 r:a) res=res*r;
	return res; 
}
signed main(){
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read(),p=read(),q=read(); down(p,n-1);
	clock_t be=clock();
	for(u32 i=0;i<=p;i++){
		c[i]=calc(i);
	}
	u32 ans=0;
	for(u32 i=1;i<=q;i++){
		u32 cur=0;
		for(u32 j=0,pw=1;j<=p;j++,pw*=i){
			cur+=c[j]*pw;
		}
		ans^=cur*i;
	}
	std::cout<<ans<<endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}