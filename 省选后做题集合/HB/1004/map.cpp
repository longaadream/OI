#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 12, mod = 998244353;
int mp[N][N], n, k, f[1 << N][1 << N], g[1 << N][1 << N], trans[1 << N][1 << N],undo[1 << N][1 << N];
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

signed main() {
	freopen("a.in","r",stdin);
	// freopen("b.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), k = read();
	clock_t be=clock();
	for(int i = 1; i <= n*(n - 1); i ++) {
		int x = read() - 1, y = read() - 1, p = read(); mp[x][y] = 1ll * p * qpow(read(), mod - 2) % mod;
	}
	int full = (1 << n) - 1;
	for(int bt1 = 0; bt1 <= full; bt1 ++){
		int req = full ^ bt1;
		for(int bt2 = req; bt2; bt2 = (bt2 - 1) & req){
			trans[bt1][bt2] = undo[bt1][bt2] = 1;
			for(int i = 0; i < n; i ++){
				if(!(bt2 & (1 << i))) continue;
				int mul = 1;
				for(int j = 0; j < n; j ++){
					if(!(bt1 & (1 << j))) continue;
					mul = 1ll * mul * (1 + mod - mp[j][i]) % mod;

					undo[bt1][bt2] = 1ll * undo[bt1][bt2] * (1 + mod - mp[j][i]) % mod;
				}
				trans[bt1][bt2] = 1ll * trans[bt1][bt2] * (1 + mod - mul) % mod;
			}
		}
	}
	for(int bt = 0; bt <= full; bt ++) undo[bt][0] = 1, trans[bt][0] = 1, trans[0][bt] = 0;
	f[1][1] = 1;
	int ans = 0;
	for(int i = 0; i < k; i ++){
		for(int bt = 0; bt <= full; bt ++){
			for(int ss = bt; ss; ss = (ss - 1) & bt){
				g[bt][ss] = 0;
			}
		}
		for(int bt = 0; bt <= full; bt ++){
			for(int ss = bt; ss; ss = (ss - 1) & bt){
				int req = full ^ bt;
				for(int s = req; s; s = (s - 1) & bt){
					g[bt | s][s] = (g[bt | s][s] + 1ll * f[bt][ss] * trans[ss][s] % mod * undo[ss][req ^ s] % mod) % mod;	
				}
			}
		}
		for(int bt = 0; bt <= full; bt ++){
			for(int ss = bt; ss; ss = (ss - 1) & bt){
				f[bt][ss] = g[bt][ss];
			}
		}
		for(int ss = 0; ss <= full; ss ++){
			ans = (ans + f[full][ss]) % mod;
		}
	}
	std::cout << ans << endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}