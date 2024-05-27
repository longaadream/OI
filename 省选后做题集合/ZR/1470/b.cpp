#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 5e3 + 4, M = 26;
const i64 inf = 1e18;
int n, m, a[N], A, B, k;
i64 dp[N][N];
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("ex_buy2.in","r",stdin);
	// freopen("buy.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	int tt = 1;
   	while(tt --){
		n = read(), k = read(), A = read(), B = read();
		for(int i = 1; i <= n; i ++) a[i] = read();
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= k; j ++) dp[i][j] = inf;
		}
		dp[0][0] = 0;
		for(int i = 1; i <= n; i ++){
			dp[i][0] = dp[i - 1][0] + a[i];
			for(int j = 1; j < k; j ++){
				dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j] + 1ll * std::min(j, k - j) * B + a[i]);
			}
			for(int j = 0; j < k; j ++){
				dp[i][j] = std::min(dp[i][j], dp[i - 1][k - 1] + A);
			}
		}
		std::cout << dp[n][0] << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}