#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 105, inf = 1e9, M = 1e5 + 5;
int s, t, h, w, a[N][N], nxt[M], hd[M], to[M], val[M], cnt = 1, row[N], col[N], dis[M], cur[M];
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
void add(int u,int v,int w){
    nxt[++ cnt] = hd[u];
    hd[u] = cnt;
    to[cnt] = v;
    val[cnt] = w;
}
bool bfs(){
    // std::cout << "orz" << endl;
    memset(dis, -1, sizeof dis);
    std::queue<int> q;
    q.push(s);
    dis[s] = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v = hd[u]; v; v = nxt[v]){
            if(dis[to[v]] == -1 && val[v]){
                dis[to[v]] = dis[u] + 1;
                q.push(to[v]);
                if(to[v] == t) return 1;
            }
        } 
    }
    return 0;
}
int dfs(int u,int lim){
    if(!lim || u == t) return lim;
    int flow = 0, f;
    for(int &v = cur[u]; v; v = nxt[v]){
        if(dis[to[v]] == dis[u] + 1 && (f = dfs(to[v], std::min(lim, val[v]))) > 0){
            val[v] -= f, val[v ^ 1] += f;
            flow += f, lim -= f;
            if(!lim) return flow;
        }
    }
    return flow;
}
int flowe(){
    int res = 0;
    while(bfs()){
        for(int i = s; i <= t; i ++) cur[i] = hd[i];
        res += dfs(s,inf);
    }
    return res;
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    h = read(), w = read(), s = 0, t = h + w + 1;
	clock_t be = clock();
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){
            a[i][j] = read();
        }
    }
    int sum = 0;
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++) row[i] += a[i][j];
        sum += row[i];
        add(s, i, row[i]);    
        add(i, s, 0);
    }
    for(int i = 1; i <= w; i ++){
        for(int j = 1; j <= h; j ++) col[i] += a[j][i];
        sum += col[i];
        add(i + h, t, col[i]);
        add(t, i + h, 0);
    }
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){
            if(a[i][j] < 0) add(i, j + h, inf),add(i, j + h, 0); else add(i, j + h, a[i][j]), add(i, j + h, 0); 
        }
    }
    std::cout << sum - flowe() << endl;
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}