#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=5e5+5;
int n,a[N],b[N],f[N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int ans=0;n=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++){a[i]=read();while(a[i]%2==0) a[i]/=2,b[i]++;}
	f[0]=f[1]=0;
	for(int i=2;i<=n;i++){
		f[i]=i-1;
		for(int j=i-1;j;j--){
			if((a[j]%a[i]==0)&&(b[i]<=i-j-1||b[i]-b[j]==i-j)){
				f[i]=min(f[i],f[j]+i-j-1);
			}
		}
	}
	ans=0x7fffffff;
	for(int i=1;i<=n;i++){
		ans=min(ans,f[i]+n-i);
	}
	cout<<ans<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
