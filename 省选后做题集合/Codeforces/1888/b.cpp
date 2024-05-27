#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5, M = 30, mod = 1e9 + 7, inf = 0x7fffffff;
int n, k, a[N];
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
		n = read(), k = read();
		int mn = 1e9;
		if(k == 4){
			for(int i = 1; i <= n; i ++){
				a[i] = read();
				a[i] %= k;
				if(a[i] == 0) mn = 0;
				mn = std::min(mn, k - a[i]);
			}	
			int num2 = 0, num1 = 0;
			for(int i = 1; i <= n; i ++){
				num2 += a[i] == 2, num1 += a[i] == 1;
			}
			if(num2 >= 2){
				mn = 0;
			}
			if(num2 && num1){
				mn = std::min(mn, 1);
			}
			if(num1 >= 2){
				mn = std::min(mn, 2);
			}
		}else{
			for(int i = 1; i <= n; i ++){
				int t = read();
				t %= k;
				if(t == 0) mn = 0;
				mn = std::min(mn, k - t);
			}
		}
		std::cout << mn << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}