#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e6,  M = 305, mod = 1e9 + 7;
const int inf = 1e9;
int n, q;
int fa[N][2], pos[N], a[N];
std::map<pii, int> mp;
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
int findf(int x, int id){return fa[x][id] == x ? x : fa[x][id] = findf(fa[x][id]);}
void merge(int x, int y, int id){
    x = findf(x, id), y = findf(y, id);
    if(x == y) return ;
    fa[x][id] = y;
}
signed main() {
    // freopen("set03.in","r",stdin);
    // freopen("set.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read(), q = read();
    for(int i = 1; i <= n; i ++) a[i] = read(), pos[a[i]] = i;
    for(int i = 1; i <= 1e6; i ++) fa[i][0] = fa[i][1] = i;
    for(int i = 2; i <= 1e6; i ++){
        for(int j = i, fst = -1; j <= 1e6; j += i){
            if(!pos[j]) continue;
            if(~fst){
                merge(j, fst, 1);
            }else{
                fst = fa[i][1];
            }
        }
    }
    for(int i = 2; i <= 1e6; i ++){
        for(int j = i, fst = -1; j <= 1e6; j += i){
            if(!pos[j] && !pos[j - 1]) continue;
            if(~fst){
                merge(j, fst, 0);
            }else{
                fst = fa[i][0];
            }
        }
    }
    
    while(q --){
        int s = read(), t = read();

    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}