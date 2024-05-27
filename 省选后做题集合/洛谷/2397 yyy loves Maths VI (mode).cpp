#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline i64 read(){
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int cnt[50];
signed main(){
	int n=read(),nn=n;
	while(n--){
		i64 tmp=read();
		int i=0;
		while(tmp){
			if(tmp&1){
				cnt[i]++;
			}
			i++,tmp>>=1;
		}
	}
	i64 ans=0;
	for(int i=0;i<=32;i++){
		if(cnt[i]>nn/2){
			ans|=(1<<i);
		}
	}
	cout<<ans;
	return 0;
} 
