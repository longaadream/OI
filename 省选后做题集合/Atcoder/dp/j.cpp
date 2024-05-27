#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 305, inf = 1e9, half = 4e3;
int n;
long double dp[N][N][N];
bool vis[N][N][N];
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
long double dfs(int i, int j, int k){
	if(i == 0 && j == 0 && k == 0) return 0.00;
	if(i < 0 || j < 0 || k < 0) return 0.00;
	// std::cout << i << ' ' << j << ' ' << k << endl;
	if(dp[i][j][k] != 0.00) return dp[i][j][k];
	return dp[i][j][k] = 1. * n/(i + j + k) + 1. * (1. * i * dfs(i - 1, j, k) + 1. * j * dfs(i + 1, j - 1, k) + 1. * k * dfs(i, j + 1, k - 1))/(i + j + k);
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read();
	clock_t be = clock();
	int tot[4] = {0, 0, 0, 0};
	for(int i = 1; i <= n; i ++){int t = read();tot[t] ++;}
	dp[0][0][0] = 0;
	std::cout << std::fixed << std::setprecision(9) << dfs(tot[1], tot[2], tot[3]) << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}