#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 17,M = 5e7 + 5, mod = 1e9 + 7;
i64 dp[M][2];
int a[N][N], n, full;
i64 cost[M];
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}

signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	n = read(), full = (1 << n) - 1; 
	clock_t be = clock();
    for(int i = 1; i <= n; i ++){
    	for(int j = 1; j <= n; j ++){
    		a[i][j] = read();
    	}
    }
    for(int bt = 0; bt <= full; bt ++){
    	for(int i = 1; i <= n; i ++){
    		for(int j = i + 1; j <= n; j ++){
    			if(((1 << (i - 1)) & bt) && ((1 << (j - 1)) & bt)){
    				cost[bt] += a[i][j];
    			}
    		}
    	}
    }
    for(int i = 1; i <= n; i ++){
    	for(int bt = 0; bt <= full; bt ++){
    		for(int ss = bt; ss; ss = (ss - 1) & bt){
    			up(dp[bt][i & 1], dp[bt ^ ss][1 ^ (i & 1)] + cost[ss]);
    		}
    	}
    }
    std::cout << dp[full][n & 1] << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}