#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e6+5, inf = 1e9;
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("link.in","r",stdin);
	// freopen("link.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int tt = read();
	clock_t be=clock();
	while(tt--){
		int n = read();
		std::multiset<i64> s;
		for(int i = 1; i <= n; i ++){
			s.insert(read());
		}
		i64 ans = 0;
		while((int)s.size()){
			ans += *s.begin();
			s.erase(s.begin());
			if(s.size()){
				i64 x = *(--s.end());
				s.erase(--s.end());
				if(x > 2) s.insert(x - 2); 
			}
		}
		std::cout << ans << endl;
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}