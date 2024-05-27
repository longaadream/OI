#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 3e5 + 5, M = 30, mod = 1e9 + 7;
int n, m, a[N][M], b[M];
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
	// freopen("soldier.in","r",stdin);
	// freopen("soldier.out","w",stdout);
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
	   	i64 ans = 1e18;
	   	for(int i = 1; i <= m; i ++) b[i] = read();
	   	for(int bt = 1; bt <= (1 << m) - 1; bt ++){
	   		i64 res = 0;
	   		for(int i = 1; i <= m; i ++){
	   			if((1 << (i - 1)) & bt) res += b[i];
	   		}
	   		for(int i = 1; i <= n; i ++){
	   			int mn = 1e9;
	   			for(int j = 1; j <= m; j ++){
	   				if((1 << (j - 1)) & bt) down(mn, a[i][j]);
	   			}
	   			res += mn;
	   		}
	   		down(ans, res);
	   	}
	   	std::cout << ans << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}