#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 2e6 + 5, M = 27, pw = 26, mod = 998244353;
int buk[M], pre[N], suf[N], hash[N], n, haspw[N];
char s[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline int gethash(int l,int r){
	return (hash[r] - 1ll * hash[l - 1] * haspw[r - l + 1] % mod + mod) % mod;
}
signed main() {
	// freopen("a.in","r",stdin);
	// freopen("b.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt = read();
	clock_t be=clock();
	while(tt -- ){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		haspw[0] = 1;
		for(int i = 1; i <= n; i ++){
			hash[i] = 1ll * hash[i - 1] * pw  % mod + (s[i] - 'a');
			hash[i] %= mod;
			haspw[i] = 1ll * haspw[i - 1] * pw % mod;
		}
		memset(buk, 0, sizeof buk);
		int sum = 0;
		for(int i = 1; i <= n; i ++){
			sum ++, buk[s[i] - 'a'] ++;
			if(buk[s[i] - 'a'] & 1) sum += buk[s[i] - 'a'];
			else sum -= buk[s[i] - 'a'];
			pre[i] = sum;
		}
		sum = 0;
		memset(buk, 0, sizeof buk);
		for(int i = n; i; i --){
			sum ++, buk[s[i] - 'a'] ++;
			if(buk[s[i] - 'a'] & 1) sum += buk[s[i] - 'a'];
			else sum -= buk[s[i] - 'a'];
			suf[i] = sum;
		}
		i64 ans = 0;
		for(int i = 1;i <= n; i ++){
			int ori = gethash(1, i);
			for(int j = i; j < n; j += i){
				if(ori == gethash(j - i + 1, j)){
					ans += 
				}
			}
		}
		std::cout << ans << endl;
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}