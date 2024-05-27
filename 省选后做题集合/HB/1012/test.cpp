#include<bits/stdc++.h>
#define db double
#define int ll
#define ll long long
#define ull unsigned long long
#define pb emplace_back
#define MP make_pair
#define pii pair<int, int>
#define vec vector<int>
#define fi first
#define se second
#define ls k<<1
#define rs k<<1|1
#define CLK (double)clock()/(double)CLOCKS_PER_SEC
using namespace std;
mt19937 rnd(time(0));
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int N=505,inf=1e18;
int n,m;db ans=inf,val[N],f[N][N];
struct node{int a,b;}a[N];
template<typename T>void chkmin(T &x,T y){x=min(x,y);}
db Solve(int K){
    for(int i=0;i<=m;i++)for(int j=0;j<=K;j++)f[i][j]=inf;
    f[0][0]=0;
    for(int i=0;i<m;i++)for(int j=0;j<=K;j++){
        chkmin(f[i+1][j],f[i][j]+1.*a[i+1].a/(K+1));
        chkmin(f[i+1][j+1],f[i][j]+1.*a[i+1].b/(j+1));
    }
    db res=inf;
    for(int i=K;i<=m;i++)res=min(res,f[i][K]+val[i]/(K+1));
    return res;
}
void MAIN(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i].a=read(),a[i].b=read();
        if(a[i].b==-1)a[i].b=inf;
    }
    sort(a+1,a+1+n,[&](node x,node y){return x.b<y.b;});
    for(int i=m;i>=0;i--){
        vec v;for(int j=i+1;j<=n;j++)v.pb(a[j].a);
        sort(v.begin(),v.end());
        for(int j=1;j<=m-i;j++)val[i]+=v[j-1];
    }
    for(int i=0;i<=m;i++)ans=min(ans,Solve(i));
    printf("%.10lf",ans);
}
signed main(){
 //   freopen("read.in","r",stdin);
//	freopen("write.out","w",stdout);
    int T=1;while(T--)MAIN();
//  printf("\nTIME:%lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}