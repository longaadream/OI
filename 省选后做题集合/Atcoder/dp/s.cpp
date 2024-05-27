#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e4 + 5, mod = 1e9 + 7;
char s[N];
i64 dp[N][105][2];
int n, k, ori[N];
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
i64 dfs(int x, int m, int lim){
	int mxdigit = lim ? ori[x] : 9;
	if(x > n) return !m;
	if(~dp[x][m][lim]) return dp[x][m][lim];
	i64 res = 0;
	for(int i = 0; i <= mxdigit; i ++){
		res += dfs(x + 1, (m + i) % k, lim && (i == mxdigit)) % mod;
		Mod(res);
	}	
	return dp[x][m][lim] = res;
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	clock_t be = clock();
    scanf("%s", s + 1);
    k = read();
    n = strlen(s + 1);
    for(int i = 1; i <= n; i ++){
    	ori[i] = s[i] - '0';
    }
    memset(dp, -1, sizeof dp);
    std::cout << (dfs(0, 0, 1) - 1 + mod) % mod<< endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}