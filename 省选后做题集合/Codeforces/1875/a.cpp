#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N = 105;
int a,b,n,v[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("number.in","r",stdin);
	// freopen("number.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt = read();
	clock_t be=clock();
	while(tt --){
		a = read(), b = read(), n = read();
		i64 ans = b;
		for(int i = 1; i <= n; i ++) {int t = read(); ans += std::min(a - 1, t);}
		std::cout << ans << endl;
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}