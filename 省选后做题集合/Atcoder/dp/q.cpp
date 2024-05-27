#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
bool Mbe;
const int N = 2e5 + 5, inf = 1e9, mod = 1e9 + 7;
int n, h[N];
struct BIT{
	i64 tr[N << 1];
	#define lowbit(x) x&(-x)
	void modify(int x, i64 det){
		while(x <= n){
			up(tr[x], det);
			x += lowbit(x);
		}
	}
	i64 query(int x){
		i64 res = 0;
		while(x){
			up(res, tr[x]);
			x -= lowbit(x);
		}
		return res;
	}
}T;
bool Med;
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
	n = read();
	clock_t be = clock();
	for(int i = 1; i <= n; i ++) h[i] = read();
	for(int i = 1; i <= n ;i ++){
		T.modify(h[i], T.query(h[i] - 1) + read());
	}
	std::cout << T.query(n) << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}