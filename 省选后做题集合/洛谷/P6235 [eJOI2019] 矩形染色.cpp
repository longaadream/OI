#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5+5, inf = 1e18;
i64 dp[N];
int a[N],b[N], n, m;
struct BIT{
    i64 tr[N << 1];
    #define lowbit(x) x&(-x)
    i64 query(int x){
        int res = 0;
        while(x){
            res += tr[x];
            x -= lowbit(x);
        }
        return res;
    }
    i64 range(int l,int r){
        return query(r) - query(l - 1);
    }
    void modify(int x, int det){
        int pos = 0;
        while(pos <= n + m - 1){
            tr[pos] += det;
            pos += lowbit(pos);
        }
    }
}T[2];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}

signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    n = read(), m = read();
	clock_t be = clock();
	for(int i = 1; i <= n + m - 1; i ++) a[i] = read();
    for(int i = 1; i <= n + m - 1; i ++) {b[i] = read();T[i & 1].modify(i, b[i]);}
    std::fill(dp, dp + n + m, inf);
    for(int i = 1; i <= n + m - 1; i ++){
        dp[i] = std::min({dp[i - 1] + a[i], dp[i - std::min(i, m)] + range()})
    }    
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}