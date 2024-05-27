#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
using pli=std::pair<i64,int>;
// using i128=__int128;
bool Mbe;
const int N = 1e5 + 5, mod = 19;
i64 n;
int m;
int ans,cnt=0;
int val[N], f[N][2];
bool Med;
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
template<class T>inline bool up(T &a,const T b){return (a <= b && ((a = b) + 1));}
template<class T>inline bool down(T &a,const T b){return (a > b && ((a = b) + 1));}
int dfs2(int now,int all,bool ck)
    {
        if(now==0&&ck)
        {
            return 1;
        }
        else if(now==0)
        {
            return 0;
        }
        if(f[now][ck]!=-1) return f[now][ck];
        f[now][ck]=0;
        int sum=n-now;
        for(int i=1;i<=all;i++)
        {
            if(now-val[i]>=0&&sum%val[i]==0)
            {
                f[now][ck]+=dfs2(now-val[i],all,ck|(i==all));
                f[now][ck]%=mod;
            }
        }
        return f[now][ck];
    }
    void dfs(int now)
    {
        for(int i=1;i<=n;i++)
            f[i][0]=f[i][1]=-1;
        ans+=dfs2(n,now,0);
        ans%=mod;
        cnt++;
        for(int i=2;i<=m;i++)
        {
            if(val[now]*i<=n)
            {
                val[now+1]=val[now]*i;
                dfs(now+1);
            }
        }
    }
    void solve()
    {
        val[1]=1;
        dfs(1);
        std::cout << ans << endl;
    }
signed main() {
	freopen("zhuangzi.in","r",stdin);
	freopen("zhuangzi.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	clock_t be = clock();
	n = read(), m = read();
    if(n <= 500){
        solve();
    }else puts("0");
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}