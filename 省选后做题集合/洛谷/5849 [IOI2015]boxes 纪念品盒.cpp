#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e7+10;
int n,k,l;
int sta1[N],top1=0,sta2[N],top2=0; i64 sum1[N],sum2[N];
signed main() {
    n=read(),k=read(),l=read();
    for (int i=1,p=read();i<=n;i++,p=(i<=n)?read():0){if(p<=l/2) sta1[++top1]=p;else sta2[++top2]=l-p;}
    reverse(sta2+1,sta2+top2+1);
    for (int i=1;i<=top1;++i){if(i<=k) sum1[i]=sta1[i];else sum1[i]=sum1[i-k]+sta1[i];}
    for (int i=1;i<=top2;++i){if(i<=k) sum2[i]=sta2[i];else sum2[i]=sum2[i-k]+sta2[i];}
    i64 ans=2ll*(sum1[top1]+sum2[top2]);
    for (int i=top1-k;i<=top1;++i)ans=min(ans,2ll*(sum1[i]+sum2[max(0,n-k-i)])+l);
    cout<<ans;
    return 0;
}
