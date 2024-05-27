#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5+5;
int n, m, dp[N][2];
pii a[N];
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(std::abs(a) > std::abs(b)) a = b;}

signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    clock_t be = clock();
   	for(int i = 1; i <= 5; i ++){
   		for(int j = 1; j <= 5; j ++){
   			int t = read();
   			if(t == 1) {
   				std::cout << std::abs(i - 3) + std::abs(j - 3) << endl;
   				exit(0);
   			}	
   		}
   	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}