#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 3e5 + 5, mod = 1e9 + 7;
int n, a[N], lst[N];
i64 dp[N];
std::map<int,int> mxpos[N];
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
   	while(tt --){
	   	n = read();
	   	for(int i = 1; i <= n; i ++) a[i] = read(), lst[i] =  0, dp[i] = 0;
	   	lst[0] = 0;
	   	for(int i = 1; i <= n; i ++){
	   		if(mxpos[i - 1][a[i]]){
	   			lst[i] = mxpos[i - 1][a[i]];
	   			std::swap(mxpos[i], mxpos[lst[i] - 1]);
	   			if(lst[i]) mxpos[i][a[lst[i] - 1]] = lst[i];
	   		}
	   		mxpos[i][a[i]] = i;
	   	}
	   	i64 ans = 0;
	   	for(int i = 1; i <= n; i ++) ans += lst[i] == 0 ? 0 : dp[i] = dp[lst[i]] + 1;
	   	std::cout << ans << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}