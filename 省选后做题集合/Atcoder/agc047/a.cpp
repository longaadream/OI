#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=30;
int f[N][N];
int main(){
	int n;
	cin>>n;
	i64 ans=0;
	for(int i=1;i<=n;i++){
		double a;
		cin>>a;
		i64 tmp=(1ll*1e9*a0.8);
		int pos1=0;
		while(tmp%2==0) tmp/=2,pos1++;
		int pos2=0;
		while(tmp%5==0) tmp/=5,pos2++;
		ans+=f[max(18-pos1,0)][max(18-pos2,0)];
		for(int i=0;i<=min(pos1,18);i++){
			for(int j=0;j<=min(pos2,18);j++){
				f[i][j]++;
			}
		}
	}
	cout<<ans;
	return 0;
}