#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=25,mod=1e9+7;
void M(int &a){return (a>mod||a<0)&&((a+=mod)%=mod),void();}
int n,m,l,T;
int pos(int x,int y){return (x-1)*m+y;}
struct mat{
	int a[N][N];
	void init(){memset(a,0,sizeof a);for(int i=1;i<=l;i++){a[i][i]=1;}}
	void clear(){memset(a,0,sizeof a);}
	void allset(){for(int i=1;i<=l;i++)for(int j=1;j<=l;j++) a[i][j]=1;}
	void set(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i!=1) a[pos(i-1,j)][pos(i,j)]=1;
				if(j!=1) a[pos(i,j-1)][pos(i,j)]=1;
				if(i!=n) a[pos(i+1,j)][pos(i,j)]=1;
				if(j!=m) a[pos(i,j+1)][pos(i,j)]=1;
			}
		}
	}
	void reset(int i,int j){
		if(i!=1) a[pos(i-1,j)][pos(i,j)]=a[pos(i,j)][pos(i-1,j)]=0;
		if(j!=1) a[pos(i,j-1)][pos(i,j)]=a[pos(i,j)][pos(i,j-1)]=0;
		if(i!=n) a[pos(i+1,j)][pos(i,j)]=a[pos(i,j)][pos(i+1,j)]=0;
		if(j!=m) a[pos(i,j+1)][pos(i,j)]=a[pos(i,j)][pos(i,j+1)]=0;
	}
	void del(int i,int j){
		if(i!=1) a[pos(i-1,j)][pos(i,j)]=a[pos(i,j)][pos(i-1,j)]=1;
		if(j!=1) a[pos(i,j-1)][pos(i,j)]=a[pos(i,j)][pos(i,j-1)]=1;
		if(i!=n) a[pos(i+1,j)][pos(i,j)]=a[pos(i,j)][pos(i+1,j)]=1;
		if(j!=m) a[pos(i,j+1)][pos(i,j)]=a[pos(i,j)][pos(i,j+1)]=1;
	}
}cur,trans;
mat mul(mat a,mat b){
	mat c;
	c.clear();
	for(int i=1;i<=l;i++){
		for(int j=1;j<=l;j++){
			for(int k=1;k<=l;k++){
				M(c.a[i][j]+=1ll*a.a[i][k]*b.a[k][j]%mod);
			}
		}
	}
	return c;
}
mat qpow(mat a,int b){
	mat res;
	res.init();
	while(b){
		if(b&1) res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	// int tt=read();
	clock_t be=clock();
	T=read(),n=read(),m=read(),l=m*n;
	int lst=0;
	trans.set();cur.allset();
	while(T--){
		int op=read(),x=read(),y=read(),i=read();
		if(op==1){
			trans.reset(x,y);
		}else if(op==2){

		}else{

		}
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
