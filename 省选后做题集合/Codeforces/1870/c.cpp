#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=1e5+5;
int a[N],pos[N],fir[N],ans[N],vis[N];
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
		int n=read(),k=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			vis[a[i]]=1;
			for(int j=a[i];j;j--){if(fir[j]) break; else fir[j]=i;}
		}
		for(int i=n;i;i--){
			for(int j=a[i];j;j--){if(pos[j])break;else pos[j]=i;}
		}
		for(int i=1;i<=k;i++){
			if(vis[i])  
			cout<<2ll*(pos[i]-fir[i]+1)<<" ";
			else cout<<"0 ";
		}
		puts("");
		memset(vis,0,sizeof vis);
		memset(fir,0,sizeof fir);
		memset(pos,0,sizeof pos);
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}