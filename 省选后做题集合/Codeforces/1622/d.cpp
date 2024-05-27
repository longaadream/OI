#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 5005, M = 305, mod = 998244353;
const int inf = 1e9;
int n, k, a[N], fac[N], inv[N], tot;
std::string s;
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x = 0,f = 1;char c = getchar();
	while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)){ x = x * 10 + (c ^ 48); c = getchar();}
	return x * f;
}
inline int C(int n, int m){
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
		n = read(), k = read();
		fac[0] = 1;
		for(int i = 1; i <= n + 2; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[n + 2] = qpow(fac[n + 2], mod - 2);
		for(int i = n + 2; i; i --) inv[i - 1] = 1ll * inv[i] * i % mod;
		std::cin >> s;
		a[++ tot] = 0;
		for(int i = 0; i < (int)s.size(); i ++) if(s[i] == '1'){a[++ tot] = i + 1;}
		a[++ tot] = n + 1;
		int ans = 1;
		if(tot <= k + 1) return std::cout << 1 << endl, 0;
		for(int i = k + 1; i <= tot; i ++){
			ans = (ans + C(a[i] - a[i - k - 1] - 1, k)) % mod;
			if(i != tot) ans = (ans + mod - C(a[i] - a[i - k] - 1, k - 1)) % mod;
		}
		if(k == 0) std::cout << 1 << endl; else
		std::cout << ans << endl;
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}