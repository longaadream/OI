#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
const int N=2e5+5;
bool Mbe;
int tt,n;
map<int,bool> mp;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	tt=read();
	clock_t be=clock();
	while(tt--){
		n=read();
		vector<int> prod;
		for(int i=2;i*i<=n;i++){
			if(n%i==0){prod.push_back(i),mp[i]=1;if(i!=n/i)prod.push_back(n/i),mp[n/i]=1;}
		}
		prod.push_back(n);
		mp[n]=1;
		sort(prod.begin(),prod.end());
		vector<int> ans;
		for(int i=0;i<(int)prod.size();i++){
			if(!mp[prod[i]]) continue;
			int lcm=prod[i]*prod[i-1]/gcd(prod[i],prod[i-1]);
			for(int j=1;j*lcm<=n;j++)if(i&&mp[j*prod[i]*prod[i-1]/gcd(prod[i],prod[i-1])]) ans.push_back(j*prod[i]*prod[i-1]/gcd(prod[i],prod[i-1])),mp[j*prod[i]*prod[i-1]/gcd(prod[i],prod[i-1])]=0;
			if(!mp[prod[i]]) continue;
			ans.push_back(prod[i]);
		}
		for(int i:ans){
			cout<<i<<" ";
		}
		putchar(10);
		int cnt=0;
		for(int i=0;i<(int)ans.size();i++){
			if(gcd(ans[i],ans[(i-1+ans.size())%ans.size()])==1) cnt++;
		}
		cout<<cnt<<endl;
		mp.clear();
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}