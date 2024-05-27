#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 105, M = 20005, mod = 998244353;
int dp[M];
int a[N][N];
int n, m, s;
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	freopen("soldier.in","r",stdin);
	freopen("soldier.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	s = read(), n = read(), m = read();
   	clock_t be = clock();
   	for(int i = 1; i <= s; i ++){
   		for(int j = 1; j <= n; j ++){
   			a[j][i] = read();
   		}
   	}
   	for(int i = 1; i <= n; i ++) std::sort(a[i] + 1, a[i] + s + 1);
   	for(int i = 1; i <= n; i ++){
   		for(int j = m; ~j; j --){
   			for(int k = 1; k <= s; k ++){
   				if(j > 2 * a[i][k]){
   					dp[j] = std::max(dp[j], dp[j - 2 * a[i][k] - 1] + k * i);
   				}
   			}
   		}
   	}
   	for(int i = 1; i <= m; i ++){
   		dp[0] = std::max(dp[0], dp[i]);
   	}
   	std::cout << dp[0] << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}