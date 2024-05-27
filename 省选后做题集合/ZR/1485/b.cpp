#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<i64,i64>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5,  M = 65, mod = 1e9 + 7;
const int inf = 1e9;
i64 mn[N << 2], tg[N << 2];
i64 n, y[N];
pii a[N];
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
    i64 x = 0,f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
    while(isdigit(c)){ x = x * 10ll + (c ^ 48); c = getchar();}
    return x * f;
}
void upd(int p,i64 v){tg[p]+=v,mn[p]+=v;}
void down(int p){
    if(tg[p]) upd(p<<1,tg[p]),upd(p<<1|1,tg[p]),tg[p]=0;
}
void modify(int p,int l,int r,int lx,int rx,int v){
    if(lx>rx) return ;
    if(l>=lx&&r<=rx) return upd(p,v);
    int mid=(l+r)/2;
    down(p);
    if(lx<=mid) modify(p<<1,l,mid,lx,rx,v);
    if(rx>mid) modify(p<<1|1,mid+1,r,lx,rx,v);
    mn[p]=std::min(mn[p<<1],mn[p<<1|1]);
}
void upd(int p,int l,int r,int pos,i64 v){
    if(l==r){mn[p]=v;return ;}
    int mid=(l+r)/2;
    down(p);
    if(pos<=mid) upd(p<<1,l,mid,pos,v);
    else upd(p<<1|1,mid+1,r,pos,v);
    mn[p]=std::min(mn[p<<1],mn[p<<1|1]);
}
i64 query(int p,int l,int r,int lx,int rx){
    if(l>=lx&&r<=rx) return mn[p];
    int mid=(l+r)/2; i64 ans=1e18;
    down(p);
    if(lx<=mid) ans=query(p<<1,l,mid,lx,rx);
    if(rx>mid) ans=std::min(ans,query(p<<1|1,mid+1,r,lx,rx));
    return ans;
}
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    freopen("ex_pairs3.in","r",stdin);
    freopen("pairs.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read();
    for(int i = 1; i <= n; i ++) a[i].first = read(), a[i].second = read(), y[i] = a[i].second;
    std::sort(a + 1, a + n + 1);
    std::sort(y + 1, y + n + 1);
    memset(mn, 0x7f,sizeof mn);
    upd(1, 0, n, 0, 0);
    for(int i = 1; i <= n; i ++){
        int pos = std::lower_bound(y + 1, y + n + 1, a[i].second) - y;
        upd(1, 0, n, pos, query(1, 0, n, 0, pos - 1) + a[i].first);
        modify(1, 0, n, pos + 1, n, a[i].first);
        modify(1, 0, n, 0, pos - 1, a[i].second);
    }
    std::cout << query(1, 0, n, 0, n) << endl;
    // }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}