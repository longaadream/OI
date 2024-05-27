#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 1e6+5, LIM = 1000;
int n,a[N],b[N], rnk[N];
i64 ans;
i64 c[N]; 
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
i64 F(int mid,int lim){
    int mn1 = a[mid], mn2 = b[mid];i64 res = 1ll * mn1 * mn2;
    up(ans, res);
    for(int rol = 0, l = mid, r = mid; lim --; rol ^= 1){
        if(rol){
            -- l, down(mn1, a[l]), down(mn2, b[l]);
        }else {
            ++ r, down(mn1, a[r]), down(mn2, b[r]);
        }
        if(l < 1 or r > n) return res;
        if(1ll * mn1 * mn2 * n <= ans) return 0;
        up(ans, res = 1ll * mn1 * mn2 * (r - l + 1));
    }
    return res;
}
signed main() {
	freopen("ni.in","r",stdin);
	freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    n = read();
	clock_t be = clock();
    for(int i = 1; i <= n; i ++) a[i] = read(), b[i] = read();
    for(int i = 1; i <= n; i ++) rnk[i] = i, c[i] = F(i, LIM);
    std::sort(rnk + 1, rnk + n + 1, [](int a,int b){
        return c[a] > c[b];
    });
    for(int i = 1; i <= n;i ++){
        if(1.00 * clock() / CLOCKS_PER_SEC > 2.40){
            break;
        }
        F(rnk[i], n);
    }
    std::cout << ans << endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}