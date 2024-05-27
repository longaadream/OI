#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    int M=1<<N;
    vector<int> A(M);
    for(int i=0;i<M;i++) cin>>A[i];
    for(int i=0;i<M/2;i++){
        if(A[i]%(M/2)!=A[M/2+i]%(M/2)){
            return cout<<"No",0;
        }
    }
    vector<int> x;
    for (int i=0;i<M/2;i++){
        if (A[i]>=M/2){
            int a=(M-1)^A[i];
            x.push_back(a);
            x.push_back(-1);
            for (int j=0;j<M/2;j++){
                A[j]^=a;
                A[j]++;
            }
            A[i]=0;
        }
    }
    x.push_back(A[0]);
    for (int i=1;i<M/2;i++){
        A[i]^=A[0];
        if (A[i]!=i){
            return cout<<"No",0;
        }
    }
    int K=x.size();
    cout<<"Yes"<<endl;
    cout<<K<<endl;
    for (int i=0;i<K;i++){
      cout<<x[i]<<" ";
    }
    cout << endl;
    return 0;
}