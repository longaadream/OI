#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=2e5+5;
int n;
map<int,int> pm1,pm2,flg,flg1;
vector<int> tru;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n=read();
	clock_t be=clock();
	for(int i=1;i<=n;i++){int x=read();pm1[x]++,pm2[x]++,tru.push_back(x);}
	sort(tru.begin(),tru.end());
	tru.erase(unique(tru.begin(),tru.end()),tru.end());
	int ans=tru.size();
	for(int i=0;i<(int)tru.size();i++){
		if(flg1[tru[i]-1]||flg1[tru[i]]) {ans-=1;continue;}
		flg1[tru[i]+1]=1;
	}
	int ans2=0;
	for(int i=0;i<(int)tru.size();i++){
		if(pm2[tru[i]]&&!flg[tru[i]-1]) flg[tru[i]-1]=1,ans2++,pm2[tru[i]]--;
		if(pm2[tru[i]]&&!flg[tru[i]]) flg[tru[i]]=1,ans2++,pm2[tru[i]]--;
		if(pm2[tru[i]]&&!flg[tru[i]+1]) flg[tru[i]+1]=1,ans2++,pm2[tru[i]]--;
	}
	cout<<ans<<" "<<ans2<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
