#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=5e5+5;
int n,k,l,r,st[N][25],pos[N][25],lg[N];
void init(){
	for(int i=1;i<=23;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			if(st[j][i-1]>st[j+(1<<(i-1))][i-1]) pos[j][i]=pos[j][i-1];else pos[j][i]=pos[j+(1<<(i-1))][i-1];
		}
	}
}
int query(int l,int r){
	int leg=lg[r-l+1];
	return st[l][leg]>st[r-(1<<leg)+1][leg]?pos[l][leg]:pos[r-(1<<leg)+1][leg];
}
struct node{	
	int l,r1,r2,t;
	node(int l,int r1,int r2):l(l),r1(r1),r2(r2),t(query(r1,r2)){}
	bool operator<(const node b)const{
		return st[t][0]-st[l-1][0]<st[b.t][0]-st[b.l-1][0];
	}
};
priority_queue<node> q;
signed main(){
	n=read(),k=read(),l=read(),r=read();
	lg[0]=-1;
	for(int i=1;i<=n;i++){
		lg[i]=lg[i>>1]+1;
	}
	for(int i=1;i<=n;i++){
		st[i][0]=read()+st[i-1][0],pos[i][0]=i;
	}
	init();
	for(int i=1;i+l-1<=n;i++){
		q.push(node(i,i+l-1,min(n,i+r-1)));
	}
	i64 ans=0;
	while(k--){
		node tmp=q.top();
		q.pop();
		ans+=st[tmp.t][0]-st[tmp.l-1][0];
		if(tmp.r1!=tmp.t) q.push(node(tmp.l,tmp.r1,tmp.t-1));
		if(tmp.r2!=tmp.t) q.push(node(tmp.l,tmp.t+1,tmp.r2));
	}
	cout<<ans;
	return 0;
}