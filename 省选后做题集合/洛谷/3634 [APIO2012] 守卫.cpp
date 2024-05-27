#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e5+5;
int n,k,m,det[N],ori[N],nxt[N],lst[N],cnt,pre[N],suf[N];
vector<pair<int,int>> v;
signed main(){
	n=read(),k=read(),m=read();
	for(int i=1,x,y,op;i<=m;i++){
		x=read(),y=read(),op=read();
		if(!op) det[x]++,det[y+1]--; else v.emplace_back(make_pair(x,y));
	}	
	for(int i=1;i<=n;i++){
		det[i]+=det[i-1];
		if(!det[i]) lst[i]=nxt[i]=++cnt,ori[cnt]=i;
	}
	for(int i=1;i<=n;i++){
		if(!lst[i]) lst[i]=lst[i-1];
	}
	for(int i=n;i>=1;i--){
		if(!nxt[i])nxt[i]=nxt[i+1];
	}
	for(int i=0;i<(int)v.size();i++){
		v[i].first=nxt[v[i].first],v[i].second=lst[v[i].second];
	}
	if(k==cnt){
		for(int i=1;i<=cnt;i++)cout<<ori[i]<<"\n";
		return 0;
	}
	sort(v.begin(),v.end());
	stack<pair<int,int>> st;
	for(int i=0;i<(int)v.size();i++){
		while(st.size()&&st.top().second>=v[i].second) st.pop();
		st.push(v[i]);
	}
	v.clear();
	while(st.size()){
		v.emplace_back(st.top());
		st.pop();
	}
	sort(v.begin(),v.end());
	int mx=0,mn=1e9;
	for(int i=0;i<(int)v.size();i++){
		if(!i) mx=v[i].second,pre[i]=1;
		if(v[i].first>mx) pre[i]=pre[i-1]+1,mx=v[i].second;else pre[i]=pre[i-1];
	}
	for(int i=(int)v.size()-1;i>=0;i--){
		if(v[i].second<mn)suf[i]=suf[i+1]+1,mn=v[i].first; else suf[i]=suf[i+1];
	}
	vector<int> res;
	for(int i=0;i<(int)v.size();i++){
		if(v[i].first==v[i].second) {res.emplace_back(ori[v[i].first]);continue;}
		if(pre[i]!=pre[i-1]+1&&i) continue;
		int ans=v.size(),l=i+1,r=(int)v.size()-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(v[mid].first>=v[i].second) ans=mid,r=mid-1; else l=mid+1;
		}
		if(pre[i]+suf[ans]>=k) res.emplace_back(ori[v[i].second]); 
	}
	if(!res.size()){
		return puts("-1"),0;
	}
	for(int i:res){
		cout<<i<<"\n";
	}
	return 0;
}
