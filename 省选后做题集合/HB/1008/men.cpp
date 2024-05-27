#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using i128=__int128;
bool Mbe;
const int N = 1e6 + 5;
struct node
{
    int x,y,v;
}v1[N],v2[N];
int s1, s2, n, q;
bool Med;
inline int read() {
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}

signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    n = read(); q = read();
    clock_t be = clock();
    int lst = 0;
    while(q--){
        int op = read();
        if(op == 1) {
            int x1 = read() ^ lst, y1 = read() ^ lst, k = read() ^ lst;
            for(x2=n2++;x2&&c2[x2].v>k;x2--)　c2[x2+1]=c2[x2];　
            c2[x2+1]=(node){x1,y1,k};
            if(n2>=800)
 　         {
   　           for(re int i=n1,j=n2,i1=(n1+=n2);i1;i1--)
                {
           　　     if(（!j)||(i&&(c1[i].v>c2[j].v)）)c1[i1]=c1[i],i--;
                 　 else c1[i1]=c2[j],j--;
                }n2=0;
            }
        }
    }
	std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}