#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 1e6+5, inf = 1e9;
int n,a[N],b[N],dp[N][2][2];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline void chmax(int &a,const int b){if(a < b) a = b;}
signed main() {
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read();
	clock_t be = clock();
    for (int i = 1; i <= n << 1; i++)
        a[i] = read();
    for (int i = 1; i <= n << 1; i++)
        b[i] = read();
    memset(dp, -0x3f, sizeof dp);
    #define A 0
    #define B 1
    dp[1][A][A] = 1, dp[1][A][B] = 0;
    dp[1][B][A] = 0, dp[1][B][B] = 1;
    for (int i = 2; i <= n << 1; i++)
    {
        if (a[i - 1] <= a[i])
            chmax(dp[i][A][A], dp[i - 1][A][A] + 1), chmax(dp[i][A][B], dp[i - 1][A][B]);
        if (b[i - 1] <= a[i])
            chmax(dp[i][A][A], dp[i - 1][B][A] + 1), chmax(dp[i][A][B], dp[i - 1][B][B]);
        if (a[i - 1] <= b[i])
            chmax(dp[i][B][A], dp[i - 1][A][A]), chmax(dp[i][B][B], dp[i - 1][A][B] + 1);
        if (b[i - 1] <= b[i])
            chmax(dp[i][B][A], dp[i - 1][B][A]), chmax(dp[i][B][B], dp[i - 1][B][B] + 1);
    }
    // std::cout << dp[2*n][A][A] << " " << dp[2*n][B][B] << endl;
    int cntA = 0, cntB = 0, lst = inf;
    std::string tmp;
    for (int i = n << 1; i; i--)
    {
        if (cntA + dp[i][A][A] >= n && cntB + dp[i][A][B] >= n && a[i] <= lst)
            cntA++, tmp.push_back('A'), lst = a[i];
        else if (cntA + dp[i][B][A] >= n && cntB + dp[i][B][B] >= n && b[i] <= lst)
            cntB++, tmp.push_back('B'), lst = b[i];
        else
            return std::cout << -1, 0;
    }
    reverse(begin(tmp),end(tmp));
    std::cout << tmp << endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}