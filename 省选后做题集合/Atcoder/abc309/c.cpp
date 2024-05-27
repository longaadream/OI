#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5;
struct node{
    int a,b;
}o[N];
signed main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>o[i].a>>o[i].b;
    }
    sort(o+1,o+n+1,[](node a,node b){return a.a<b.a;});
    for(int i=n-1;i;i--){
        o[i].b+=o[i+1].b;
    }
    for(int i=1;i<=n;i++){
        if(o[i].a==o[i-1].a) continue;
        if(o[i].b<=k){
            return cout<<o[i-1].a+1,0;
        }
    }
    cout<<o[n].a+1;
    return 0;
}