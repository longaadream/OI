#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 5e5 + 5, M = 20005, mod = 1e9 + 7, i100 = 570000004;
int a[N], b[N], n, f, g;
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
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	n = read();
   	clock_t be = clock();
   	for(int i = 1; i <= n; i ++){
   		a[i] = 1ll * read() * i100 % mod, b[i] = 1ll * read() * i100 % mod;
   	}
   	f = 1, g = 0;
   	for(int i = 1; i <= n; i ++){
   		int loop = qpow((1 - 1ll * g * b[i] % mod + mod) % mod , mod - 2);
   		f = 1ll * f * a[i] % mod * loop % mod;
   		g = (1ll * g * a[i] % mod * a[i] % mod * loop % mod + b[i]) % mod;
   	}
   	std::cout << f << endl; 
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}