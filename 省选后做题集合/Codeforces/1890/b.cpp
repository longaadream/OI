#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 105, M = 65, mod = 1e9 + 7;
const int inf = 1e9;
int n;
std::string a, b;
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
bool chk(std::string s){
    if((int)s.size() == 1) return 1;
    for(int i = 1; i < (int)s.size(); i ++){
        if(s[i] == s[i - 1]) return 0;
    }
    return 1;
}
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    // freopen("set03.in","r",stdin);
    // freopen("set.out","w",stdout);
    int tt = read();
    clock_t be = clock();
    // int tt = 1;
    while(tt --){
        read(), read();
        std::cin >> a >> b;
        if(chk(a)) {std::cout << "Yes" << endl; continue;}
        if(!chk(b)){std::cout << "No" << endl;continue;}
        char l = b[0], r = b[(int)b.size() - 1];
        int flg = 1;
        for(int i = 0; i < (int)a.size(); i ++){
            if(a[i] == a[i + 1]){
                if(a[i] == l or a[i + 1] == r){
                    flg = 0;
                }
            }
        }
        std::cout << (flg ? "Yes" : "No") << endl;
    }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}