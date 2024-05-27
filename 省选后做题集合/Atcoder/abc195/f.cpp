#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 4, M = 2e6 + 5, mod = 998244353;
const i64 inf = 1e18;
i64 l, r, isp[N], dp[M], p[N], cnt;  
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("P6329_1.in","r",stdin);
	// freopen("P6329.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
		l = read(), r = read();
		for(int i = 2; i <= r - l + 1; i ++){
			int flg = 1;
			for(int j = 2; j * j <= i; j ++){
				if(i % j == 0) flg = 0;
			}
			if(flg) p[++cnt] = i;
		}
		dp[0] = 1;
		for(i64 i = l; i <= r; i ++){
			int msk = 0;
			for(int j = 1; j <= cnt; j ++){
				if(i % p[j] == 0) msk |= (1 << (j - 1));
			}
			for(int bt = 0; bt <= (1 << cnt) - 1; bt ++){
				if(!(bt & msk)){
					dp[bt | msk] += dp[bt];
				}
			}
		}
		i64 ans = 0;
		for(int bt = 0; bt <= (1 << cnt) - 1; bt ++) ans += dp[bt];
		std::cout << ans << endl;
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}