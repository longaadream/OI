#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<i64,int>;
bool Mbe;
const int N=1e5+5;
pii a[N],b[N];
int c1, c2;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
pii merge(pii a,pii b){
	pii c;
	c.first = a.first + b.first;
	c.second = -1;
	for(int i = 29; i; i --){
		if(a.second & b.second & (1 << i)){
			c.second = ((1 << i) - 1) | a.second | b.second;
			break;
		}
	}
	if(c.second == -1) c.second = a.second | b.second;
	return c;
}
signed main() {
	// freopen("ring.in","r",stdin);
	// freopen("ring.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	int n = read(), m = read();
	clock_t be=clock();
	a[++c1] = std::make_pair(0, 0);
	for(int i = 1; i <= n; i ++) {
		int v = read(), l = read();
		for(int j = 1; j <= c1; j ++) {
			a[j + c1] = merge(a[j], std::make_pair(v, l));
		}
		c2 = 0, c1 *= 2;
		sort(a + 1, a + c1 + 1);
		for(int j = 1; j <= c1; j ++) {
			if(!c2 || b[c2].second < a[j].second) {
				b[++c2] = a[j];
			} 	
		}
		c1 = c2;
		for(int j = 1; j <= c1; j ++) {
			a[j] = b[j];
		}
	}
	int q = read();
	for(int i = 0; i < q; i ++) { 
		int t = read();
		for(int j = 1; j <= c1; j ++){
			if(a[j].second >= t){
				std::cout << a[j].first << endl;
				goto end;
			}
		}
		std::cout << -1 << endl;
		end:{}
	}
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}
/*
4
2
1
0 1
3
3
0 1
1 2
2 0
6
6
0 1
0 5
1 3
5 4
3 2
4 2
6
7
0 1
0 5
1 3
1 4
5 4
3 2
4 2

*/