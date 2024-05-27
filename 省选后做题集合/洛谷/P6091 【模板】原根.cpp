#include<bits/stdc++.h>
using namespace std;
using i64=long long;
#define endl '\n'
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e6+5;
int phi[N],isprime[N],isrt[N];
vector<int> p;
void euler(){
	isprime[1]=1;
	for(int i=2;i<=N-5;i++){
		if(!isprime[i]){
			p.push_back(i);
			phi[i]=i-1;
		}
		for(int j:p){
			if(i*j>=N-5) break;
			isprime[i*j]=1,phi[i*j]=phi[i]*phi[j];
			if(i%j==0){
				phi[i*j]=phi[i]*j;
				break;
			}
			phi[i*j]=phi[i]*phi[j];
		}
	}
	isrt[2]=1,isrt[4]=1;
	for(int i:p){
		if(i==2) continue;
		for(int j=1;i*j<=N-5;j*=i){
			isrt[i]=isrt[2*i]=1;
		}
	}
}
vector<int> ans,prod;
void makeprod(int x){
	prod.clear();
	for(int i=0;x!=1;i++){
		if(x%p[i]==0) x/=p[i],prod.push_back(p[i]);
		while(x%p[i]==0) x/=p[i];
	}
}
int qpow(int a,int b,int p){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%p;
		a=1ll*a*a%p;
		b>>=1; 
	}
	return res;
}
bool chk(int x,int p){
	if(qpow(x,phi[p],p)!=1){
		return 0;
	}
	for(int i:prod){
		if(qpow(x,i,p)==1){
			return 0;
		}
	}
	return 1;
}
int getrt(int x){
	ans.clear();
	for(int i=2;i<x;i++){
		if(chk(i,x)) return i;
	}
}
signed main(){
	int tt=read();
	euler();
	while(tt--){
		int n=read(),d=read();
		if(isrt[n]){
			cout<<phi[phi[n]]<<endl;
			getrt(n);

		}else{
			cout<<0<<endl<<endl;
		}

	}
	return 0;
}