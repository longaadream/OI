#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 110,  M = 65, mod = 1e9 + 7;
const int inf = 1e9;
std::string dp[N][N][N];
int n, m, k;
int nxt[N];
char a[N], b[N], c[N];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
    i64 x = 0,f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
    while(isdigit(c)){ x = x * 10 + (c ^ 48); c = getchar();}
    return x * f;
}
void KMP(char* t){
	int sz = strlen(t + 1);
	memset(nxt, 0, sizeof nxt);
	for(int i = 2, j = 0; i <= sz; i ++){
		while(j && t[j + 1] != t[i]) j = nxt[j];
		if(t[j + 1] == t[i]) j ++;
		nxt[i] = j;
	}
	// for(int i = 1; i <= sz; i ++){
	// 	std::cout << nxt[i] << endl;
	// }
}
void upd(std::string &a, std::string b){
	if((int)a.size() < (int)b.size()){
		a = b;
	}
}
signed main() {
    // freopen("set03.in","r",stdin);
    // freopen("set.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    scanf("%s%s%s", a + 1, b + 1, c + 1);
    KMP(c);
    n = strlen(a + 1), m = strlen(b + 1), k = strlen(c + 1);
    for(int i = 1; i <= n; i ++){
    	for(int j = 1; j <= m; j ++){
    		for(int l = 0; l < k; l ++){
    			if(a[i] == b[j]){
    				int pos = l;
    				while(pos && c[pos + 1] != a[i]) pos = nxt[pos];
    				if(c[pos + 1] == a[i]) pos ++;
    				upd(dp[i][j][pos], dp[i - 1][j - 1][l] + a[i]);
    			}
    			upd(dp[i][j][l], dp[i - 1][j][l]);
    			upd(dp[i][j][l], dp[i][j - 1][l]);
    		}
    	}
    }
    std::string ans;
    for(int i = 0; i < k; i ++){
    	upd(ans, dp[n][m][i]);
    }
    if(ans.size()){
    	std::cout << ans << endl;
    }else{
    	std::cout << "0" << endl;
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}