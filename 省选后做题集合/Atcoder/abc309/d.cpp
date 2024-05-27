#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
vector<int> E[N];
int n1,n2,m,dis[N],vis[N];
int bfs(int cur){
    queue<int> q;
    int ans=0;
    q.push(cur);
    vis[cur]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:E[u]){
            if(vis[v]) continue;
            vis[v]=1;
            dis[v]=dis[u]+1;
            ans=max(ans,dis[v]);
            q.push(v);
        }
    }
    return ans;
}
signed main(){
    cin>>n1>>n2>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v),E[v].push_back(u);
    }
    cout<<bfs(1)+bfs(n1+n2)+1;
    return 0;
}