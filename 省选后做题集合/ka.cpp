#import<bits/stdc++.h>
using namespace std;int n,t,m,a[1<<19];main(){for(cin>>t;t--;sort(a,a+m),cout<<a[m/2]<<'\n',m=0)for(cin>>n;n--;cin>>a[m++],m-=n&1)}
