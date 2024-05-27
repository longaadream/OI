#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5;
int n, m;
int a0[N], a1[N];
char s[N];
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(std::abs(a) > std::abs(b)) a = b;}

signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), m = read();
    clock_t be = clock();
    std::cin >> (s + 1);
    int len = strlen(s + 1);
    for(int i = 1; i <= len; i ++) a0[i] = a0[i - 1] + (s[i] == '0' && s[i + 1] == '0'), a1[i] = a1[i - 1] + (s[i] == '1' && s[i + 1] == '1');
    while(m --){
    	int l = read(), r = read(); 
    	std::cout << 1 + std::max(a0[r] - a0[l - 1] - (s[r] == '0' && s[r + 1] == '0'), a1[r] - a1[l - 1] - (s[r] == '1' && s[r + 1] == '1')) << endl;
    }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}