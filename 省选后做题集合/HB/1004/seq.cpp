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
int a[N], n, m;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline int reac(){
	char ret = getchar();
	while(ret != 'A' && ret != 'Q') ret = getchar();
	return ret;
}
signed main() {
	// freopen("ex_B2.in","r",stdin);
	// freopen("b.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), m = read();
	for(int i = 1; i <= n; i ++) a[i] = read();
	clock_t be=clock();
	while(m --){
		char s = reac();
		if(s == 'Q'){
			int l = read(), r = read();
			int mx = 0, sum = 0;
			for(int i = l; i <= r; i ++){
				sum += a[i];
				sum = std::max(0, sum);
				mx = std::max(mx, sum);
			}
			std::cout << mx << endl;
		}else{
			int l = read(), r = read(), x = read();
			for(int i = l; i <= r; i ++){
				a[i] += x;
			}
		}
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}