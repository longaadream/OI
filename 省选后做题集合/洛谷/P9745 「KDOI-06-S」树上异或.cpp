#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 5e5 + 4, M = 26, mod = 998244353;
const i64 inf = 1e18;
int n;
i64 a[N];
int pw[70];
int dp[N][65][2], g[N];
std::vector<int> E[N];
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
void dfs(int u,int f){
	for(int i = 0; i <= 59; i ++){
		dp[u][i][a[u] >> i & 1] = 1;
	}
	for(int v:E[u]){
		if(v == f) continue;
		dfs(v, u);
		for(int i = 0; i <= 59; i ++){
			int i1 = dp[u][i][1], i0 = dp[u][i][0];
			dp[u][i][0] = 1ll * i0 * g[v] % mod;
			dp[u][i][1] = 1ll * i1 * g[v] % mod;
			dp[u][i][1] = (dp[u][i][1] + 1ll * dp[v][i][0] * i1 % mod + 1ll * dp[v][i][1] * i0 % mod) % mod;
			dp[u][i][0] = (dp[u][i][0] + 1ll * dp[v][i][1] * i1 % mod + 1ll * dp[v][i][0] * i0 % mod) % mod;	
		}
	}
	for(int i = 0; i <= 59; i ++){
		g[u] = (g[u] + 1ll * pw[i] * dp[u][i][1] % mod) % mod;
	}
}
signed main() {
	// freopen("ex_buy2.in","r",stdin);
	// freopen("buy.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	int tt = 1;
   	while(tt --){
		n = read();
		for(int i = 1; i <= n; i ++) a[i] = read();
		pw[0] = 1;
		for(int i = 1; i <= 59; i ++){
			pw[i] = 2ll * pw[i - 1] % mod; 
		}
		for(int i = 2; i <= n; i ++){
			int u = read();
			E[i].push_back(u), E[u].push_back(i);
		}
		dfs(1, 0);
		std::cout << g[1] << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}