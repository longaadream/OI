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
int n, m, p;
int fa[N],siz[N];
bool Med;
inline int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y){x = find(x), y = find(y);if(x == y) return; siz[y] += siz[x], fa[x] = y;}
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = 1ll * res * a % p;
		}
		a = 1ll * a * a % p;
		b >>= 1;
	}
	return res;
}
signed main() {
	// freopen("book.in","r",stdin);
	// freopen("book.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(),m = read(), p = read();
	clock_t be=clock();
	if(p == 1) return puts("0"), 0;
	for(int i = 1; i <= n; i ++) fa[i] = i, siz[i] = 1;
	for(int i = 1; i <= m; i ++){
		int x = read(), y = read(); merge(x, y);
	}
	int ans = 1, k = 0;
	for(int i = 1; i <= n; i ++){
		if(fa[i] == i) ans = 1ll * ans * siz[i] % p, k ++;
	}
	if(k == 1) return puts("1"), 0;
	ans = 1ll * ans * qpow(n, k - 2) % p;
	std::cout << ans << endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}