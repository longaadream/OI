#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 1e5 + 5;
int a[N], n, Q, lst[N], pre[N];
struct tr{
	pii l,r;
	int mx;
	tr operator+(const tr &rhs) const{
		tr ret;
		if(rhs.mx == 0) return *this;
		if(mx == 0) return rhs;
		ret.l = l,ret.r = rhs.r;
		if(l.first == r.first && r.first == rhs.l.first) {ret.l.second = l.second + rhs.l.second;}
		if(r.first == rhs.l.first && rhs.l.first == rhs.r.first){ret.r.second = rhs.r.second + r.second;}
		if(r.first == rhs.l.first){
			ret.mx = std::max(mx, r.second + rhs.l.second);
		}
		ret.mx = std::max({mx, rhs.mx, ret.l.second,ret.r.second});
		return ret;
	}
}T[N<<2];
void emptize(tr &x){
	x.l = std::make_pair(0, 0);
	x.r = std::make_pair(0, 0);
	x.mx = 0;
}
void build(int x, int l,int r){
	if(l == r){
		T[x].l = std::make_pair(a[l], 1);
		T[x].r = std::make_pair(a[r], 1);
		T[x].mx = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	T[x] = T[x << 1] + T[x << 1 | 1];
}
tr query(int x,int l,int r,int ll,int rr){
	if(l >= ll && r <= rr){
		return T[x];
	}
	int mid = (l + r) >> 1;
	tr res;
	emptize(res);
	if(mid >= ll) res = res + query(x << 1, l, mid, ll, rr);
	if(mid + 1 <= rr) res = res + query(x << 1 | 1, mid + 1, r, ll, rr);
	return res; 
}
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	freopen("ex_B2.in","r",stdin);
	freopen("b.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read();
	clock_t be=clock();
	for(int i = 1; i <= n; i ++) {lst[i] = i,a[i] = read(); if(a[i] == a[i - 1]) lst[i] = lst[i - 1];}
	for(int i = n; i; i --){pre[i] = i; if(a[i] == a[i + 1]) pre[i] = pre[i + 1];}
	build(1, 1, n);
	Q = read();
	// std::cout << query(1, 1, n, 2, 2).r.first << query(1, 1, n, 3, 3).l.first << endl;
	while(Q --){
		int l = read(), r = read();
		if(a[l] == a[r]){
			std::cout << "0" << endl;
			continue;
		}
		std::cout << a[r] - a[l] + std::max(query(1, 1, n, l, lst[r]).mx - 1, 0) << endl;
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}