#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 5;
int n, mod, dp[N], redp[N];
std::vector<int> E[N], pre[N], suf[N];
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
void dfs(int u, int f){
	dp[u] = 1;
	for(int v:E[u]){
		if(v == f) continue;
		dfs(v, u);
		dp[u] = 1ll * dp[u] * (dp[v] + 1) % mod;
	}
}
void redfs(int u,int f){
	if(u == 1) redp[u] = dp[u];
	int prod = 1;
	pre[u].push_back(1);
	for(int v:E[u]){
		if(v == f) continue;
		prod = 1ll * prod * (dp[v] + 1) % mod;
		pre[u].push_back(prod);
	}
	std::reverse(E[u].begin(),E[u].end());
	prod = 1;
	suf[u].push_back(1);
	for(int v:E[u]){
		if(v == f) continue;
		prod = 1ll * prod * (dp[v] + 1) % mod;
		suf[u].push_back(prod);
	}
	std::reverse(suf[u].begin(), suf[u].end());
	std::reverse(E[u].begin(), E[u].end());
	int i = 1;
	for(int v:E[u]){
		if(v == f) continue;
		redp[v] = 1ll * dp[v] * (1ll * pre[u][i - 1] * suf[u][i + 1] % mod + 1) % mod;
		redfs(v, u);
		++ i;
	}

}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	n = read(), mod = read();
   	clock_t be = clock();
   	for(int i = 1; i < n; i ++) {int x = read(), y = read(); E[x].push_back(y), E[y].push_back(x);}
    dfs(1, 1);
	redfs(1, 1);	
	for(int i = 1; i <= n; i ++) std::cout << redp[i] << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}