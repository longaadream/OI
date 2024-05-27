#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
// using i128=__int128;
bool Mbe;
const int N = 1e6+5, LIM = 1000;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    int tt = read();
	clock_t be = clock();
    while(tt --){
    	int n = read(), m = read(), k = read();
    	int ans2 = std::min(n - 1, m) + m/n;
    	if(k > 3){std::cout << 0 << endl;continue;}
    	if(k == 1) {std::cout << 1 << endl;continue;}
    	if(k == 2) {std::cout << ans2 << endl;continue;}
    	if(k == 3) {std::cout << m - ans2 << endl; continue;}
    }
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}