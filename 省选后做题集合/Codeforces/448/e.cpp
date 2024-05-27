#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e6+5;
i64 n, m, cnt;
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
std::map<i64,bool> pm;
std::map<i64, std::vector<i64> > v;
void print(i64 x){
    if(!cnt) exit(0);
    cnt --;
    std::cout << x << " ";
}
void solve(i64 a,i64 b){
    if(b == 0 || a == 1) {print(a);return;}
    if(!pm[a]){
        for(int j = 1 ; 1ll * j * j <= a; j ++){
            if(a % j == 0) v[a].push_back(j);
        }
        for(int j = sqrtl(a); j; j --){
            if(a % j == 0 && j != a/j) v[a].push_back(a/j);
        }
        pm[a] = 1;
    }
    for(i64 val:v[a]){
        solve(val, b - 1);
    }
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    n = read(), m = read(); cnt = 1e5;
	clock_t be = clock();
    solve(n, m);
    putchar(10);
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}