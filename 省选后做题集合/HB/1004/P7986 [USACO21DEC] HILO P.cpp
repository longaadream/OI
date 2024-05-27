#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 5005, mod = 1e9 + 7;
int f[N][N][2], n, x;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("a.in","r",stdin);
	// freopen("b.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), x = read();
	clock_t be=clock();
	f[0][0][0] = f[0][0][1] = 1;
	for(int i = 1; i <= n; i ++){
		
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}