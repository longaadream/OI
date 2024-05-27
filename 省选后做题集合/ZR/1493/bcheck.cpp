#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 5,  B = 5e2, mod = 1e9 + 7;
const int inf = 1e9;
int n, m, tot, tr[N << 2], tg[N << 2];
pii a[N], rl[N];
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
void pushdown(int x){
    if(tg[x]){
        tr[x << 1] += tg[x], tr[x << 1 | 1] += tg[x];
        tg[x << 1] += tg[x], tg[x << 1 | 1] += tg[x];
        tg[x] = 0;
    }
}
void update(int x, int l, int r, int ll, int rr, int det){
    if(l >= ll && r <= rr){
        tg[x] += det, tr[x] += det;
        return ;
    }
    int mid = (l + r) >> 1;
    pushdown(x);
    if(ll <= mid) update(x << 1, l, mid, ll, rr, det);
    if(mid + 1 <= rr) update(x << 1 | 1, mid + 1, r, ll, rr, det);
    tr[x] = std::max(tr[x << 1], tr[x << 1 | 1]); 
}
// int query(int x, int l, int r, int ll, int rr){
//     if(ll <= l && r <= rr){
//         return tr[x];
//     }
//     int mid = (l + r) >> 1;
//     pushdown(x);
//     int ans = 0;
//     if(ll <= mid) ans = std::max(ans, query(x << 1, l, mid, ll, rr)); 
//     if(mid + 1 <= rr) ans = std::max(ans, query(x << 1 | 1, mid + 1, r, ll, rr));
//     return ans;
// }
signed main(){
    // freopen("ex_A3.in","r",stdin);
    // freopen("a.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    while(1){
        system("bdtmk.exe");
        system("b.exe");
        system("bdp.exe");
        if(system("fc bb.out b1.out")) break;
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}