#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 305, inf = 1e9, M = 1e5 + 5, mod = 1e9 + 7;
i64 n, k, a[N], dp[M][2];
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
	n = read(), k = read();
	clock_t be = clock();
	for(int i = 1; i <= n; i ++) a[i] = read();
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= k; j ++){
			dp[j][i & 1] = dp[j][1 ^ (i & 1)];
			if(j - a[i] > 0) dp[j][i & 1] -= dp[j - a[i] - 1][1 ^ (i & 1)];
			Mod(dp[j][i & 1]);
		}
		for(int j = 1; j <= k; j ++){
			dp[j][i & 1] += dp[j - 1][i & 1];
			Mod(dp[j][i & 1]);
		}
	}
	std::cout << (dp[k][n & 1] + mod) % mod << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}