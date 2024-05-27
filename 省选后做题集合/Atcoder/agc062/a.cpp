#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();};
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int main(){
	int tt=read();
	while(tt--){
		read();
		string a;
		cin>>a;
		if(a[a.size()-1]=='A') {puts("A");continue;}
		int flg=0;
		for(int i=a.size()-1;~i;i--){
			if(a[i]=='A'){
				for(int j=0;j<i;j++){
					if(a[j]=='B') flg=1; 
				}
				goto end;
			}
		}
		end:{}
		if(flg) puts("A"); else puts("B");
	}	
	return 0;
}