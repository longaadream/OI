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
int n, m, C[N][N], fac[N];
std::map<int,int> dp[N];
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
signed main() {
	// freopen("soldier.in","r",stdin);
	// freopen("soldier.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	n = read(), m = read();
   	clock_t be = clock();
   	for(int i = 0; i <= n; i ++){
   		C[i][0] = 1;
   		for(int j = 1; j <= i; j ++){
   			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
   		}
   	}	
   	fac[0] = 1;
   	for(int i = 1; i <= n; i ++) fac[i] = 1ll * i * fac[i - 1] % mod;
   	dp[0][1] = 1;
   	for(int i = 0; i < n; i ++){
   		for(pii val : dp[i]){
   			int j = val.first;
   			for(int k = 1; k + i <= n; k ++)
   				dp[i + k][j/std::__gcd(j, k) * k] = (dp[i + k][j/std::__gcd(j, k) * k] + 1ll * dp[i][j] * C[n - i - 1][k - 1] % mod * fac[k - 1] % mod) % mod;		
   		}
   	}
   	i64 ans = 0;
	for(pii val : dp[n]){
		// std::cout << val.first << " " << val.second << endl;
		ans = (ans + 1ll * qpow(val.first, m) * val.second % mod) % mod;
	}	
   	std::cout << ans << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}