	#include<bits/stdc++.h>
	using namespace std;
	using i64=long long;
	#define int __int128
	const int N=71,mod=1e9+7;
	i64 bt[N],n;
	int p[N],tot;
	inline int read(){
		int x=0,f=1;char c=getchar();
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
		return x*f;
	}
	int qpow(int a,int b){
		int res=1;
		while(b){
			if(b&1) res=1ll*a*res%mod;
			a=1ll*a*a%mod;
			b>>=1;
		}
		return res;
	}
	int msk[N];
	int makemask(int x){
		i64 tmp=0;
		for(int i=1;i<=tot;i++){
	//		cerr<<p[i]<<endl;
			if(x<p[i]) continue;
			while(x%p[i]==0){
				x/=p[i],tmp^=(1ll<<(i-1));
			}
		}
		return tmp;
	}
	void insert(int x){
		for(int i=tot;i>=0;i--){
			if(!(((__int128)(__int128)1<<i)&x)){
				continue;
			} 		
			if(!bt[i]) return (void)(bt[i]=x); else x=x^bt[i];
		}
	}
	bool check(int x){
		for(int i=2;i*i<=x;i++){
			if(x%i==0) return 0;
		}
		return 1;
	}
	void print(int x){
		if(!x) return ;
		print(x/10);
		putchar((x%10)+'0');	
	}
	signed main(){
		int n=read();
		for(int i(2);i<=70;i++){
			if(check(i)) p[++tot]=i;
		}
		for(int i=1;i<=70;i++){
			msk[i]=makemask(i);
		}
		for(int i=1;i<=n;i++){
			int x=read();
			insert(msk[x]);
		}
		int ct=0;
		for(int i=tot;i>=0;i--){
			if(bt[i]) ct++;
		}
		if((qpow(2,(n-ct))-1+mod)%mod==0){
			return puts("0"),0;
		}
		print((qpow(2,(n-ct))-1+mod)%mod);
		return 0;
	}
