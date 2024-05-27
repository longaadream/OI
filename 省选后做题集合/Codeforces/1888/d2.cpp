#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5, M = 30, inf = 0x7fffffff;
int n, k, a[N], b[N], m, a1[N];
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
   	int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	while(tt --){
		n = read();m = read();
		for(int i = 2; i <= n; i ++) a1[i] = read();
		for(int i = 1; i <= n; i ++) b[i] = read();
		std::sort(b + 1, b + n + 1);
		i64 sum = 0;
		a[1] = 1;
		for(int i = 2; i <= n; i ++) a[i] = a1[i];
		std::sort(a + 1, a + n + 1);
		int ans = 0;
		for(int i = 1, j = 1; i <= n; i ++){
			while(j <= n && b[j] <= a[i])  ++ j;
			if(j > n) {ans = n - i + 1;break;}
			++ j;
		}	
		int ori = ans;
		int l = 1, r = m, res = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			a[1] = mid;
			for(int i = 2; i <= n; i ++) a[i] = a1[i];
			std::sort(a + 1, a + n + 1);
			int ans = 0;
			for(int i = 1, j = 1; i <= n; i ++){
				while(j <= n && b[j] <= a[i])  ++ j;
				if(j > n) {ans = n - i + 1;break;}
				++ j;
			}	
			if(ans == ori + 1){
				r = mid - 1;
			} else{
				l = mid + 1;
				res = mid;
			}
		}
		std::cout << 1ll * ori * res + 1ll * (m - res) * (ori + 1) << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}