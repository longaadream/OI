#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=105,M=55,inf=1e9;
int n,val[N*N];
vector<bitset<105>> be,ed;
bool vis[N*N];
vector<array<int,3>> E[N];
bitset<105> tmp;
bitset<105> nul;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
void dfs1(int x){
	if(x==n){
		be.push_back(tmp);
		return;
	}
	for(auto to:E[x]){
		if(vis[to[1]]) continue;
		vis[to[1]]=1;
		tmp[to[0]]=1;
		dfs1(to[1]);
		tmp[to[0]]=0;
		vis[to[1]]=0;
	}
}
void dfs2(int x){
	if(x==1){
		ed.push_back(tmp);
		return;
	}
	for(auto to:E[x]){
		if(vis[to[1]]) continue;
		vis[to[1]]=1;
		tmp[to[0]]=1;
		dfs2(to[1]);
		tmp[to[0]]=0;
		vis[to[1]]=0;
	}
}
i64 calc(bitset<105> x){
	i64 ans=0;
	for(int i=1;i<=n*n;i++){
		bitset<105> cur;
		cur[i]=1;
		if((x&cur)!=nul){
			ans+=val[i];
		}
	}
	return ans;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();
	clock_t Be=clock();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int t=read();
			if(t){
				E[i].push_back({(i-1)*n+j,j,t});
				val[(i-1)*n+j]=t;
			}
		}
	}
	vis[1]=1;
	dfs1(1);
	vis[1]=0;
	vis[n]=1;
	dfs2(n);
	vis[n]=0;
	int ans=inf;
	for(bitset<105> a:be){
		for(bitset<105> b:ed){
			bitset<105> mp=a|b;
			ans=min(ans,calc(mp));
		}
	}
	cout<<ans<<endl;
	cerr<<clock()-Be<<"ms"<<endl;
	return 0;
}
