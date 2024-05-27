#include <bits/stdc++.h>
#define rep(i, f, t) for(int i(f); i <= t; ++i)
#define re(i, t) for(int i(1); i <= t; ++i)
#define per(i, t, f) for(int i(t); i >= f; --i)
#define pe(i, t) for(int i(t); i >= 1; --i)
#define ste(i, f, t, s) for(int i(f); i <= t; i += s)
#define ets(i, t, f, s) for(int i(t); i >= f; i -= s)
#define each(i, x) for(auto &i : (x))
#define nx(i, u) for(int i(head[u]); i; i = e[i].nxt) 
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
// #define int long long
using namespace std;
// typedef pair <double, int> pdi;
typedef pair <int, int> pii;
// typedef pair <string, bool> psb;
#define pb push_back
#define fi first
#define se second
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define ix(l, r) ((l + r) | (l != r))
#define mp(i, j) (make_pair(i, j))
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-7
#define look_memory cerr<<abs(&sT-&eD)/1024.0/1024<<'\n'
bool sT;
// #define int long long

namespace io {
char buf[1<<21], *p1 = buf, *p2 = buf, buf1[1<<21];
inline char gc () {return p1 == p2 && (p2 = (p1 = buf) + fread (buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;}

#ifndef ONLINE_JUDGE
#endif

template<class I>
inline void read(I &x) {
    x = 0; I f = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar(); }
    while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar(); }
    x *= f;
}

template<class I>
inline void write(I x) {
    if(x == 0) {putchar('0'); return;}
    I tmp = x > 0 ? x : -x;
    if(x < 0) putchar('-');
    int cnt = 0;
    while(tmp > 0) {
        buf1[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while(cnt > 0) putchar(buf1[--cnt]);
}

#define in(x) read(x)
#define outn(x) write(x), putchar('\n')
#define out(x) write(x), putchar(' ')

} using namespace io;

const int mod = 998244353;
int n, m, x, y, p, q;
int a[15][15];

inline int ksm (int a, int b){
    ll ans = 1, base = a;
    while(b) {
        if(b & 1) ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}

queue<int>Q;
int dis[20];
int e[20][20];

void solve () {
    int ans =0;
    int num = n*(n-1);
    re(s, (1 << num) - 1) {
        int res = 0;
        int now = 1;
        re(i, n) {
            re(j, n) {
                e[i][j] = 0;
                if(i == j) continue;
                if(s >> res & 1) now = 1ll * now * a[i][j] % mod, e[i][j] = 1;
                else now = 1ll * now * (mod + 1 - a[i][j]) % mod;
                res++;
            }
        }
        re(i, n) dis[i] = inf;
        dis[1] = 0;
        Q.push(1);
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            re(i, n) {
                if(e[u][i]) {
                    if(dis[i] > dis[u] + 1) {
                        dis[i] = dis[u] + 1;
                        Q.push(i);
                    }
                }
            }
        }
        bool flag = 0;
        re(i, n) {
            if(dis[i] > m) {
                flag = 1;
                break;
            }
        }
        if(!flag) ans = (ans + now) %mod;
    }
    outn(ans);
}

bool eD;
int main () {
    freopen("a.in","r",stdin);
    // freopen("2.txt","w",stdout);
    read(n), read(m);
    re(i, n*(n-1)) {
        read(x), read(y), read(p), read(q);
        a[x][y] = 1ll * p * ksm(q, mod- 2) % mod; 
    }  
    solve();
    return 0;
}