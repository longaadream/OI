#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e6 + 5;
i64 a[N], buk[N], n, d[N], tot;
bool Med;
std::mt19937 rnd(time(0));
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
   	n = read();
   	clock_t be = clock();
   	for(int i = 1; i <= n; i ++) a[i] = read();
   	i64 ans = 1;
   	for(int times = 10; times; times --){
		i64 x = a[rnd() % n + 1];
		tot = 0;   
		for(i64 i = 1; 1ll * i * i <= x; i ++){
			if(x % i == 0){
				d[++tot] = i, buk[tot] = 0;
				if(x / i != i) d[++tot] = x / i, buk[tot] = 0;
			}
		}		
		std::sort(d + 1, d + tot + 1);
		for(int i = 1; i <= n; i ++) buk[std::lower_bound(d + 1, d + tot + 1, std::__gcd(x, a[i])) - d] ++;
		for(int i = 1; i <= tot; i ++){
			for(int j = i + 1; j <= tot; j ++){
				if(d[j] % d[i] == 0){
					buk[i] += buk[j];
				}
			}
		}
		for(int i = 1; i <= tot; i ++){
			if(2 * buk[i] >= n){
				up(ans, d[i]);
			}
		}
   	}
   	std::cout << ans << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}