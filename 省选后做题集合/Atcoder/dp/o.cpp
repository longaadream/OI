#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 22, inf = 1e9, M = 3e6 + 5, mod = 1e9 + 7;
i64 n, k, a[N][N], dp[M][2], full;
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), full = (1 << n) - 1;
	clock_t be = clock();
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			a[i][j] = read();
		}
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= full; j ++){
			dp[j][i & 1] = 0;
		}
		for(int j = 1; j <= full; j ++){
			if((__builtin_popcount(j) & 1) != (i & 1)) continue;
			for(int k = 1; k <= n; k ++){
				if( ((1 << (k - 1)) & j) && a[i][k]) dp[j][i & 1] += dp[j ^ (1 << (k - 1))][1 ^ (i & 1)], Mod(dp[j][i & 1]);
			}
		}
	}
	std::cout << dp[full][n & 1] << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}