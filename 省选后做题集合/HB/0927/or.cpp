#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=5e3 + 5, inf = 1e18;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	freopen("or.in","r",stdin);
	freopen("or.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int l = read(), r = read();
	clock_t be=clock();
	int bas = r - l + 1;
	std::set<int> st;
	for(int bt = 1; bt <= (1 << bas) - 1; bt ++){
		int res = 0;
		for(int i = l; i <= r; i ++){
			if(bt & (1 << (i - l))){
				res |= i;
			}
		}
		st.insert(res);
	}
	std::cout << (int)st.size() << endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}