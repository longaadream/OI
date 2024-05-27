#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 5e7 + 5, mod = 1e9 + 7;
int n, m;
int a[N];
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

signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	n = read(), m = read();
	clock_t be = clock();
   	for(int i = 1; i <= n; i ++) a[i] = read();
   	std::sort(a + 1, a + n + 1);
   	i64 ans = 0;
   	for(int i = 2*(n - m) + 1; i <= n; i ++){
   		ans += 1ll * a[i] * a[i];
   	}
   	for(int i = 1; i <= (n - m); i ++){
   		ans += 1ll * (a[i] + a[2*(n - m) - i + 1]) * (a[i] + a[2*(n - m) - i + 1]);
   	}
   	std::cout << ans << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}