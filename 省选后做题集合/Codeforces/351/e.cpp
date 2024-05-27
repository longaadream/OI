#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5;
int n, m;
int a[N],l[N],r[N];
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
struct BIT{
	int tr[N << 1];
	#define lowbit(x) x&(-x)
	void modify(int x,int det){
		while(x <= N){
			tr[x] += det;
			x += lowbit(x);
		}
	}
	int query(int x){
		int res = 0;
		while(x){
			res += tr[x];
			x -= lowbit(x);
		}
		return res;
	}
}T[2];
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int n = read();
	clock_t be = clock();
    for(int i = 1; i <= n; i ++) a[i] = std::abs(read()) + 1;
 	for(int i = 1; i <= n; i ++) l[i] = T[0].query(a[i] - 1), T[0].modify(a[i], 1);
   	for(int i = n; i; i--) r[i] = T[1].query(a[i] - 1), T[1].modify(a[i], 1);
   	i64 res = 0;
   	for(int i = 1; i <= n; i ++) res += std::min(l[i], r[i]);
   	std::cout << res << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}