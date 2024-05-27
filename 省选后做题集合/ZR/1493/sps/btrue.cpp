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
    freopen("bb.in","r",stdin);
    freopen("bb.out","w",stdout);
    // int tt = read();
    n = read(); m = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    for(int i = 1; i <= n; i ++) a[i].first = read(), a[i].second = read();
    std::sort(a + 1, a + n + 1,[](pii a, pii b){
        return (a.first ^ b.first) ? a.first < b.first : a.second < b.second;
    });
    for(int i = 1, lst = 0; i <= n; i ++){
        if(a[i].second <= lst){
            continue;
        }   
        rl[++ tot] = a[i];
        lst  = a[i].second;
    }
    while(m --){
        int x = read(), det = read();
        int l = 1, r = tot, ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(x <= rl[mid].second){
                ans = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        int ll = ans;
        l = 1, r = tot, ans = tot + 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(x >= rl[mid].first){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        int rr = ans;
        // std::cout << ll << " " << rr << endl;
        if(ll != 0 && rr != tot + 1 && ll <= rr) update(1, 1, tot, ll, rr, det);
        std::cout << tr[1] << endl;
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}