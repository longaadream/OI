#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 2e6+5;
i64 n, q, a[N], nxt[N], s[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
int check(int st,int ed){
    int ans = 0;
    while(st <= ed){
        st = nxt[st] + 1;
        ans ++;
    }
    return ans;
}
int solve(int k){
    if(s[n] <= k) return 1;
    int pos = 1;
    for(int i = 1; i <= n; i ++){
        while(s[pos + 1] - s[i - 1] <= k) pos ++;
        nxt[i] = pos;
    }
    // for(int i = 1; i <= n; i ++) std::cout << nxt[i] << " ";
    for(int i = n + 1; i <= n << 1; i ++) nxt[i] = nxt[i - n] + n;
    pos = 1;
    for(int i = 2; i <= n; i ++) if(nxt[pos] - pos > nxt[i] - i) pos = i;
    int res = 0x7fffffff;
    for(int i = pos + 1; i <= nxt[pos] + 1; i ++) {int ret = i > n ? i - n : i; down(res, check(ret, ret - 1 + n));}
    return res;  
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    n = read(); q = read();
	clock_t be = clock();
	for(int i = 1; i <= n; i ++) a[i] = read(), a[i + n] = a[i];
    for(int i = 1; i <= n << 1; i ++) s[i] = s[i - 1] + a[i];
    while(q --){
        int k = read();
        std::cout << solve(k) << endl;
    }
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}