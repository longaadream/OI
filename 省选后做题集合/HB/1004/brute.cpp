#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 13, mod = 998244353, md = 998244352;
int ed[N][N],n,k;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
int qpow(int x, int y){
	int res = 1;
	while(y){
		if(y & 1) {
			res = 1ll * res * x % mod;
		}
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}
// std::mt19937 rnd(time(0));
signed main() {
	// freopen("ex_B2.in","r",stdin);
	freopen("a.in","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), k = read();
	clock_t be=clock();
	for(int i = 1; i <= n*(n - 1); i ++){
		int x = read(), y = read(), p = read(); ed[x][y] = p * qpow(read(), mod - 2);
	}
	
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}