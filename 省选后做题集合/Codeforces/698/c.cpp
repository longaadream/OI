#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 25, M = 305, mod = 998244353;
const int inf = 1e9;
int n, k;
long double p[N], dp[1 << (N - 2)], ans[N];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
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
		n = read(), k = read();
		int cnt = 0;
		for(int i = 1; i <= n; i ++) std::cin >> p[i], cnt += p[i] ? 1 : 0;
		if(cnt <= k){
			for(int i = 1; i <= n; i ++){
				std::cout << (p[i] ? "1" : "0") << " ";
			}
			return 0;
		}
		dp[0] = 1;
		for(int bt = 0; bt <= (1 << n) - 1; bt ++){
			long double sum = 0;
			if(__builtin_popcount(bt) > k) continue;
			if(__builtin_popcount(bt) == k){
				for(int i = 1; i <= n; i ++){
					if((1 << (i - 1)) & bt) ans[i] += dp[bt];
				}
			}
			for(int i = 1; i <= n; i ++){
				if((1 << (i - 1)) & bt) sum += p[i];
			}
			sum = 1. / (1. - sum);
			for(int i = 1; i <= n; i ++){
				if(!((1 << (i - 1)) & bt)) dp[bt | (1 << (i - 1))] += 1. * dp[bt] * sum * p[i]; 
			}
		}
		std::cout << std::fixed << std::setprecision(9);
		for(int i = 1; i <= n; i ++){
			std::cout << ans[i] << endl;
		}
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}