#include<bits/stdc++.h>
using namespace std;
#define i64 long long;
const int N=1e6+5;
int son[N][27],fail[N],flag[N];
int cnt=1;
void insert(char *s,int n){
	int u=1;
	for(int i=1;i<=n;i++){
		int v=s[i]-'a';
		if(!son[u][v]) son[u][v]=++cnt;
		u=son[u][v];
	}
	flag[u]++;
}
void build(){
	for(int i=0;i<26;i++){
		son[0][i]=1;
	}
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int v=son[u][i],t=fail[u];
			if(!v) son[u][i]=son[t][i];
			else fail[v]=son[t][i];
			if(v) q.push(v);
		}
	}
}
int query(char *s,int n){
	int u=1,ans=0;
	for(int i=1;i<=n;i++){
		int v=s[i]-'a';
		int k=son[u][v];
		while(k>1&&flag[k]!=-1){
			ans+=flag[k],flag[k]=-1;
			k=fail[k];
		}
		u=son[u][v];
	}
	return ans;
}
int n;
char s[N],t[N];
signed main(){
	int tt;
	cin>>tt;
	while(tt--){
		cin>>n;
		memset(son,0,sizeof son);
		memset(flag,0,sizeof flag);
		memset(fail,0,sizeof fail);
		cnt=1;
		while(n--){
			cin>>(s+1);
			insert(s,strlen(s+1));
		}
		build();
		cin>>(t+1);
		cout<<query(t,strlen(t+1))<<endl;
	}
	return 0;
}