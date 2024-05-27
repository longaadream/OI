#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N][N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            a[i][j+1]=s[j]=='1';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j!=1){
                cout<<a[i][j-1];
                continue;
            }
            if(i==1&&j==1){
                cout<<a[i+1][j];
                continue;
            }
            if(j==n&&i!=1){
                cout<<a[i-1][j];
                continue;
            }
            if(j==n&&i==1){
                cout<<a[i][j-1];
                continue;
            }
            if(i==n&&j!=n){
                cout<<a[i][j+1];
                continue;
            }
            if(i==n&&j==n){
                cout<<a[i-1][j];
                continue;
            }
            if(j==1&&i!=n){
                cout<<a[i+1][j];
                continue;
            }
            if(j==1&&i==n){
                cout<<a[i][j+1];
                continue;
            }
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}