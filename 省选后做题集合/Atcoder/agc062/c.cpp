#include<bits/stdc++.h>
using namespace std;
using i64=long long;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=105;
i64 a[N],n,k;
set<i64> s,tmp;
void print(){
	int cnt=0;
	for(int i:s){
		cout<<i<<" ";
		if(++cnt==k) exit(0);
	}
	exit(0);
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	i64 sum=0; sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(sum<a[i]){
			tmp=s;
			for(i64 j=sum+1;j<a[i];j++) {s.insert(j);if((signed)s.size()>=k) print();}
			if((signed)s.size()>=k) print(); 
			for(i64 j:tmp){
				s.insert(j+a[i]);
			}
		}else{
			tmp.clear();
			for(i64 j:s){
				if(j<a[i]) tmp.insert(j);  
			}
			if((signed)tmp.size()>=k) {s=tmp;print();}
			for(i64 j:s){
				if(j>a[i]&&s.count(j-a[i])) tmp.insert(j);
				if(j+a[i]>sum) tmp.insert(j+a[i]);
			}
			s=tmp;
		}
		sum+=a[i];
	}
	for(i64 i=sum+1;(signed)s.size()<k;i++){
		s.insert(i);
	}
	print();
	return 0;
}