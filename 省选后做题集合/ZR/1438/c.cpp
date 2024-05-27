#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
bool Mbe;
const int N=2e5+5;
int n,siz;
map<char,char> src;
map<char,bool> vis;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
bool check(char c1,char c2){
	if(siz>=25) return 0;
	for(char c=src[c1];c;c=src[c]){
		if(c==c1||c==c2) return 1;
	}
	return 0;
}
signed main(){
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	clock_t be=clock();
	int tt=read();
	while(tt--){
		n=read(),siz=0;
		string a;
		string b;
		cin>>a;
		for(int i='a';i<'z';i++) src[i]=vis[i]=0;
		for(int i=0;i<(int)a.size();i++){
			if(src[a[i]]) {b.push_back(src[a[i]]);continue;}
			char j;
			for(j='a';vis[j]||a[i]==j||check(j,a[i]);++j);
			b.push_back(j);src[a[i]]=j,vis[j]=1,siz++;
		}
		cout<<b<<endl;
		src.clear(),vis.clear();
	}
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
