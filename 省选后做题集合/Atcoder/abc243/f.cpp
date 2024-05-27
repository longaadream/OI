#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 55, mod = 998244353;
int n, m, K, dp[N][N][N], sum, a[N], fac[N], inv[N];
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
template<class T>inline T qpow(T a, T b){T res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
int C(int n,int m){
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	n = read(), K = read(), m = read();
   	clock_t be = clock();
   	fac[0] = 1;
   	for(int i = 1; i <= 50; i ++){
   		fac[i] = 1ll * fac[i - 1] * i % mod; 
   	}
   	inv[50] = qpow(fac[50], mod - 2);
   	for(int i = 50; i; i --){
   		inv[i - 1] = 1ll * inv[i] * i % mod;
   	}
   	for(int i = 1; i <= n; i ++) sum += a[i] = read();
   	sum = qpow(sum, mod - 2);
   	dp[0][0][0] = 1;
   	for(int i = 1; i <= n; i ++){
   		dp[i][0][0] = 1;
   		for(int j = 1; j <= m; j ++){
   			for(int k = 1; k <= std::min(i, K); k ++){
   				dp[i][j][k] = dp[i - 1][j][k];
   				for(int l = 1; l <= j; l ++){
   					// std::cout << 1ll * dp[i - 1][j - l][k - 1]
   					// * qpow(1ll * a[i] * sum % mod,1ll * l) % mod * C(j, l) % mod
   					// << i - 1 << j - l << k - 1
   					 // << endl;
   					dp[i][j][k] = (dp[i][j][k] + 1ll * dp[i - 1][j - l][k - 1] * qpow(1ll * a[i] * sum % mod,1ll * l) % mod * C(j, l) % mod) % mod;
   				}
   			}
   		}
   	}
   	std::cout << dp[n][m][K] << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}