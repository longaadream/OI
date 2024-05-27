#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1005, M = 105, mod = 998244353;
const int inf = 1e9;
int n, m;
std::vector<int> dep[N];
int dp[M][N];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x = 0,f = 1;char c = getchar();
	while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)){ x = x * 10 + (c ^ 48); c = getchar();}
	return x * f;
}
signed main() {
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
		n = read(); m = read();
		for(int i = 1;i <= n; i ++){
			int t = read(), q = read();
			dep[m - t].push_back(q);
		}
		for(int i = 0; i <= m; i ++){
			std::sort(dep[i].begin(), dep[i].end(), std::greater<int>());
			for(int j = 1; j < dep[i].size(); j ++){
				dep[i][j] += dep[i][j - 1];
			}
		}
		for(int i = m + 1; i; i --){
			for(int j = 0; j <= n; j ++){
				dp[i - 1][(j + 1)/2] = std::max(dp[i - 1][(j + 1)/2], dp[i][j]);
				for(int k = 1; k <= (int)dep[i - 1].size(); k ++){	
					dp[i - 1][(j + 1)/2 + k] = std::max(dp[i - 1][(j + 1)/2 + k], dp[i][j] + dep[i - 1][k - 1]);
				}
			}
		}
		std::cout << dp[0][1] << endl;
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}