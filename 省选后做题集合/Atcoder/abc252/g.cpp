#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 5e3 + 5, mod = 998244353;
int n, q, dp[N][N], a[N];
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	n = read();
   	clock_t be = clock();
   	for(int i = 1; i <= n; i ++) a[i] = read();
   	for(int l = n + 1; l > 1; l --){
   		dp[l][l] = 1;
   		for(int r = l + 1; r <= n + 1; r ++){
   			dp[l][r] = dp[l + 1][r];
   			for(int k = l + 1; k < r; k ++){
   				if(a[l] < a[k]) dp[l][r] = (dp[l][r] + 1ll * dp[l + 1][k] * dp[k][r] % mod) % mod;
   			}
   		}
   	}
   	std::cout << dp[2][n + 1] << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}