#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=5e3 + 5, mod = 998244353;
int n, m, a[N], res = 1;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = 1ll * res * a % mod;
		}
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
int _gcd(int a, int b){
	return b ? _gcd(b, a % b) : a;
}
void dfs(int x){
	if(x == n){
		int gcd = a[1], lcm = a[1];
		for(int i = 1; i <= n; i ++){
			// std::cout << a[i] << " ";
			gcd = _gcd(a[i], gcd); lcm = (lcm * a[i]) / gcd;
		}
		// std::cout << "gcd:" << gcd << "lcm:" << lcm << endl;
		res = 1ll * res * qpow(lcm, gcd) % mod;
		return ;
	}
	for(int i = 1; i <= m; i ++){
		a[x + 1] = i;
		dfs(x + 1);
	}
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), m = read();
	clock_t be=clock();
	dfs(0);
	std::cout << res << endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}