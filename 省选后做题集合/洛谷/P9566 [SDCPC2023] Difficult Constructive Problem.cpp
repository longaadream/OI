#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 4, M = 2e6 + 5, mod = 998244353;
const i64 inf = 1e18;
int l[N][2], r[N][2], n, m, ans[N];
char s[N];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline bool chk(int i, int j){
	return s[i] == '?' || s[i] == j + '0';
}
signed main() {
	// freopen("P6329_1.in","r",stdin);
	// freopen("P6329.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	int tt = read();
   	clock_t be = clock();
   	// int tt = 1;
   	while(tt --){
		n = read(), m = read();
		memset(ans, -1, sizeof ans);
		memset(l, 0x3f, sizeof l);
		memset(r, -0x3f, sizeof r);
		std::cin >> (s + 1);
		for(int i = 0; i <= 1; i ++){
			if(chk(n, i)) {
				l[n][i] = r[n][i] = 0;
			}
		}
		for(int i = n - 1; i; i --){
			for(int j = 0; j <= 1; j ++){
				if(chk(i, j)){
					l[i][j] = std::min(l[i + 1][j], l[i + 1][j ^ 1] + 1);
					r[i][j] = std::max(r[i + 1][j], r[i + 1][j ^ 1] + 1);
				}
			}
		}
		int cur = 0;
		int flg = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= 1; j ++){
				if(chk(i, j)){
					if(i > 1) cur += j != ans[i - 1];
					if(l[i][j] + cur <= m && r[i][j] + cur >= m &&( (m - l[i][j] - cur) % 2 == 0 || s[n] == '?') ) {ans[i] = j; break;}
					if(i > 1) cur -= j != ans[i - 1];
				}
			}
			if(ans[i] == -1){
				flg = 0;
			}
		}
		if(!flg){
			std::cout << "Impossible" << endl;
		}else{
			for(int i = 1; i <= n; i++){
				std::cout << ans[i];
			}
			puts("");
		}
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}