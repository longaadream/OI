#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,xa=0,xb=0,ya=0,yb=0;
    cin>>a>>b;
    if(b==a+1){
        if(b==7||b==4){
            return cout<<"No",0;
        }
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}