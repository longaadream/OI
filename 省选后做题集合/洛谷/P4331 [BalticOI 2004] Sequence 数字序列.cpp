#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e6+5;
int n, a[N], b[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("ring.in","r",stdin);
	// freopen("ring.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int n = read();
	clock_t be=clock();
	for(int i = 1; i <= n; i ++) {
		a[i] = read() - i;
	}
	std::priority_queue<int> slope;int k = 0;
	for(int i = 1; i <= n; i ++) {
		k -= 1;
		slope.push(a[i]), slope.push(a[i]);
		while(k + (int)slope.size() > 0) slope.pop();
		b[i] = slope.top();
	}
	for(int i = n - 1; i; i --) {
		b[i] = std::min(b[i + 1], b[i]);
	}
	i64 ans = 0;
	for(int i = 1; i <= n; i++){
		ans += abs(a[i] - b[i]);
	}
	std::cout<< ans << endl;
	for(int i = 1; i <= n; i ++) {
		std::cout << b[i] + i << " ";
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}