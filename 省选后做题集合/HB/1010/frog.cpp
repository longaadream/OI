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
const int N = 2e5 + 5, inf = 1e9;  
int n, m, a[N], l[N], r[N];
i64 dis[N];
std::vector<int> E[N];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline bool up(T &a,const T b){return (a <= b && ((a = b) + 1));}
template<class T>inline bool down(T &a,const T b){return (a > b && ((a = b) + 1));}
signed main() {
	freopen("frog.in","r",stdin);
	freopen("frog.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), m = read();
    clock_t be = clock();
	for(int i = 1; i <= n; i ++) a[i] = read();
    for(int i = 1; i <= m; i ++){
        int u = read(), v = read();
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++){dis[i] = inf;}
    dis[1] = 0,l[1] = 0, r[1] = 0;
    std::priority_queue<pli, std::vector<pli>, std::less<pli>> pq;
    pq.push(std::make_pair(0, 1));
    while(pq.size()){
        int u = pq.top().second, ds = pq.top().first;
        pq.pop();
        if(ds != dis[u]) continue;
        for(int v:E[u]){
            if(down(dis[v], dis[u] + 1 + std::max(0, a[v] - r[u] - 1))){
                l[v] = std::max(l[u] - 1, a[v]);
                r[v] = std::max(r[u] + 1, a[v]);
                pq.push(std::make_pair(dis[v], v));
            }
            if(dis[v] == dis[u] + 1 + std::max(0, a[v] - r[u] - 1)){
                l[v] = std::max(l[u] - 1, a[v]);
                r[v] = std::max(r[u] + 1, a[v]);   
            }
        }
    }      
    std::cout << dis[n] + l[n] << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}