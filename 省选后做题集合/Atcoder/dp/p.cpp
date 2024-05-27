#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 5, inf = 1e9, mod = 1e9 + 7;
i64 n, dp[N][2];
std::vector<int> E[N];
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
void dfs(int u, int f){
	dp[u][1] = dp[u][0] = 1;
	for(int v:E[u]){
		if(v == f) continue;
		dfs(v, u);
		dp[u][0] *= (dp[v][0] + dp[v][1]) % mod;
		Mod(dp[u][0]);
		dp[u][1] *= (dp[v][0]) % mod;
		Mod(dp[u][1]);
	}
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read();
	if(n == 1) return std::cout << 2 << endl, 0;
	clock_t be = clock();
	for(int i = 1; i < n; i ++){
		int x = read(), y = read();
		E[x].push_back(y), E[y].push_back(x);
	}
	dfs(1, 1);
	// std::cout << dp[2][1] << " " << dp[2][0] << endl;
	std::cout << (dp[1][1] + dp[1][0]) % mod << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}