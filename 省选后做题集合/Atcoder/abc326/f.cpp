#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 100,  M = 65, mod = 1e9 + 7;
const int inf = 1e9;
int n, hori[N], vert[N], obx, oby, totx, toty;
std::unordered_map<i64, int> mph, mpv;
std::unordered_map<i64, int> vish, visv;
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
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    // freopen("ex_pairs3.in","r",stdin);
    // freopen("pairs.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read(); obx = read(), oby = read();
    for(int i = 1; i <= n; i ++){
        if(i & 1) vert[++ toty] = read(); else hori[++ totx] = read();
    }
    int prex = totx/2, prey = toty/2;
    // std::cout << totx << " " << toty << endl;
    // std::cout << prex << " " << prey << endl;
    // for(int i = 1; i <= totx; i ++) std::cout << hori[i] << endl;
    // for(int i = 1; i <= toty; i ++) std::cout << vert[i] << endl;
    for(int bt = 0; bt <= (1 << prex) - 1; bt ++){
        i64 sum = 0;
        for(int i = 1; i <= prex; i ++){
             if((1 << (i - 1)) & bt){
                sum += hori[i];
            }else sum -= hori[i];
        }
        // std::cout << bt << " " << sum << endl;
        mph[sum] = bt;
        vish[sum] = 1;
    }
    for(int bt = 0; bt <= (1 << prey) - 1; bt ++){
        i64 sum = 0;
        for(int i = 1; i <= prey; i ++){
            if(1 << (i - 1) & bt){
                sum += vert[i];
            }else sum -= vert[i];
        }
        // std::cout << bt << " " << sum << endl;
        mpv[sum] = bt;
        visv[sum] = 1;
    }
    i64 tgv = -1, tgh = -1;
    // std::cout << totx - prex << " " << toty - prey << endl;
    for(int bt = 0; bt <= (1 << (totx - prex)) - 1; bt ++){
        i64 sum = 0;
        for(int i = prex + 1; i <= totx; i ++){
            if((1 << (i - prex - 1)) & bt){
                sum += hori[i];
            }else sum -= hori[i];
        }
        // std::cout << bt << " " << sum << endl;
        // std::cout << sum - obx << endl; 
        if(vish[-sum - obx]){
            // std::cout << bt << " " << mph[sum] - obx << endl; 
            tgh = (1ll * bt) << prex;
            tgh |= mph[-sum - obx];
        }
    }
    for(int bt = 0; bt <= (1 << (toty - prey)) - 1; bt ++){
        i64 sum = 0;
        for(int i = prey + 1; i <= toty; i ++){
            if((1 << (i - prey - 1)) & bt){
                sum += vert[i];
            }else sum -= vert[i];
        }
        // std::cout << bt << " " << sum << endl;
        if(visv[-sum - oby]){
            tgv = (1ll * bt) << prey;
            tgv |= mpv[-sum - oby];
        }
    }
    std::cout << tgv << " " << tgh << endl;
    if(~tgh && ~tgv){
        std::cout << "Yes" << endl;
        int cur = 1;
        for(int i = 1; i <= n; i ++){
            if(i & 1){
                // std::cout << (tgv >> ((i + 1)/2 - 1) & 1) << endl;
                if(cur == 1){
                    std::cout << ((tgv >> ((i + 1)/2 - 1) & 1) ? "L" : "R");
                }else{
                    std::cout << ((tgv >> ((i + 1)/2 - 1) & 1) ? "R" : "L");
                }
                if(tgv >> ((i + 1)/2 - 1) & 1) cur = 1; else cur = 2;      
            }else{
                // std::cout << (tgh >> (i/2 - 1) & 1) << endl;
                if(cur == 1){
                    std::cout << ((tgh >> (i/2 - 1) & 1) ? "R" : "L");
                }else{
                    std::cout << ((tgh >> (i/2 - 1) & 1) ? "L" : "R");
                }
                if(tgh >> (i/2 - 1) & 1) cur = 2; else cur = 1;
            }
        }
    }else{
        std::cout << "No";
    }
    // }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}