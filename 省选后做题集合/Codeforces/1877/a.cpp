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
        int n = read(), sum = 0;
        for(int i = 1; i <= n - 1; i ++){int t = read(); sum += t;} 
        std::cout << 0 - sum << endl;
    }
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}