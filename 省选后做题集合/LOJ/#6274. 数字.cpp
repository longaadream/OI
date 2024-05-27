#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
int T,l1,l2,r1,r2,dp[61][1<<16],s,t,tl1,tl2,tr1,tr2,a,b,c,d;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
#define compress(a,b,c,d) (a|(b<<1)|(c<<2)|(d<<3))
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	// int tt=read();
	T=read(),l1=read(),r1=read(),l2=read(),r2=read();
	clock_t be=clock();
	dp[60][1<<compress(1,1,1,1)]=1;
	for(int i=59;~i;--i){
		t=T>>i&1,tl1=l1>>i&1,tl2=l2>>i&1,tr1=r1>>i&1,tr2=r2>>i&1;
		for(int j=0;j<(1<<16);++j){
			if(!dp[i+1][j]) continue;
			for(int v=0;v<=1;++v){
				for(int bit=0;bit<(1<<4);++bit){
					if(!(j&(1<<bit))) continue;
					s=0,a=s&1,b=s>>1&1,c=s>>2&1,d=s>>3&1;
					for(int x=0;x<=1;++x){
						for(int y=0;y<=1;++y){
							if(((x|y)==t)&&((x&y)==v)&&(!a||x>=tl1)&&(!b||x<=tr1)&&(!c||y>=tl2)&&(!d||y<=tr2)){
								s|=compress(a&&(x>=tl1),b&&(x<=tr1),c&&(y>=tl2),d&&(y<=tr2));
							}
						}
					}
				}
				dp[i][s]+=dp[i+1][j];
			}
		}
	}
	int ans=0;
	for(int i=1;i<(1<<16);++i){
		ans+=dp[0][i];
	}
	cout<<ans<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
