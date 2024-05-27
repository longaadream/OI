#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=2e5+5;
struct ACAM{
	int cnt=1,f[N],son[N][27],ed[N];
	void insert(string s){
		int u=1;
		for(char c:s){
			if(!son[u][c-'a']) son[u][c-'a']=++cnt;
			u=son[u][c-'a'];
		}
		ed[u]++;
	}
	void build(){
		queue<int> q;
		for(int i=0;i<26;i++){
			son[0][i]=1;
		}
		q.push(1);
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int i=0;i<26;i++){
				int v=son[u][i],t=f[u];
				if(!v) son[u][i]=son[t][i]; else f[v]=son[t][i];
				if(v) q.push(v);
			}
			ed[u]+=ed[f[u]];
		}
	}
}a1,a2;
string a;
int n,s[N];
signed main(){
	cin>>a>>n;
	for(int i=1;i<=n;i++){
		string tmp;
		cin>>tmp;
		a1.insert(tmp);reverse(tmp.begin(),tmp.end());a2.insert(tmp);
	}
	a1.build(),a2.build();
	for(int i=0,p=1;i<(int)a.size();i++){
		p=a1.son[p][a[i]-'a'],s[i]=a1.ed[p]; 
	}
	i64 ans=0;
	for(int i=(int)a.size()-1,p=1;i>0;i--){
		p=a2.son[p][a[i]-'a'],ans+=1ll*a2.ed[p]*s[i-1];
	}
	cout<<ans;
	return 0;
}
