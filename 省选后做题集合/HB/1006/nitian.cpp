#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef int ll;
const ll maxn = 1e6 + 7;
const ll INF = 1e9 + 7, MOD = 998244353; // 1e9 + 7

inline ll read()
{
    char cCc;
    ll xXx = 0, wWw = 1;
    while (cCc < '0' || cCc > '9')
        (cCc == '-') && (wWw = -wWw), cCc = getchar();
    while (cCc >= '0' && cCc <= '9')
        xXx = (xXx << 1) + (xXx << 3) + (cCc ^ '0'), cCc = getchar();
    xXx *= wWw;
    return xXx;
}

inline void write(ll xXx)
{
    if (xXx < 0)
        putchar('-'), xXx = -xXx;
    if (xXx > 9)
        write(xXx / 10);
    putchar(xXx % 10 + '0');
}

inline void add(ll &Aa, const ll Bb) { Aa = (Aa + Bb) > MOD ? (Aa + Bb - MOD) : Aa + Bb; }
inline void chmax(ll &Aa, const ll Bb) { Aa = (Aa < Bb ? Bb : Aa); }
inline void chmin(ll &Aa, const ll Bb) { Aa = (Aa > Bb ? Bb : Aa); }

ll A = 0, B = 1;
ll n, a[maxn], b[maxn], f[maxn][2][2];
char ans[maxn];

signed main()
{
    // freopen("merge.in", "r", stdin);
    // freopen("merge.out", "w", stdout);
    n = read();
    for (ll i = 1; i <= n << 1; i++)
        a[i] = read();
    for (ll i = 1; i <= n << 1; i++)
        b[i] = read();
    memset(f, -0x3f, sizeof f);
    f[1][A][A] = 1, f[1][A][B] = 0;
    f[1][B][A] = 0, f[1][B][B] = 1;
    for (ll i = 2; i <= n << 1; i++)
    {
        if (a[i - 1] <= a[i])
            chmax(f[i][A][A], f[i - 1][A][A] + 1), chmax(f[i][A][B], f[i - 1][A][B]);
        if (b[i - 1] <= a[i])
            chmax(f[i][A][A], f[i - 1][B][A] + 1), chmax(f[i][A][B], f[i - 1][B][B]);
        if (a[i - 1] <= b[i])
            chmax(f[i][B][A], f[i - 1][A][A]), chmax(f[i][B][B], f[i - 1][A][B] + 1);
        if (b[i - 1] <= b[i])
            chmax(f[i][B][A], f[i - 1][B][A]), chmax(f[i][B][B], f[i - 1][B][B] + 1);
    }

    std::cout << f[2*n][A][A] << " " << f[2*n][B][B] << endl;
    ll cntA = 0, cntB = 0, lst = INT_MAX;
    for (ll i = n << 1; i; i--)
    {
        if (cntA + f[i][A][A] >= n && cntB + f[i][A][B] >= n && a[i] <= lst)
            cntA++, ans[i] = 'A', lst = a[i];
        else if (cntA + f[i][B][A] >= n && cntB + f[i][B][B] >= n && b[i] <= lst)
            cntB++, ans[i] = 'B', lst = b[i];
        else
            return cout << -1, 0;
    }
    for (ll i = 1; i <= n << 1; i++)
        putchar(ans[i]);
    return 0;
}
/*
3
2 5 4 9 15 11
6 7 6 8 12 14
*/