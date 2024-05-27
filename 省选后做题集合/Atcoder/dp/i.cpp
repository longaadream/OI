#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 8e4 + 5, inf = 1e9, half = 4e3;
int n, sum, W;
long double p[N], dp[N][2];
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
inline int id(int x){return x + half;}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read();
	clock_t be = clock();
	for(int i = 1; i <= n; i ++) std::cin >> p[i];
    dp[id(0)][0] = 1.00;
	for(int i = 1; i <= n; i ++){
		for(int j = -n; j <= n; j ++){
			dp[id(j)][i & 1] += 1. * dp[id(j + 1)][1 ^ (i & 1)] * (1. - p[i]);
		}
		for(int j = n; j >= -n; j --){
			dp[id(j)][i & 1] += 1. * dp[id(j - 1)][1 ^ (i & 1)] * p[i]; 
			// std::cout << i << " " << j << " " << std::fixed << std::setprecision(9) << dp[id(j)][n & 1] << endl;
		}
		for(int j = n; j >= -n; j --) dp[id(j)][1 ^ (i & 1)] = 0;
	}	
	long double ans = 0;
	for(int i = 1; i <= n; i ++){
		ans += dp[id(i)][n & 1];
	}
	std::cout << std::fixed << std::setprecision(9) << ans << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}