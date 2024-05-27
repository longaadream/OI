#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 6e5 + 5, M = 105, mod = 998244353;
const int inf = 1e9;
int n, nodecnt;
struct Tree
{
	int ls, rs, sum;
}tr[N << 2];
i64 ans, pos, neg;
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x = 0,f = 1;char c = getchar();
	while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)){ x = x * 10 + (c ^ 48); c = getchar();}
	return x * f;
}
void modify(int &x, int l, int r, int k){
	if(!x) x = ++nodecnt;
	tr[x].sum ++;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(k <= mid) modify(tr[x].ls, l, mid, k);
	else modify(tr[x].rs, mid + 1, r, k);
}
void merge(int &x, int y, int l, int r){
	if(!x || !y) {x = x + y; return;}
	tr[x].sum += tr[y].sum;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	pos += 1ll * tr[tr[y].rs].sum * tr[tr[x].ls].sum;
	neg += 1ll * tr[tr[x].rs].sum * tr[tr[y].ls].sum;
	merge(tr[x].ls, tr[y].ls, l, mid);
	merge(tr[x].rs, tr[y].rs, mid + 1, r);
}
void dfs(int &x){
	int t = read();
	if(!t){
		int l = 0, r = 0;
		dfs(l);
		dfs(r);
		pos = neg = 0;
		x = l;
		merge(x, r, 1, n);
		ans += std::min(pos, neg);
	}else modify(x, 1, n, t);
}
signed main() {
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
		n = read();
		int rt = 0;
		dfs(rt);
		std::cout << ans << endl;
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}