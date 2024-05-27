#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
vector<int> E[N];
int n,m,val[N],vis[N],ans;
void dfs(int u,int dep){
    dep=max(dep,val[u]);
    if(dep) ans++;
    for(int v:E[u]){
        dfs(v,max(dep-1,0ll));
    }
}
signed main(){
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        E[u].push_back(i);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        val[x]=max(val[x],y+1);
    }
    dfs(1,val[1]);
    cout<<ans;
    return 0;
}