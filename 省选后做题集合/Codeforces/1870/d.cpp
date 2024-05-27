#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=1e5+5;
int a[N];
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
		int n=read(),mx=0x7fffffff,pos=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]<=mx) pos=i,mx=a[i];
		}
		int k=read(),use1=(k/mx)-1,rem=k-use1*mx;
		int mn=0x7fffffff,pos2=0;
		for(int i=n;i>pos;i--){
			if(a[i]<mn){pos2=i,mn=a[i];}
		}
		if(mn<=rem){
			for(int i=1;i<=pos;i++) cout<<use1+1<<" ";
			for(int i=pos+1;i<=pos2;i++) cout<<(k%mx)/(mn-mx)<<" ";
			for(int i=pos2+1;i<=n;i++) cout<<"0 ";
			puts("");
			goto end;
		}
		for(int i=1;i<=pos;i++) cout<<use1+1<<" ";
		for(int i=pos+1;i<=n;i++) cout<<"0 ";
		puts("");
		end:{}
		for(int i=1;i<=n;i++) a[i]=0;
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}