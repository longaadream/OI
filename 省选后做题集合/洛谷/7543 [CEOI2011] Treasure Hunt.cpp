#include<bits/stdc++.h>
using namespace std;
using i64=long long;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=4e5+5;
int n,idx[N],cnt,fa[N][20],dep[N],dis[N],f[N],len[N];
int Dis(int u){
	int p=(lower_bound(idx+1,idx+cnt+1,u)-idx);
	return dis[p]+u-idx[p];
}
int lcadis(int s,int t){
	int u=lower_bound(idx+1,idx+cnt+1,s)-idx,v=lower_bound(idx+1,idx+cnt+1,t)-idx;
	int p;
	if(u==v)return p=min(s,t);
	else{
		if(dep[u]<dep[v]) swap(u,v),swap(s,t);
		for(int i=19;~i;i--){
			if(dep[fa[u][i]]>dep[v]){
				u=fa[u][i];
			}
			if(fa[u][0]==v){
				p=min(f[u],t);
			}else{
				if(dep[u]!=dep[v]){
					u=fa[u][0];
				}
				for(int i=19;~i;i--){
					if(fa[u][i]!=fa[v][i]){
						u=fa[u][i],v=fa[v][i];
					}
				}
				p=min(f[u],f[v]);
			}
		}
	}
	return Dis(s)+Dis(t)-2*Dis(p);
}
signed main(){
	n=read();
	int lst=0;
	while(n--){
		char s[5];
		cin>>(s+1);
		if(s[1]=='P'){
			int u=read(),s=read();
			u^=lst,s^=lst;
			idx[cnt+1]=idx[cnt]+s;++cnt,f[cnt]=u,len[cnt]=s;
			int faa=lower_bound(idx+1,idx+cnt+1,u)-idx;
			fa[cnt][0]=faa,dep[cnt]=dep[faa]+1,dis[cnt]=Dis(u)+s;
			for(int i=1;i<20;i++) fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
		}else{
			int u=read(),v=read();
			u^=lst,v^=lst;
			int dist=lcadis(u,v),w=dist/2;
			if(Dis(u)<Dis(v)) swap(u,v),w=dist-w;
			w=Dis(u)-w;
			u=lower_bound(idx+1,idx+cnt+1,u)-idx;
			for(int i=19;~i;i--){
				if(dis[fa[u][i]]-len[fa[u][i]]>=w){
					u=fa[u][i];
				}
			}
			if(fa[u][0]&&dis[fa[u][0]]-len[fa[u][0]]>=w){
				u=fa[u][0];
			}		
			cout<<(lst=(idx[u]-dis[u]+w))<<'\n';
		}
	}
	return 0;
}
