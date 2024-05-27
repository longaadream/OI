#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 27, M = 105, mod = 998244353;
const int inf = 1e9;
int a[N], n, k;
i64 s;
i64 fac[N];
std::unordered_map<i64,int> mp[30];
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
signed main() {
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
		n = read(), k = read(), s = read();
		fac[0] = 1;
		for(int i = 1; i <= 18; i++){
			fac[i] = 1ll * fac[i - 1] * i;
		}
		for(int i = 1; i <= n; i ++) a[i] = read();
		for(int bt = 0, ed = qpow(3,n/2) - 1; bt <= ed; bt ++){
			int dec = bt, num = 0, flg = 1;
			i64 res = 0;
			for(int i = 1; i <= n/2; i ++){
				int mes = dec % 3;
				if(mes == 2 && a[i] > 18)  flg = 0;
				if(mes == 2 && a[i] <= 18) res += fac[a[i]];
				if(mes == 1) res += a[i];
				dec /= 3;
				num += mes == 2;
			}
			if(num > k || ! flg) continue;
			// std::cout << num << " " << res << endl;
			if(res > s) continue;
			mp[num][res] ++;
		}
		i64 ans = 0;	
		for(int bt = 0, ed = qpow(3,n - n/2) - 1; bt <= ed; bt ++){
			int dec = bt, num = 0, flg = 1;
			i64 res = 0;
			for(int i = n/2 + 1; i <= n; i ++){
				int mes = dec % 3;
				if(mes == 2 && a[i] > 18)  flg = 0;
				if(mes == 2 && a[i] <= 18) res += fac[a[i]];
				if(mes == 1) res += a[i];
				dec /= 3;
				num += mes == 2;
			}
			if(num > k || !flg) continue;
			if(res > s) continue;
			for(int i = k - num; ~i; i --){
				ans += mp[i][s - res];
			}
		}
		std::cout << ans << endl;
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}