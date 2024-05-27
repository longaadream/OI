#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5, M = 105, mod = 998244353;
const int inf = 1e9;
int n, nodecnt, a[N], rt, k;
struct node{
    int len, ls, rs, mx, lmx, rmx, num, id;
    node(): mx(0), lmx(0), rmx(0), num(0), ls(0), rs(0), len(0){};
}tr[N << 5];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
    i64 x = 0,f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
    while(isdigit(c)){ x = x * 10 + (c ^ 48); c = getchar();}
    return x * f;
}
void pushup(int x){
    node ll = tr[tr[x].ls], rr = tr[tr[x].rs];
    tr[x].mx = std::max({ll.mx, rr.mx, ll.rmx + rr.lmx});  
    tr[x].lmx = ll.lmx, tr[x].rmx = rr.rmx;
    if(ll.lmx == ll.len) tr[x].lmx += rr.lmx;
    if(rr.rmx == rr.len) tr[x].rmx += ll.rmx;
}
void modify(int &x, int l, int r, int k, int det){
    if(!x) x = ++nodecnt, tr[x].len = r - l + 1, tr[x].id = x;
    // std::cerr << x << " " << l << " " << r << endl;
    if(l == r){
        tr[x].num += det;
        if(!tr[x].num) tr[x].lmx = tr[x].rmx = tr[x].mx = 0; else tr[x].lmx = tr[x].rmx = tr[x].mx = 1;
        // std::cout << "orz" << endl;
        return ;
    }
    int mid = (l + r) >> 1;
    if(k <= mid) modify(tr[x].ls, l, mid, k, det);
    else modify(tr[x].rs, mid + 1, r, k, det);
    pushup(x);
    // std::cout << l << " " << r << " " << tr[x].lmx << " " << tr[x].rmx << " " << tr[x].mx << endl;
}
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    freopen("set03.in","r",stdin);
    freopen("set.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    i64 ans = 0;
    n = read(), k = read();
    for(int i = 1; i <= n; i ++) a[i] = read();
    for(int i = 1,l = 1; i <= n; i ++){
        modify(rt, 1, inf, a[i], 1);
        // std::cout << i << endl;
        while(tr[rt].mx > k) {modify(rt, 1, inf, a[l ++], -1);}
        // std::cout << l << endl;
        ans += i - l + 1;
    }
    std::cout << ans << endl;
    // }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}