#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 5;
int n, q;
int a[N], pre[N];
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
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
   	n = read(), q = read();
   	clock_t be = clock();
   	for(int i = 1; i <= n; i ++) a[i] = read();
    std::sort(a + 1, a + n + 1); 
	for(int i = 1; i <= n; i ++){
		a[i] -= (i - 1);
	}
	pre[1] = a[1];
	for(int i = 2;i <= n; i ++){
		pre[i] = std::min(pre[i - 1], a[i]);
	}
	while(q --){
		
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}