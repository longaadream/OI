#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long;
using pii=pair<int,int>;
bool Mbe;
const int N=55;
bool Med;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int a[N],buk[N],len=0,C[N][N];
long long getmul(int n){
	long long ans=1;
	for(int i=0;i<=9;i++){
		ans*=C[n][buk[i]];
		n-=buk[i];
	}
	return ans;
}
signed main(){
	char c=getchar();
	while(!isdigit(c));
	while(isdigit(c)) buk[a[++len]=c^48]++,c=getchar();
	//for(int i=1;i<=len;i++) cout<<a[i]<<" ";
	C[0][0]=1;
	for(int i=1;i<=50;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	i64 ans=0;
	for(int i=1;i<=len;i++){
		for(int j=0;j<a[i];j++){
			if(buk[j]){
				buk[j]--;
				ans+=getmul(len-i);
				buk[j]++;
			}
		}
		buk[a[i]]--;
	}
	cout<<ans<<endl;
	return 0;
}