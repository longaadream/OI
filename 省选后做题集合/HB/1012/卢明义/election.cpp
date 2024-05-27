#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using pli=std::pair<i64,int>;
// using i128=__int128;
bool Mbe;
const int N = 500 + 5, inf = 1e9;  
double dp[N][N];
int n, K, suf[N];
struct node
{
    int a, b;
}a[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline bool up(T &a,const T b){return (a < b && ((a = b) + 1));}
template<class T>inline bool down(T &a,const T b){return (a > b && ((a = b) + 1));}
signed main() {
	freopen("election.in","r",stdin);
	freopen("election.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(); K = read();
    clock_t be = clock();
    for(int i = 1; i <= n; i ++) a[i].a = read(), a[i].b = read();
    for(int i = 1; i <= n; i ++) if(a[i].b == -1) a[i].b = inf;
    std::sort(a + 1, a + n + 1, [](node a,node b){return a.b ^ b.b ? a.b < b.b : a.a < b.a;});
    double ans = inf;
    for(int i = 0; i <= K; i ++){
        std::vector<int> v;
        for(int j = i + 1; j <= n; j ++) v.push_back(a[j].a);   
        std::sort(v.begin(),v.end());
        for(int j = 1; j <= K - i; j ++) suf[i] += v[j - 1];
    }
    // for(int i = 0; i <= K; i ++){
    //     std::cout << suf[i] << endl;
    // }
    for(int num = 0; num <= K; num ++){
        for(int i = 0; i <= K; i ++) for(int j = 0; j <= num; j ++) dp[i][j] = inf;
        dp[0][0] = 0;    
        for(int i = 0; i <= K; i ++){
            for(int j = 0; j <= std::min(i,num); j ++){
                down(dp[i + 1][j], dp[i][j] + 1.00 * a[i + 1].a/(num + 1));
                down(dp[i + 1][j + 1], dp[i][j] + 1.00 * a[i + 1].b/(j + 1)); 
            }
        }
        for(int i = num; i <= K; i ++) down(ans, dp[i][num] + 1.00 * suf[i]/(num + 1));
    }
    std::cout << std::fixed << std::setprecision(3) << ans << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}