#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e6+5, inf = 1e9;
int n,a[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
bool check(int lim, int mx){
	int flg = 0;int mxx = 0;
	for(int i = 1; i <= n; i ++){
		if(flg == 2 && a[i] < lim){
			return 0;
		}
		if(flg == 1){
			mxx = std::max(mxx , std::max(0, lim - a[i]));
		}
		if(flg == 1 && a[i] + mxx > mx){
			flg = 2;
		}
		if(!flg && a[i] < lim) flg = 1,mxx = std::max(mxx, std::max(0, lim - a[i]));
	}
	return 1;
}
signed main() {
	// freopen("link.in","r",stdin);
	// freopen("link.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt = read();
	clock_t be=clock();
	while(tt--){
		n = read();
		int mx = 0;
		for(int i = 1; i <= n; i ++) {a[i] = read(); mx = std::max(mx, a[i]);}
		int l = 0, r = 1e9, ans = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid, mx)) {
				ans = mid, l = mid + 1;
			}else r = mid - 1;
 		}
 		std::cout << mx - ans << endl;
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}