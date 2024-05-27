#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 1e6 + 5,  M = 65, mod = 1e9 + 7;
const int inf = 1e9;
i64 n, a[N], pos[N], det[N];
i64 k;
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
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    freopen("ex_ball3.in","r",stdin);
    freopen("ball.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read(), k = read();
    for(int i = 1; i <= n; i ++) pos[read()] = i;
    for(int i = 1; i < n; i ++){
        int l = pos[i], r = pos[i + 1];
        if(l > r) std::swap(l, r);
        det[l] ++, det[r] --;
    }
    std::priority_queue<i64> pq;
    for(int i = 1; i <= n; i ++) det[i] += det[i - 1], pq.push(det[i]);
    int cnt = 0;
    while(pq.size() && k > 0){
        cnt ++ ;
        k -= pq.top();
        pq.pop();
    }
    std::cout << (k > 0 ? -1 : cnt) << endl;
    // }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}