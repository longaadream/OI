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

const int N=1e6+5;

int ban[N],vis[N],a[N],last[N];

int suf[N];//ºó¼Ì 

int state[N];//Ñ¡²»ÁË/Ò»¶¨Ñ¡/¿ÉÄÜÑ¡ 

int dp[N],ans;

int sum[N];

void solve(int l,int r)
{
	rep(i,l-1,r+1)
	{
		dp[i]=0;
		sum[i]=0;
	}
	dp[l]=1;
	rep(i,l,r)
	{
		if(suf[i]>r) state[i]=0;
		else if(suf[suf[i]]>r) state[i]=1;
		else state[i]=2;
		sum[i]=sum[i-1]+(state[i]==1);
//		cout<<"×´Ì¬: "<<"i: "<<i<<" "<<state[i]<<endl;
	}
	rep(i,l,r)
	{
		dp[i]%=MOD;
		if(state[i]==0)
		{
			dp[i+1]+=dp[i]; 
		}
		if(state[i]==1)
		{
			int j=suf[i];
			if(sum[j-1]-sum[i]==0)
			{
				dp[j+1]+=dp[i];
			}
		}
		if(state[i]==2)
		{
			int j=suf[i];
			if(sum[j-1]-sum[i]==0)
			{
				dp[j+1]+=dp[i];
			}
			dp[i+1]+=dp[i];
		}
//		cout<<"dpÖµ: "<<"i: "<<i<<" "<<dp[i]<<endl;
	}
	dp[r+1]%=MOD;
//	cout<<dp[r+1]<<endl;
	ans+=dp[r+1];
	ans%=MOD;
}

int sm[N];

signed main()
{
	freopen("in.in","r",stdin);
	freopen("2.txt", "w", stdout);
	int n=read();
	rep(i,1,n*3)
	{
		a[i]=read();
		vis[a[i]]++;
		if(vis[a[i]]==2)
		{
			ban[i]=1;//½ûÖ¹	
		}
		sm[i]=sm[i-1]+ban[i];
		if(last[a[i]]!=0) suf[last[a[i]]]=i;
		last[a[i]]=i;
	}
	n=n*3;
	rep(i,1,n)
	{
		suf[last[i]]=n+1;
	}
	solve(1,n);//ÎÞÒ»È¦
	int flag=1,l=0;
	rep(i,0,n-1)
	{
		if(ban[i]) break;
		if(sm[n]-sm[last[a[i]]]==0)
		{
			solve(i+1,last[a[i]]-1);
		}
	}
//	rep(i,1,n)
//	{
//		if(a[i]==a[n]) {l=i;break;}
//		if(ban[i]) {flag=0;break;}
//	}
//	if(flag)
//	{
//		solve(l+1,n-1);
//	}
//	flag=1;int r=0;
//	per(i,1,n)
//	{
//		if(a[i]==a[1]) {r=i;break;}
//		if(ban[i]) {flag=0;break;}
//	}
//	if(flag)
//	{
//		solve(2,r);
//	}
	cout<<ans<<endl;
	return 0;
}