#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using namespace std;
using i64=long long;
const int N=2e5+5;
bool Mbe;
int n,m,a[N],ind[N],len,cnt,ls[N<<5],rs[N<<5],rt[N<<5];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int build(int l,int r){
	int nw=++cnt;
	if(l==r) return nw;
	int mid=(l+r)>>1;
	ls[nw]=build(l,mid);
	rs[nw]=build(mid+1,r);
	return nw;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read(),m=read();
	clock_t be=clock();
	rt[0]=build(1,n);
	while(m--){
		
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}