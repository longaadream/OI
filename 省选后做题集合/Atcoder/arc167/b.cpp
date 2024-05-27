#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 5e7 + 5, mod = 998244353;
i64 n, m, b;
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
int qpow(int a, int b){
	int ans = 1;
	while(b){
		if(b & 1){
			ans = 1ll * ans * a % mod;
		}
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return ans;
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	n = read(), b = m = read(); m %= mod;
	clock_t be = clock();
   	i64 res = n;
   	int ans = 1;
   	int odd = 1;
   	for(int i = 2; 1ll * i * i<= n; i ++){
   		if(res % i == 0){
   			int tmp = 0;
   			while(res % i == 0){
   				res /= i; tmp ++;
   			}
   			if(tmp & 1) odd = 0;
   			ans = 1ll * ans * (1ll * m * tmp % mod + 1) % mod;
   		}
   	}
   	if(res != 1) ans = 1ll * ans * (m + 1) % mod, odd = 0;
   	ans = 1ll * ans * m % mod;
   	if(odd && b & 1) ans = (ans + mod - 1) % mod;
   	std::cout << 1ll * ans * qpow(2, mod - 2) % mod << endl;

    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}