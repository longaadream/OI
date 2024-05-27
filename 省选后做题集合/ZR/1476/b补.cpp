#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 5, M = 26, inf = 0x7fffffff;
int n, m;
i64 a[N][M], b[M];
i64 dp[1 << M], g[1 << M];
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
		n = read(), m = read();
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				a[i][j] = read();
			}
		}
		for(int i = 1; i <= m; i ++)
			g[(1 << (i - 1))] = read();
		for(int i = 1; i <= n; i ++){
			std::vector<pii> v;
			for(int j = 1; j <= m; j ++){
				v.push_back(std::make_pair(a[i][j], j));
			}
			std::sort(v.begin(), v.end());
			int ori = (1 << (v[0].second - 1));
			dp[0] += v[0].first;
			for(int j = 1; j < m; j ++){
				dp[ori] += v[j].first - v[j - 1].first;
				ori |= (1 << (v[j].second - 1));
			}
		}
		for(int i = 0; i < m; i ++){
			for(int bt = 0; bt < (1 << m); bt ++){
				if((1 << i) & bt){
					dp[bt] += dp[bt ^ (1 << i)];
					g[bt] += g[bt ^ (1 << i)];
				}
			}
		}
		i64 mn = 1e18;
		for(int bt = 0; bt < (1 << m) - 1; bt ++){
			// std::cout << bt << " " << dp[bt] << " " << g[((1 << m) - 1) ^ bt] << endl;
			mn = std::min(mn, dp[bt] + g[((1 << m) - 1) ^ bt]);
		}
		std::cout << mn << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}