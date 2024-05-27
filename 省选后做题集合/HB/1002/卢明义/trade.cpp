#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 5e5 + 10,mod = 998244353;
int n,a[N], ans, b[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
void dfs(int x){
	if(x == n){
		int mul = 1;
		for(int i = 1; i <= n; i ++){
			mul = 1ll * mul * b[i] % mod;
		}
		ans += mul;
		return ;
	}
	for(int i = 0; i <= a[i]; i ++){
		b[x] -= i, b[x % mod + 1] += i;
		dfs(x + 1);
		b[x] += i, b[x % mod + 1] -= i; 
	}
}
signed main() {
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read();
	clock_t be=clock();
	for(int i = 1; i <= n; i ++) a[i] = b[i] = read();
	dfs(1);
	std::cout << ans << endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}