#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
bool Mbe;
const int N = 2e5 + 5,  B = 5e2 + 5, mod = 1e9 + 7;
const int inf = 0x7fffffff;
int n, a[N];
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
int rad(std::string a){
    int res = 0;
    for(char i:a){
        if(isdigit(i)){
            res = res * 10 + (i ^ 48);
        }
    }
    return res;
}
char reac(){
    char c = getchar();
    while(c != 'F' && c != 'E') c = getchar();
    return c;
}
int reads(std::string a){
    int res = 0;
    for(char i:a){
        if(isdigit(i)) res = res * 10 + (i ^ 48);
    }
    return res;
}
signed main() {
    // freopen("game.in","r",stdin);
    // freopen("game.out","w",stdout);
    int tt = read();
    // n = read();
    std::cerr << 1. * (&Med - &Mbe)/1024/1024 << endl;
    clock_t be = clock();
    // int tt = 1;
    while(tt --){
        int lines = read(), mx = 0;
        std::string com;
        std::cin >> com;
        if(com[2] == '1'){
            mx = 0;
        }else mx = reads(com);
        std::map<char, int> vars;
        std::stack<std::string> st;
        std::stack<bool> contri, cover;
        int sta = 0, flg = 1, mxsta = 0, comp = 0, cov = 0, avi = 0;
        for(int l = 1; l <= lines; l ++){
            char op; op = reac();
            // std::cout << op << endl;
            if(op == 'E'){if(!sta) {flg = 0;avi = 1;} if(!avi){if(cover.top()) cov --; cover.pop(); if(contri.top()) comp --; contri.pop(); sta --, vars[st.top()[0]] --, st.pop();}}
            else{
                std::string var; std::cin >> var;
                if(vars[var[0]]) {flg = 0;avi = 1;}
                std::string be, ed; std::cin >> be >> ed;
                if(!avi){
                vars[var[0]] ++;
                st.push(var);
                // std::cout << op << " " << var << " " << be << " " << ed << endl;
                if(be[0] == 'n' && ed[0] != 'n'){
                    cover.push(1);
                    cov ++;
                    contri.push(0);
                }else
                if(ed[0] == 'n' && be[0] != 'n'){
                    cover.push(0);
                    if(!cov) {comp ++, contri.push(1);} else contri.push(0);
                }else
                if(be[0] == 'n' && ed[0] == 'n'){
                    cover.push(0);
                    contri.push(0);
                }else{
                    int Be = rad(be), Ed = rad(ed);
                    if(Be <= Ed){
                        cover.push(0);
                        contri.push(0);
                    }else{
                        cover.push(1);
                        cov ++;
                        contri.push(0);
                    }
                }
                sta ++;
                mxsta = std::max(mxsta, comp);
                }
            }
            // std::cout << "comp:" << comp << "cov:" << cov << endl;
        }
        if(sta != 0) flg = 0; 
        if(!flg) {std::cout << "ERR" << endl; continue;}
        std::cout << (mxsta == mx ? "Yes" : "No") << endl;
    }
    std::cerr << clock() - be << "ms" << endl;
    return 0;
}