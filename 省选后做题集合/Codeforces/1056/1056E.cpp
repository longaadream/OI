#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=1e6+5,mod=998244353;
char s[N],t[N];
i64 hsh[N],pw[N];
int sum=0,fl,pre;
int lens,lent;
i64 gethsh(int l,int r){
	return (hsh[r]-1ll*hsh[l-1]*pw[r-l+1]%mod+mod)%mod;
}
bool check(int x){
	int len[2],val[2];
	len[0]=x,len[1]=(lent-len[0]*sum)/(lens-sum);
//	cerr<<len[0]<<" "<<len[1]<<endl;
	if((len[0]<=0) ||(len[1]<=0)) return 0;
	if(((len[0]*sum)+(len[1]*(lens-sum)))!=lent) return 0;
	val[0]=gethsh(1,len[0]),val[1]=gethsh(1+(len[0]*pre),(len[0]*pre)+len[1]);
	if(val[0]==val[1]) return 0;
	int cnt=0;
	for(int i=1,l=1;i<=lens;i++){
//		cerr<<s[i]<<endl;
		int r=l+len[s[i]!=('0'+fl)]-1;
//		cerr<<"l:"<<l<<"r:"<<r<<endl;
		if(gethsh(l,r)!=val[s[i]!=('0'+fl)]) return 0;
		l=r+1,cnt++;
	}
//	cerr<<"orz"<<endl;
	if(cnt!=lens) return 0;
	return 1;
}
signed main(){
	cin>>(s+1);
	cin>>(t+1);
	if(s[1]=='1') fl=1;
	lens=strlen(s+1),lent=strlen(t+1);
	int flg=0;
	for(int i=1;i<=lens;i++){
		if(!flg&&s[i]==('0'+fl)) pre++;
		if(s[i]!=('0'+fl)) flg=1;
		sum+=(s[i]==('0'+fl));
	}
	pw[0]=1;
	for(int i=1;i<=lent;i++){
		hsh[i]=(1ll*hsh[i-1]*124%mod+(t[i]-'a'+1))%mod;
		pw[i]=1ll*pw[i-1]*124%mod;
	}
	int ans=0;
	for(int i=1;i*sum<lent;i++){
		ans+=check(i);
	}
	cout<<ans;
	return 0;
}
