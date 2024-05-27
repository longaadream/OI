#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 3e3 + 5, mod = 1e9 + 7;
i64 dp[N][N];
int n;
char s[N];
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
	n = read();
	clock_t be = clock();
    scanf("%s", s + 2);
    dp[1][1] = 1;
    for(int i = 2; i <= n; i ++){
    	for(int j = 1; j <= i; j ++){
    		if(s[i] == '<') dp[i][j] += dp[i - 1][j - 1], Mod(dp[i][j]); else dp[i][j] += (dp[i - 1][i - 1] - dp[i - 1][j - 1] + mod) % mod, Mod(dp[i][j]);
    	}
    	for(int j = 1; j <= i; j ++) dp[i][j] += dp[i][j - 1], Mod(dp[i][j]);
    }
	std::cout << dp[n][n] << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}