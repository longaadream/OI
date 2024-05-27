#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=2005,mod=1e7+7;
bool Med;
inline i64 read(){
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int hori[N][N],vert[N][N],n,m,h,w,k;
int get(int l1,int r1,int l2,int r2){
	return (hori[l2][r2-1]-hori[l2][r1-1]-hori[l1-1][r2-1]+hori[l1-1][r1-1])+(vert[l2-1][r2]-vert[l1-1][r2]-vert[l2-1][r1-1]+vert[l1-1][r1-1]);
}
char s[N][N];
signed main(){
	n=read(),m=read(),h=read(),w=read(),k=read();
	for(int i=1;i<=n;i++){
		cin>>(s[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((s[i][j]^s[i][j+1])==1){
				hori[i][j]++;
			}
			if((s[i][j]^s[i+1][j])==1){
				vert[i][j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			hori[i][j]+=hori[i-1][j]+hori[i][j-1]-hori[i-1][j-1],vert[i][j]+=vert[i-1][j]+vert[i][j-1]-vert[i-1][j-1];
		}
	}
	i64 ans=0;
	for(int i=1;i+h-1<=n;i++){
		for(int j=1;j+w-1<=m;j++){
			if(get(i,j,i+h-1,j+w-1)>=k){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}