#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=4e5+5;
int n,cnt[N],a[N],m,base[N],tot,val[N],res[N],sq,bl[N];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
struct Q{
	int l,r,t,id;
};
struct M{
	int pos,val;
};
Q o1[N];
M o2[N];
int t1,t2;
void upd(int pos,int det){
	cnt[pos]+=det;
}
void del(int pos){
	upd(val[pos],-1);
	val[pos]--;
	upd(val[pos],1);
}
void add(int pos){
	upd(val[pos],-1);
	val[pos]++;
	upd(val[pos],1);
}
void rev(int id,int t){
	if(o1[id].l<=o2[t].pos&&o2[t].pos<=o1[id].r){
		del(a[o2[t].pos]);
		add(o2[t].val);
	}
	swap(a[o2[t].pos],o2[t].val);
}
int checkans(){
	for(int i=1;i<=0x7fffffff;i++){
		if(!cnt[i]) return i;
	}
}
signed main(){
	cnt[0]=0x7fffffff;
	n=read(),m=read();
	sq=pow(n,0.666666);
	for(int i=1;i<=n;i++){
		bl[i]=(i-1)/sq+1;
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
		base[++tot]=a[i];	
	}
	for(int i=1;i<=m;i++){
		int op=read();
		if(op==1){
			o1[++t1]=(Q){read(),read(),t2,t1};				
		}else{
			int pos=read(),val=read();
			o2[++t2]=(M){pos,val};
			base[++tot]=val;
		}
	}
	sort(base+1,base+tot+1);
	tot=unique(base+1,base+tot+1)-(base+1);
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(base+1,base+tot+1,a[i])-base;
	}
	for(int i=1;i<=t2;i++){
		o2[i].val=lower_bound(base+1,base+tot+1,o2[i].val)-base;
	}
	sort(o1+1,o1+t1+1,[](Q a,Q b){
		return (bl[a.l]^bl[b.l])?(a.l<b.l):((bl[a.r]^bl[b.r])?a.r<b.r:a.t<b.t);	
	});
	int l=1,r=0,t=0;
	for(int i=1;i<=t1;i++){
		int ql=o1[i].l,qr=o1[i].r,qt=o1[i].t;
		while(l<ql) del(a[l++]);
		while(l>ql) add(a[--l]);
		while(r<qr) add(a[++r]);
		while(r>qr) del(a[r--]);
		while(t<qt) rev(i,++t);
		while(t>qt) rev(i,t--);	
		res[o1[i].id]=checkans();
	}
	for(int i=1;i<=t1;i++){
		cout<<res[i]<<"\n";
	}
	return 0;
}
