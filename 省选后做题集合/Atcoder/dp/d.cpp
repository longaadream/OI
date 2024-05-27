#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 5, inf = 1e9;
i64 n, sum, W, w[N], v[N], dp[N];
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
	n = read(), W = read();
	clock_t be = clock();
	sum = 0;
    for(int i = 1; i <= n; i ++) w[i] = read(), sum += v[i] = read();
    int ans = 0;
    std::memset(dp, 0x7f, sizeof dp);
    dp[0] = 0;
   	for(int j = 1; j <= n; j ++){
   		for(int i = sum - v[i]; ~i; i --){
   			down(dp[i + v[j]], dp[i] + w[j]);
   		}
   	}
   	for(int i = 0; i <= sum; i ++){if(dp[i] <= W) up(ans, i);}
   	std::cout << ans << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}