#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e5 + 5,  B = 5e2 + 5, mod = 1e9 + 7;
const int inf = 1e9;
int n, m, a[N], cnt;
i64 mp[2][B][N], bl;
std::unordered_map<int,int> siz, tot, flg, id, lsh, cod;
std::map<int,std::vector<int>> pos;
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
i64 brute(int x,int y){
    std::vector<int> num,tmpx,tmpy;
    tmpx = pos[x], tmpy = pos[y];
    int cntx = 0, cnty = 0;
    i64 ans = 0;
    while(tmpx.size() && tmpy.size()){
        if(tmpx.back() < tmpy.back()){
            ans = std::max(ans, 1ll * (++cnty) * (siz[x] - cntx)), tmpy.pop_back();
        }else ++cntx, tmpx.pop_back();
    }
    return ans;
}
signed main() {
    // freopen("aa.in","r",stdin);
    // freopen("a1.out","w",stdout);
    // int tt = read();
    n = read(); m = read();
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    for(int i = 1; i <= n; i ++) {a[i] = read();}
    std::vector<int> v;
    for(int i = 1; i <= n; i ++) v.push_back(a[i]);
    sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for(int i = 1; i <= n; i ++) {
        cod[a[i]] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        a[i] = cod[a[i]];
        siz[a[i]] ++; pos[a[i]].push_back(i);
    }
    for(pii vl:siz){
        if(vl.second >= (B - 5)){
            id[vl.first] = ++cnt;
            flg[vl.first] = 1;
            tot.clear();
            for(int i = 1; i <= n; i ++){
                mp[1][cnt][a[i]] = std::max(mp[1][cnt][a[i]], 1ll * (siz[a[i]] - tot[a[i]]) * tot[vl.first]);
                tot[a[i]] ++;
            }
            tot.clear();
            for(int i = n; i; i --){
                mp[0][cnt][a[i]] = std::max(mp[0][cnt][a[i]], 1ll * (siz[a[i]] - tot[a[i]]) * tot[vl.first]);
                tot[a[i]] ++;
            }
        }  
    }
    while(m --){
        int x = read(), y = read();
        x = cod[x], y = cod[y];
        if(x == y){
            std::cout << 1ll * siz[x]/2 * (siz[x] - siz[x]/2) << endl;
            continue;
        }
        if(flg[x]){
            x = id[x];
            std::cout << mp[1][x][y] << endl;
            continue;
        }
        if(flg[y]){
            y = id[y];
            std::cout << mp[0][y][x] << endl;
            continue;
        }
        std::cout << brute(x, y) << endl;
    }
    // }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}