#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000010;
int n,m;
char s[N];
int L[N][2],R[N][2],ans[N];
bool check(int i,int j)
{
	return s[i]=='?'||s[i]==j+'0';
}
int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	memset(L,0x3f,sizeof L);
	memset(R,-0x3f,sizeof R);
	for(int i=0;i<2;i++)
		if(check(n,i))
			L[n][i]=R[n][i]=0;
	for(int i=n-1;i;i--)
		for(int j=0;j<2;j++)
			if(check(i,j))
			{
				L[i][j]=min(L[i+1][j],L[i+1][j^1]+1);
				R[i][j]=max(R[i+1][j],R[i+1][j^1]+1);
			}
	for(int i = 1; i <= n; i ++) for(int j = 0; j <= 1; j ++) std::cout << L[i][j] << " " << R[i][j] << endl; 
	for(int i=1,cur=0;i<=n;i++)
	{
		ans[i]=-1;
		for(int j=0;j<2;j++)
		{
			cur+=i>1&&j!=ans[i-1];
			if(L[i][j]+cur<=m&&m<=R[i][j]+cur&&((m-(L[i][j]+cur))%2==0||s[n]=='?')){ans[i]=j;break;}
			cur-=i>1&&j!=ans[i-1];
		}
		if(ans[i]==-1)
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	return 0;
}