#include<bits/stdc++.h>
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int MAXN=8e6,mod=1e9+7;
using namespace std;
int n,m,ans;
int f[MAXN],pw[MAXN];
int main(){
	freopen("kosare.in","r",stdin);
	freopen("kosare.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<(1<<22);i++)pw[i]=(pw[i-1]+pw[i-1])%mod;
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		int k=read();
		int st=(1<<m)-1;
		while(k--){
			int x=read();
			st^=(1<<(x-1));
		}f[st]++;
	}
	for(int i=1;i<=m;i++)
		for(int mask=0;mask<(1<<m);mask++)
			if(mask&(1<<(i-1)))
				f[mask^(1<<(i-1))]=(f[mask^(1<<(i-1))]+f[mask])%mod;
	for(int mask=0;mask<(1<<m);mask++){
		int sgn=__builtin_popcount(mask)&1?-1:1;
		ans=(ans+(pw[f[mask]]-1)*sgn)%mod;
	}cout<<(ans+mod)%mod;
	return 0;
}
