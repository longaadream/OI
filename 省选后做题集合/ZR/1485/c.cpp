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
int n, a[N * 6], pre[N], nxt[N], lst[N], sum[N * 6], cnt[N], dp[N * 6], mk[N * 6], pos[5], tot[N];
int ans;
bool Med;
// template<class T>inline void up(T &a, T b){if(a < b) a = b;}
// template<class T>inline void down(T &a, T b){if(a > b) a = b;}
// template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
template<class T>inline void addmod(T &a, T b){a = (a + b) % mod;}
// template<class T1, class T2>inline int qpow(T1 a, T2 b){int res = 1;for(;b;b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod; return res;}
inline i64 read() {
    i64 x = 0,f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
    while(isdigit(c)){ x = x * 10ll + (c ^ 48); c = getchar();}
    return x * f;
}
void solve(int l, int r){
    memset(dp, 0, sizeof dp);
    memset(sum, 0, sizeof sum);
    memset(lst, 0, sizeof lst);
    memset(cnt, 0, sizeof cnt);
    memset(tot, 0, sizeof tot);
    for(int i = l; i <= r; i ++){
        tot[a[i]] ++;
    }
    for(int i = 2; i <= n; i ++){
        if(tot[i] == 1) return ;
    }
    for(int i = l; i <= r; i ++){
        if(a[i] == 1) continue;
        if(lst[a[i]]) nxt[lst[a[i]]] = i;
        lst[a[i]] = i;
        cnt[a[i]] ++;
        if(tot[a[i]] == 3 && cnt[a[i]] == 2) sum[i] ++; 
        if(tot[a[i]] == 2) sum[i] ++; 
        mk[i] = cnt[a[i]];
    }
    for(int i = l; i <= r; i ++) sum[i] += sum[i - 1];
    dp[l] = 1;
    for(int i = l; i <= r; i ++){
        if(a[i] == 1){
            addmod(dp[i + 1], dp[i]);
            continue;
        }
        if(tot[a[i]] == 3){
            if(mk[i] == 1){
                if(sum[nxt[i] - 1] - sum[i] == 0 && a[i] != 1) addmod(dp[nxt[i] + 1], dp[i]);
                addmod(dp[i + 1], dp[i]);
            }else if(mk[i] == 2){
                if(sum[nxt[i] - 1] - sum[i] == 0 && a[i] != 1) addmod(dp[nxt[i] + 1], dp[i]);
            }else{
                addmod(dp[i + 1], dp[i]);
            }
        }else{
            if(mk[i] == 1){
                if(sum[nxt[i] - 1] - sum[i] != 0) return;
                else addmod(dp[nxt[i] + 1], dp[i]); 
            }
        }
    }
    addmod(ans, dp[r + 1]); 
}
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    // freopen("ex_pairs3.in","r",stdin);
    // freopen("pairs.out","w",stdout);
    // int tt = read();
    clock_t be = clock();
    // int tt = 1;
    // while(tt --){
    n = read();
    for(int i = 1; i <= 3 * n; i ++){
        a[i] = read();
        if(a[i] == 1) pos[cnt[a[i]] ++] = i;
    }
    for(int i = 3 * n + 1; i <= 6 * n; i ++){
        a[i] = a[i - 3 * n];
    }
    solve(pos[0] + 1, pos[1] - 1);
    solve(pos[1] + 1, pos[2] - 1);
    solve(pos[2] + 1, pos[0] - 1 + 3 * n);
    std::cout << ans << endl;
    // }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}