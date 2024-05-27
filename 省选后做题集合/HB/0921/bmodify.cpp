#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e4+5,inf=1e9,M=1e7+5;
int n, m, s[N], p[N], k[N];
i64 dp[N][2][55], tree[M];
int ls[M], rs[M], nw, tot, rt[55][2], single;
std::vector<int> v[N];
bool Med;
inline int read() {
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+(c^48);c=getchar();}
    return x*f;
}
void pushup(int x){
    tree[x] = tree[ls[x]] + tree[rs[x]];
}
void modify(int &tr, int pos, int l, int r, int det){
    if(!tr) tr = ++nw;
    if(l == r){
        tree[tr]++;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos<=mid) modify(ls[tr], pos, l, mid, det);
    else modify(rs[tr], pos, mid + 1, r, det);
    pushup(tr);
}
void eter(int &tr, int pos, int l, int r, int det){
    if(!tr) tr = ++nw;
    if(l == r){
        tree[tr]=1;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos<=mid) modify(ls[tr], pos, l, mid, det);
    else modify(rs[tr], pos, mid + 1, r, det);
    pushup(tr);
}
void eter(int &tr,int pos){
    eter(tr, pos, 0, tot, det);
}
void modify(int &tr,int pos, int det){
    modify(tr, pos, 0, tot, det);
}
i64 query(int &tr,int ll,int rr, int l, int r){
    if(!tr) tr = ++nw;
    if(l>=ll&&r<=rr){
        return tree[tr];
    }
    int mid = (l + r) >> 1;
    i64 ans = 0;
    if(ll<=mid) ans += query(ls[tr], ll, rr, l, mid);
    if(rr>=mid + 1) ans+= query(rs[tr], ll, rr, mid + 1, r);
    return ans;  
}
i64 query(int &tr, int ll, int rr){
    return query(tr, ll, rr, 0, tot);
}
signed main() {
    std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
    int tt = read();
    clock_t be=clock();
    for(int _ = 1; _ <= tt; _++) {
        n = read(), m = read();
        memset(tree, 0, sizeof tree);
        memset(ls, 0, sizeof ls);
        memset(rs, 0, sizeof rs);
        memset(k, 0, sizeof k);
        nw = single = 0;
        for(int i = 0; i <= m + 1; i ++){
            rt[i][0] = rt[i][1] = 0;
        }
        std::vector<int> su, pu;
        for(int i = 0; i < n; i ++){
            s[i] = read(), p[i] = read();
            su.push_back(s[i]), pu.push_back(p[i]);
        }
        std::sort(su.begin(), su.end()), sort(pu.begin(), pu.end());
        pu.erase(std::unique(pu.begin(), pu.end()), pu.end());
        for(int i = 0; i < n; i ++){
            s[i] = std::lower_bound(su.begin(), su.end(), s[i]) - su.begin();
            p[i] = std::lower_bound(pu.begin(), pu.end(), p[i]) - pu.begin();
            k[s[i]] = p[i];
        }
        tot=(int)pu.size();
        for(int i = 1; i < (int)su.size(); i ++){
            if(k[i]>0) dp[i][1][1] += query(single, 0, k[i] - 1);
            if(k[i] < tot - 1) dp[i][0][1] += query(single, k[i] + 1, tot - 1);
            eter(single, k[i]);
            for(int j = 1; j <= m + 1; j ++){
                dp[i][1][j] += query(rt[j - 1][0], k[i] + 1, tot - 1);
                dp[i][1][j] += query(rt[j - 1][1], 0, k[i] - 1);
                dp[i][1][j] -= query(rt[i - 1][])
            }
        }
        std::cout<<"Case #"<<_<<": "<< (dp[n - 1][0][m + 1] + dp[n - 1][1][m + 1])<<endl;
    }
    std::cerr<<clock()-be<<"ms"<<endl;
    return 0;
}
/*
3
6 1
320 3
306 1
401 3
325 4
393 5
380 2
4 1
101 3
102 2
103 2
104 4
3 0
102 2
101 1
103 3
*/