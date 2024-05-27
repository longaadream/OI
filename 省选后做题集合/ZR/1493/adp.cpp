#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(b);i>=(a);i--)
#define endl "\n"
#define For(i,u) for(int i=head[u];i;i=e[i].next)
#define V vector<int>
#define VV vector<V>
#define Debug(a) cout<<"QwQ "<<a<<endl;
#define FST NOT_FST
#define trash_round unrated
#define pint pair<int,int>
#define fi first
#define se second
#define Vp vector<pint>
const int MOD=1e9+7;
using namespace std;
int n,m;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
string reads()
{
	char ch=getchar();string s;
	while(ch<'a'||ch>'z'){ch=getchar();}
	while(ch>='a'&&ch<='z'){s+=ch;ch=getchar();}
	return s;
}
char readc()
{
	char ch=getchar();
	while(ch<'a'||ch>'z') ch=getchar();
	return ch;
}

// down is mytrue code ------------------------------

const int N=1005;

int sum[N],rsum[N],a[N];

signed main()
{
	freopen("aa.in","r",stdin);
	freopen("aa.out","w",stdout);
	int n=read(),m=read();
	rep(i,1,n)
	{
		a[i]=read();
	}
	rep(i,1,m)
	{
		int x=read(),y=read();
		rep(i,0,n+1) sum[i]=0,rsum[i]=0;
		rep(i,1,n)
		{
			if(a[i]==x) sum[i]=1;
			sum[i]+=sum[i-1];
		}
		per(i,1,n)
		{
			if(a[i]==y) rsum[i]=1;
			rsum[i]+=rsum[i+1];
		}
		int ans=0;
		rep(i,1,n+1)
		{
			ans=max(ans,sum[i-1]*rsum[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}