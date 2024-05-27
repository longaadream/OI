#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5, inf = 1e9;
int n, k, a[N][3], dp[N][3];
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}

signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int n = read();
	clock_t be = clock();
    for(int j = 1; j <= n; j ++){
    	for(int i = 0; i < 3; i ++){
    		a[j][i] = read();
    	}
    }
    for(int i = 1; i <= n; i ++){
    	for(int j = 0; j <= 2; j ++){
    		for(int k = 0; k <= 2; k ++){
    			if(j == k) continue;
    			up(dp[i][j], dp[i - 1][k] + a[i][j]);
    		}
    	}
    }
    std::cout << std::max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}