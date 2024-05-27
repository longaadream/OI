#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=2e2+5,inf=1e9;
int n,a[N],p[N];
char s[N];
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10u+(c^48);c=getchar();}
	return x*f;
}
struct del_heap
{
	std::priority_queue<int> a,b;
	void emplace(int x) {a.emplace(x);}
	void del(int x) {b.emplace(x);}
	void maintain() {for(; a.top()==b.top(); a.pop(),b.pop());}
	void pop() {maintain(),a.pop();}
	int top() {maintain();return a.top();}
};
signed main(){
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	clock_t be=clock();
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}