#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N = 55;
int a[N],b[N],n,m,k;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("number.in","r",stdin);
	// freopen("number.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt = read();
	clock_t be=clock();
	while(tt --){
		n = read(), m = read(), k = read();		
		k %= 3;
		for(int i = 1; i <= n; i ++) a[i] = read();
		for(int i = 1; i <= m; i ++) b[i] = read();
		for(int i = 1; i <= k; i ++){
			if(i & 1){
				int mx = 0,mxpos;
				for(int j = 1;j <= n; j ++){
					if(b[j] > mx){
						mx = b[j],mxpos = j;
					}
				}
				int mn = 1e9,mnpos;
				for(int j = 1;j <= n; j ++){
					if(a[j] < mn){
						mn = a[j],mnpos = j;
					}
				}
				if(mx > mn){
					std::swap(a[mnpos], b[mxpos]);
				}
			}else{
				int mx = 0,mxpos;
				for(int j = 1;j <= n; j ++){
					if(a[j] > mx){
						mx = a[j],mxpos = j;
					}
				}
				int mn = 1e9,mnpos;
				for(int j = 1;j <= n; j ++){
					if(b[j] < mn){
						mn = b[j],mnpos = j;
					}
				}
				if(mx > mn){
					std::swap(b[mnpos], a[mxpos]);
				}
			}
		}	
		i64 ans = 0;
		for(int i = 1; i <= n; i++){ans += a[i];}
		std::cout << ans << endl;
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}