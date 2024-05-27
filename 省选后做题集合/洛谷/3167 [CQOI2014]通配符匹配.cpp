#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=1e5+10,mod=998244353;
int n,m=1,op[N],len[N],h[N];
char s[N];
signed main(){
	cin>>(s+1)>>n;
	int ll=strlen(s+1);
	for(int i=1;i<=ll;i++){
		if(islower(s[i])) h[m]=(1ll*h[m]*124+s[i]-'a')%mod,len[m]++;else op[++m]=(s[i]=='*');
	}
	while(n--){
		static char c[N];
		static int hs[N],pw[N],l;
		cin>>(c+1); l=strlen(c+1);
		pw[0]=1;
		for(int i=1;i<=l;i++) pw[i]=1ll*pw[i-1]*124%mod,hs[i]=(1ll*hs[i-1]*124%mod+c[i]-'a')%mod;
		auto geths=[](int l,int r){return (hs[r]-1ll*hs[l-1]*pw[r-l+1]%mod+mod)%mod;};
		vector<bool> dp[20],lst;
		for (vector<bool> &i:dp) i.resize(l+10);
		dp[1][len[1]]=(h[1]==geths(1,len[1]));
		lst=dp[1];
		partial_sum(lst.begin(),lst.end(),lst.begin(),bit_or<>());
		for(int i=2;i<=m;i++){
			for(int j=1;j<=l;j++){
				if(j>=len[i]&&geths(j-len[i]+1,j)==h[i]&&!dp[i][j]){
					dp[i][j]=op[i]?lst[j-len[i]]:dp[i-1][j-len[i]-1];
				}
			}
			partial_sum(dp[i].begin(),dp[i].end(),lst.begin(),bit_or<>());
		}
		puts(dp[m][l]?"YES":"NO");
	}
}
