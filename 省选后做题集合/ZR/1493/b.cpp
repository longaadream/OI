#include<bits/stdc++.h>
#define ll long long
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

int ct;

struct dt
{
	int l,r;
}k[N],a[N];

bool cmp(dt a,dt b)
{
	if(a.l==b.l) return a.r>b.r;
	else return a.l<b.l;
}

struct
{
	int maxn;
	int tag;
}tr[N*4];

void push_down(int i,int k)
{
	tr[i].maxn+=k;
	tr[i].tag+=k;
}

void push_up(int i)
{
	tr[i].maxn=max(tr[i*2].maxn,tr[i*2+1].maxn);
}

void lan(int i)
{
	if(tr[i].tag)
	{
		push_down(i*2,tr[i].tag);
		push_down(i*2+1,tr[i].tag);
		tr[i].tag=0;
	}
}

void upd(int i,int l,int r,int dl,int dr,int k)
{
	if(dl<=l&&dr>=r)
	{
		push_down(i,k);
		return;
	}
	lan(i);
	int mid=l+r>>1;
	if(dl<=mid)
	{
		upd(i*2,l,mid,dl,dr,k);
	}
	if(dr>mid)
	{
		upd(i*2+1,mid+1,r,dl,dr,k);
	}
	push_up(i);
}

const int INF=1e9+1;

int main()
{
	freopen("bb.in","r",stdin);
	freopen("bb.out","w",stdout);
	int n=read(),m=read();
	rep(i,1,n)
	{
		k[i].l=read();
		k[i].r=read();
	}
	sort(k+1,k+1+n,cmp);
	int last=0;
	rep(i,1,n)//È¥µô°üº¬ 
	{
		if(k[i].r<=last)
		{
			continue;
		}
		else
		{
			a[++ct]=k[i];
			last=k[i].r;
		}
	}
	a[ct+1].l=INF+1;
	a[ct+1].r=INF+1;
	rep(i,1,m)
	{
		int p=read(),x=read();
		int l=0,r=ct+1,R=ct+1,L=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(a[mid].l<=p)
			{
				l=mid+1;
				R=mid;
			}
			else r=mid-1;
		}
		l=0,r=ct+1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(a[mid].r>=p)
			{
				r=mid-1;
				L=mid;
			}
			else l=mid+1;
		}
		if(L<=R&&L!=0&&R!=ct+1) upd(1,1,n,L,R,x);
		cout<<tr[1].maxn<<endl;
	}
	return 0;
}