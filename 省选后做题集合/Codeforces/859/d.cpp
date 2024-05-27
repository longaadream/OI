#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 7, M = 100, mod = 998244353;
const int inf = 1e9;
int n, m;
long double a[M][M], prob[M][N], dp[M][N];
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
		n = read(); m = (1 << n);
		for(int i = 0; i <= m - 1; i ++){
			for(int j =0; j <= m - 1; j ++){
				a[i][j] = 1. * read() / 100;
			}
		}
		long double ans = 0;
		for(int i = 0; i <= m - 1; i ++) prob[i][0] = 1;
		int sd = 0,lst = 0;
		for(int rd = 1; rd <= n; rd ++){
			sd |= (1 << (rd - 1));
			for(int i = 0; i <= m - 1; i ++){
				for(int j = 0; j <= m - 1; j ++){
					if(((i ^ j) | sd) == sd && i != j && ((i ^ j) | lst) != lst) prob[i][rd] += 1. * prob[j][rd - 1] * a[i][j];
				}
				prob[i][rd] *= prob[i][rd - 1];
			}
			for(int i = 0; i <= m - 1; i ++){
				dp[i][rd] = dp[i][rd - 1] + 1. * prob[i][rd] * std::pow(2, rd - 1);
				long double mx = 0;
				for(int j = 0; j <= m - 1; j ++){
					if(((i ^ j) | sd) == sd && i != j && ((i ^ j) | lst) != lst) mx = std::max(mx, dp[j][rd - 1]);
				}
				dp[i][rd] += mx;
			}
			lst = sd;

		}
		for(int i = 0; i <= m - 1; i ++){
			ans = std::max(ans, dp[i][n]);
		}
		std::cout << std::fixed << std::setprecision(9) << ans << endl;
		// for(int rd = 1; rd <= n; rd ++){
		// 	for(int i = 0; i <= m - 1; i ++){
		// 		std::cout << prob[i][rd] << " ";
		// 	}
		// 	putchar(10);
		// }
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}