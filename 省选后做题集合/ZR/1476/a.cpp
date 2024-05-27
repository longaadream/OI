#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 3e5 + 5, mod = 1e9 + 7;
std::string a;
i64 ans = 0;
bool Med;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
char make(char a,char b){
	int ta = a - '0', tb = b - '0';
	if(ta + tb >= 10){
		tb = (ta + tb) % 10, ta = 1;
		ans ++;
	}
	ans ++;
	return (char)((ta + tb) + '0');
}
signed main() {
	// freopen("soldier.in","r",stdin);
	// freopen("soldier.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
   	// int tt = read();
   	clock_t be = clock();
   	int tt = 1;
   	while(tt --){
	   	std::cin >> a;
	   	std::string tmp;
	   	for(int i = 0; i < (int)a.size(); i ++){
	   		tmp.push_back(a[i]);
	   		if(tmp.size() == 2){
	   			// std::cout << tmp << endl;
	   			char t = make(tmp[0], tmp[1]);
	   			// std::cout << t << endl;
	   			tmp.clear();
	   			tmp.push_back(t);
	   		}
	   	}
	   	std::cout << ans << endl;
	}
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}