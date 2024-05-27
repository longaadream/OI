#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
// using i128=__int128;
bool Mbe;
const int N = 1e6+5, mod = 998244353;
int a[N],b[N];
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
		if(b&1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    // int tt = read();
	clock_t be = clock();
    // while(tt --){
    	int n = read();
    	for(int i = 1; i <= n; i ++) a[i] = read();
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i; j <= n; j +=i) b[i] = std::max(b[i], a[j]);
    	}
    	std::sort(b + 1, b + n + 1);
    	i64 sum = 0;
    	for(int i = 1; i <= n; i ++) sum = (sum + 1ll * b[i] * qpow(2, i - 1) % mod) % mod;
    	std::cout << sum << endl;
    // }
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}