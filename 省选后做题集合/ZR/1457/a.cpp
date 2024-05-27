#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 1e5 + 5;
int a[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("ex_A2.in","r",stdin);
	// freopen("a.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt = read();
	clock_t be=clock();
	while(tt --){
		int n = read();
		i64 sum = 0;
		if(n == 1){
			int t = read();
			if(t >= 0) {
				std::cout << "1" << endl;
				continue;
			} else {
				std::cout << "0" << endl;
				continue;
			}
		}
		int flag = 1;
		for(int i = 1; i <= n; i ++){
			int t = read(); if(sum < 0) {
				flag = 0;
			}
			sum += t;
		}
		if(flag) std::cout << "1" << endl; else std::cout << "0" << endl; 
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}