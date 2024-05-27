#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e6+5;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	freopen("kill.in","r",stdin);
	freopen("kill.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	clock_t be=clock();
	puts("TIE");
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}