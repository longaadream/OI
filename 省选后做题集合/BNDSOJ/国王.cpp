#include<bits/stdc++.h>
using namespace std;
using i64=long long;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int f[160][160],g[160][160],sts[160],num[160],n,k,cnt;
signed main(){
	n=read(),k=read();
	for(int i=0;i<(1<<n);i++){
		if(i&(i<<1)) continue;	
		sts[++cnt]=i,num[cnt]=__builtin_popcount(i);
		f[__builtin_popcount(i)][cnt]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int l=1;l<=cnt;l++){
				if(j>=num[l]){
					for(int l2=1;l2<=cnt;l2++){
						if(!(sts[l2]&sts[l])&&!(sts[l2]&(sts[l]<<1))&&!((sts[l2]<<1)&sts[l])){
							g[j][l]+=f[j-num[l]][l2];
						}
					}
				}
			}
		}
		memcpy(f,g,sizeof f);
		memset(g,0,sizeof g);
	}
	i64 ans=0;
	for(int i=1;i<=cnt;i++){
		ans+=f[k][i];
	}
	cout<<ans;
	return 0;
}