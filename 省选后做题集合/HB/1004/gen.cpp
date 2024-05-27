#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 13, mod = 998244353, md = 998244352;
int ed[N][N],n,k;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
std::mt19937 rnd(time(0));
signed main() {
	// freopen("ex_B2.in","r",stdin);
	freopen("a.in","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = rnd() % 5 + 1, k = rnd() % (n - 1) + 1;
	std::cout << n << " " << k << endl;
	clock_t be=clock();
	for(int i = 1;i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(i == j) continue;
			std::cout << i << " " << j << " " << rnd() % mod << " " << rnd() % md + 1 << endl;
		}
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}