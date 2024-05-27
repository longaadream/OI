#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 3e5 + 5, M = 70, inf = 0x7fffffff;
int n, m;
pii a[N];
struct Query{
	int l, r;
}q[N];
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
int dis(pii a, pii b){
	return std::max(std::abs(a.first - b.first), std::abs(a.second - b.second));
}
namespace Subtask1{
	void solve(){

	}
}
namespace Subtask2{
	void solve(){
		for(int d = 1; d <= m; d ++){
			int mx = 0;
			int l = q[d].l, r = q[d].r;
			for(int i = l; i <= r; i ++){
				int mn = 1e9;
				for(int j = l; j <= r; j ++){
					for(int k = j + 1; k <= r; k ++){
						if(j == i || k == i) continue;
						mn = std::min(mn, dis(a[j], a[k]));
					}
				}
				mx = std::max(mx, mn);
			}
			std::cout << mx << endl;
		}
	}	
}
signed main() {
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	int tt = 1;
   	while(tt --){
	   	int flg = 1;
	   	n = read();
	   	for(int i = 1; i <= n; i ++) {a[i].first = read(), a[i].second = read(); if(a[i].first <= a[i - 1].first || a[i].second <= a[i - 1].second) flg = 0;}
	   	m = read();
	   	for(int i = 1; i <= m; i ++){q[i].l = read(), q[i].r = read();}
	   	Subtask2::solve();
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}