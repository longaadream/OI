#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using i64=long long;
const int N=3e5+5;
int a[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	int m=1<<n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m/2;i++){
		if(a[i]%(m/2)!=a[i+m/2]%(m/2)) return cout<<"No",0;
	}
	vector<int> op;
	for(int i=1;i<=m/2;i++){
		if(a[i]>=m/2){
			int r=a[i]-(m/2);
			int det=(m/2-1)^r;
			op.pb(det);
			op.pb(-1);
			for(int j=1;j<=m/2;j++){
				a[j]^=det;
				a[j]++;
			}
			a[i]=0;
		}
	}
	op.pb(a[1]);
	for(int i=2;i<=m/2;i++){
		a[i]^=a[1];
		if(a[i]!=i-1) return cout<<"No",0;
	}
	cout<<"Yes\n";
	int k=(int)op.size();
	cout<<k<<endl;
	for(int i=0;i<k;i++) cout<<op[i]<<" ";
	cout<<endl;
	return 0;
}