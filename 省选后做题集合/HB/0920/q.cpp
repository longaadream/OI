#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=15,inf=1e9;
int n;
double a[N][N],b[N][N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();
	clock_t be=clock();
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++) std::cin>>a[i][j];
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++){
			a[i][n+1]-=a[i][j]*a[i][j];
			a[i][j]*=2;
		}
	}
	for(int i=n;i;i--){
		for(int j=1;j<=n+1;j++){
			b[i][j]=a[i][j]-a[i+1][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i][i]==0){
			for(int j=1;i<=n;i++){
				if(b[j][i]!=0){
					for(int k=1;k<=n+1;k++){
						std::swap(b[k][i],b[i][i]);
					}
					break;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			double d=b[j][i]/b[i][i];
			for(int k=i;k<=n+1;k++){
				b[j][k]-=b[i][k]*d;
			}
		}
	}
	for(int i=1;i<=n;i++){
		std::cout<<std::fixed<<std::setprecision(6)<<-1.00*b[i][n+1]/b[i][i]<<" ";
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}