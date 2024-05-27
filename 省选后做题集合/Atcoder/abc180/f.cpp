#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1005, mod = 1e9 + 7;
int n, m, K, dp[N][N], fac[N], inv[N];
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline int C(int n, int m){
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
	// freopen("soldier.in","r",stdin);
	// freopen("soldier.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	n = read(), m = read(), K = read();
   	clock_t be = clock();
   	fac[0] = 1;
   	for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;  
    inv[n] = qpow(fac[n], mod - 2);
	for(int i = n; i; i --) inv[i - 1] = 1ll * i * inv[i] % mod;
	dp[0][0] = 1;
	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= std::min(i, m); j ++){
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
			for(int k = 2; k <= std::min(n - i, K); k ++){
				dp[i + k][j + k] = (dp[i + k][j + k] + 1ll * dp[i][j] * C(n - i - 1, k - 1) % mod * fac[k - 1] % mod * (k > 2 ? qpow(2, mod - 2) : 1) % mod) % mod;
				dp[i + k][j + k - 1] = (dp[i + k][j + k - 1] + 1ll * dp[i][j] * C(n - i - 1, k - 1) % mod * fac[k] % mod * (k > 2 ? qpow(2, mod - 2) : 1) % mod) % mod;
			}
		}
	}
	int ans1 = dp[n][m];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= std::min(i, m); j ++){
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
			for(int k = 2; k <= std::min(n - i, K - 1); k ++){
				dp[i + k][j + k] = (dp[i + k][j + k] + 1ll * dp[i][j] * C(n - i - 1, k - 1) % mod * fac[k - 1] % mod * (k > 2 ? qpow(2, mod - 2) : 1) % mod) % mod;
				dp[i + k][j + k - 1] = (dp[i + k][j + k - 1] + 1ll * dp[i][j] * C(n - i - 1, k - 1) % mod * fac[k] % mod * (k > 2 ? qpow(2, mod - 2) : 1) % mod) % mod;
			}
		}
	}
	std::cout << (ans1 - dp[n][m] + mod) % mod << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}