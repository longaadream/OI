#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();};
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=2e5+5;
int a[N];
bitset<N> f;
int main(){
	int n=read();i64 sum=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i<n) sum+=a[i];
	} 
	sort(a+1,a+n+1);
	if(sum<a[n]) return puts("-1"),0;
	f[0]=1;
	for(int r=a[n]/2,pos=0,s=0;r<=a[n];r++){
		while(pos<=n-1&&a[pos+1]<r) f|=(f<<a[++pos]),s+=a[pos];
		int x=a[pos+1]-r,y=(pos==n-1)?r:(a[pos+2]-r);
		int cur=f._Find_next(x-1);
		if(s-cur>=y) return printf("%d",r),0;
	}
	return 0;
}