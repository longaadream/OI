#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 3e5 + 5, M = 5e4 + 5, B = 5e2 + 5, mod = 998244353;
const int inf = 0x7fffffff;
int n, q;
int tr[N << 2];
int a[N];
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
int merge(int x, int y){
    return (x & y) ? (x | y) : x;
}
void build(int x, int l, int r){
    if(l == r){
        tr[x] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    tr[x] = merge(tr[x << 1], tr[x << 1 | 1]);
}
int query(int x, int l, int r, int ll, int rr){
    if(l >= ll && r <= rr){
        return tr[x];
    }
    int mid = (l + r) >> 1;
    if(mid < ll) return query(x << 1 | 1, mid + 1, r, ll, rr);
    else if(rr < mid + 1) return query(x << 1, l, mid, ll, rr);
    else return merge(query(x << 1, l, mid, ll, rr), query(x << 1 | 1, mid + 1, r, ll, rr));
}
signed main() {
    // freopen("game.in","r",stdin);
    // freopen("game.out","w",stdout);
    // int tt = read();
    n = read(), q = read();
    std::cerr << (1. * (&Med - &Mbe)/1024/1024) << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    for(int i = 1; i <= n;i ++) a[i] = read();
    build(1, 1, n);
    while(q --){
        int l = read(), r = read();
        // std::cout << query(1, 1, n, l, r - 1) << endl;
        std::cout << ((query(1 , 1 , n, l , r - 1) & a[r]) ? "Shi" : "Fou") << endl;
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}


int a = 0
for i in range(1,n):
    a = a + i
print(a)