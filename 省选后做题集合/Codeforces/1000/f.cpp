#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 5e5 + 5, M = 105, mod = 998244353;
const int inf = 1e9;
int a[N], n, m, ans[N], lst[N];
std::vector<pii> q[N];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x = 0,f = 1;char c = getchar();
	while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)){ x = x * 10 + (c ^ 48); c = getchar();}
	return x * f;
}
struct node{
	int val, ori;
	node(){val = inf, ori = 0;}
	node operator +(const node &b) const{
		node c;
		if(val < b.val) c.val = val, c.ori = ori;
		else c.val = b.val, c.ori = b.ori;
		return c;
	}
}tr[N << 2];
void build(int x, int l, int r){
	if(l == r){
		tr[x].val = inf, tr[x].ori = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);build(x << 1 | 1, mid + 1, r);
	tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
void modify(int x, int l, int r, int k, int det, int id){
	if(l == r){
		tr[x].val = det, tr[x].ori = id;
		return ;
	}
	int mid = (l + r) >> 1;
	if(k <= mid) modify(x << 1, l, mid, k, det, id);
	else modify(x << 1 | 1, mid + 1, r, k, det, id);
	tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
node query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr){
		return tr[x];
	}
	int mid = (l + r) >> 1;
	node ret;
	if(ll <= mid) ret = ret + query(x << 1, l, mid, ll, rr);
	if(mid + 1 <= rr) ret = ret + query(x << 1 | 1, mid + 1, r, ll, rr);
	return ret;
}
signed main() {
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	// while(tt --){
		n = read();
		for(int i = 1; i <= n; i ++){
			a[i] = read();
		}
		m = read();
		for(int i = 1; i <= m; i ++){
			int l = read(), r = read();
			q[r].push_back(std::make_pair(l, i));
		}
		for(int i = 1; i <= n; i ++){
			std::sort(q[i].begin(), q[i].end());
		}
		build(1, 1, n);
		for(int i = 1; i <= n; i ++){
			int x = a[i];
			if(lst[x]) modify(1, 1, n, lst[x], inf, 0);
			modify(1, 1, n, i, lst[x], x);
			lst[x] = i;
			for(pii val:q[i]){
				node res = query(1, 1, n, val.first, i);
				ans[val.second] = res.val < val.first ? res.ori : 0;
			}
		}
		for(int i = 1; i <= m; i ++) std::cout << ans[i] << endl;
	// }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}