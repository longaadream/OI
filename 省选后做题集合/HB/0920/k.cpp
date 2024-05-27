#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=2e2+5,inf=1e9;
int n,a[N],p[N];
char s[N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10u+(c^48);c=getchar();}
	return x*f;
}
void dfs(int x,int sum){
	if(sum<0) return;
	if(s[x]){
		return dfs(x+1,sum+(s[x]=='('?1:-1));
	}
	if(x==n){
		std::cout<<s+1;exit(0);
	}
	if(!s[x]&&!s[a[x]]&&x<a[x]){s[x]='(',s[a[x]]=')';dfs(x+1,sum+1);s[x]=0,s[a[x]]=0;}
	if(!s[x]&&!s[p[x]]&&x<p[x]){s[x]=')',s[p[x]]='(';dfs(x+1,sum-1);s[x]=0,s[p[x]]=0;}
}
signed main(){
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++) {a[i]=read();if(a[i]>i) p[a[i]]=i;}
	s[1]='(',s[a[1]]=')';
	dfs(2,1);
	std::cout<<(s+1)<<endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}