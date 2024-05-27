#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5, mod = 998244353;
int n, q;
int buk[N], dp[N];
struct BIT{
	int tr[N << 1];
	#define lowbit(x) x&(-x)
	void modify(int x, int det){
		while(x <= n){
			tr[x] =(tr[x] + det) % mod;
			x += lowbit(x);
		}
	}
	int query(int x){
		int res = 0;
		while(x){
			res = (res + tr[x]) % mod;
			x -= lowbit(x);
		}
		return res;
	}
}T;
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
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
   	for(int i = 1; i <= n; i ++) {
   		int t = read(); 
   		if(!buk[t]){
  			T.modify(i, dp[i] = 1 + T.query(i - 1)); 			
   		}else{
   			T.modify(i, dp[i] = (T.query(i - 1) - T.query(buk[t] - 1) + mod) % mod);
   			T.modify(buk[t], mod-dp[buk[t]]);
   		}
   		buk[t] = i;
   	}
   	std::cout << T.query(n) << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}