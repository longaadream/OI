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
pii chk(std::string s){
    int k = (int)s.size();
    for(int i = 0; i < k; i ++) if(s[i] == s[k - i - 1]) {if(s[i] == '0')return std::make_pair(0, k - i - 1); else return std::make_pair(0, i);}
    return std::make_pair(-1, 0);
}
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    // freopen("set03.in","r",stdin);
    // freopen("set.out","w",stdout);
    int tt = read();
    clock_t be = clock();
    // int tt = 1;
    while(tt --){
        int len = read();
        std::cin >> a;
        if(chk(a).first == -1) {std::cout << 0 << endl; continue;}
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < (int)a.size(); i ++){
            cnt0 += a[i] == '0', cnt1 += a[i] == '1';
        }
        if(cnt0 != cnt1) {std::cout << "-1" << endl; continue;}
        int cnt = 0;
        pii cur;
        std::string tmp = a;
        std::vector<int> q;
        tmp = ' ' + tmp;
        for(int i = 1; i <(int)tmp.size(); i ++){
            int j = tmp.size() - 1 - i + 1;
            if(i >= j) break;
            if(tmp[i] == tmp[j]){
                if(tmp[i] == '0'){
                    tmp.insert(j + 1,"01");
                    q.push_back(j);
                }else{
                    tmp.insert(i,"01");
                    q.push_back(i - 1);
                }
            }
        }
        std::cout << q.size() << endl;
        for(int i : q){
            std::cout << i << " ";
        }
        putchar(10);
    }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}