#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64=long long;
const int N=7e4+5;
bool Mbe;
char s[N];
bitset<N> b;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main(){
	clock_t be=clock();
	cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	read();
	scanf("%s",s+1);
	int n=strlen(s+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='e') b.set(i,1); 
	}
	for(int i=b._Find_first();i!=b.size();i=b._Find_next(i)){
		ans++;
		if(b._Find_next(i)-i>2){ans+=3; continue;}
		ans+=3-(b._Find_next(i)-i);
	}
	cout<<ans<<endl;
	cerr<<clock()-be<<"ms"<<endl;
	return 0;
}