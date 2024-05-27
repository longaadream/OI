#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=2e5+5;
int fa[N],n,m,col[N],siz[N];
int findf(int u){
    return u==fa[u]?u:fa[u]=findf(fa[u]);
}
void unite(int u,int v){
    u=findf(u),v=findf(v);
    if(u==v) return;
    if(siz[u]<siz[v]) swap(u,v);
    fa[v]=u;
    siz[u]+=siz[v];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
    vector<pair<int,int>> q;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;  q.push_back(make_pair(u,v));
    }
    for(int i=1;i<=n;i++){
        cin>>col[i];
    }
    for(auto i:q){
        if(i.first!=i.second) unite(i.first,i.second);
    }
    for(int i=1;i<=n;i++) if(siz[i]%2==0) return cout<<"Yes",0;
    cout<<"No";
    return 0;
}