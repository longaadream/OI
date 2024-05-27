#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using pli=std::pair<i64,int>;
// using i128=__int128;
bool Mbe;
const int N = 5000 + 5, inf = 1e9;  
int n, k, a[N], uni[N], sum[N], buk[N];
std::bitset<1005> chk;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline bool up(T &a,const T b){return (a < b && ((a = b) + 1));}
template<class T>inline bool down(T &a,const T b){return (a > b && ((a = b) + 1));}
signed main() {
	freopen("round.in","r",stdin);
	freopen("round.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), k = read();
    clock_t be = clock();
    for(int i = 1; i <= n; i ++){
        uni[i] = a[i] = read();
    }
    std::sort(uni + 1, uni + n + 1);
    int tot = std::unique(uni + 1, uni + n + 1) - uni - 1;
    for(int i = 1; i <= n; i ++){
        a[i] = std::lower_bound(uni + 1, uni + tot + 1, a[i]) - uni;
        sum[a[i]] ++;
    }
    int ans = 0, mn = 0x7fffffff;
    for(int l = 1; l <= n; l ++){
        chk.reset();
        for(int i = 1; i <= tot; i ++) buk[i] = 0;
        for(int r = l; r <= n; r ++){
            buk[a[r]] ++;
            if(buk[a[r]] != sum[a[r]]) chk[a[r]] = 1;
            else chk[a[r]] = 0;
            if(!chk.count() && (l != 1 && r != n)) ans ++, mn = std::min(mn, std::abs(n - 2 * (r - l + 1))), std::cout << l << " " << r << endl; 
        }
    }
    std::cout << ans << " " << mn << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}