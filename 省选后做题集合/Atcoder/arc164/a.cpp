#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        i64 a,b;
        cin>>a>>b;
        i64 lb=0,ub=a;
        while(a){
            lb+=a%3;
            a/=3;
        }
        if(lb<=b&&b<=ub&&(b-lb)%2==0) cout<<"Yes\n";else cout<<"No\n";
    }
    return 0;
}