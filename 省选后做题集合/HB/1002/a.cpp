#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 8e5 + 5;
struct node { int w, v, a; }a[N];
int n, m, i, j, k, T, x[N], y[N], f[N], lim, t, W; 
__int128 ans; 
void print(i128 x) { if(x) print(x/10), std::cout << (int)(x%10); }
void ad1(int w, int v) { for(int i=lim; i>=w; --i) f[i]=std::max(f[i], f[i-w]+v); }
void ad2(int w, int v) { for(int i=0; i+w<=lim; ++i) f[i]=std::max(f[i], f[i+w]-v); }
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("book.in","r",stdin);
	// freopen("book.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read();
	clock_t be=clock();
	for(int i=1; i<=n; ++i) a[i].a = read();
	for(int i=1; i<=n; ++i) a[i].w = read(),m = std::max(m, a[i].w);
	for(int i=1; i<=n; ++i) a[i].v = read();  
	std::sort(a+1, a+n+1, [] (node x, node y) { return x.v*y.w>y.v*x.w; }); 
	W = read();
	for(int i=1; i<=n; ++i)
		int t=std::min(x[i]=a[i].a, W/a[i].w); ans=ans+(i128)t*a[i].v, W-=t*a[i].w, x[i]-=t, y[i]+=t; 
	memset(f, 0x80, sizeof(f)); f[0]=0; lim=m*m+W; 
	for(int i=1; i<=n; ++i) {
		for(t=1; t<=x[i]; t<<=1ll) ad1(a[i].w*t, a[i].v*t), x[i]-=t; 
		if(x[i]) ad1(a[i].w*x[i], a[i].v*x[i]); 
	}
	for(int i=1; i<=n; ++i) {
		for(t=1; t<=y[i]; t<<=1ll) ad2(a[i].w*t, a[i].v*t), y[i]-=t; 
		if(y[i]) ad2(a[i].w*y[i], a[i].v*y[i]); 
	}
	i128 res = 0;
	for(int i = 0;i <= W; i ++) res = std::max(res, (i128)f[i]);
	ans += res;
	print(ans);
	puts("");
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}