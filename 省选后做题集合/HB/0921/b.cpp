#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
bool Mbe;
const int N=1e4+5;
i64 dp[N][55][2];
int UBIT[55][2][N], DBIT[64][2][N];
int shift[64][2][N],used[N];
bool Med;
inline int read() {
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+(c^48);c=getchar();}
    return x*f;
}
int query(int A[], int idx) {
    int sum = 0;
    while (idx)
        sum += A[idx], idx -= idx&(-idx);
    return sum;
}
void modify(int A[], int idx, int val, int L) {
    while (idx <= L)
        A[idx] += val, idx += idx&(-idx);
}
int main() {
    int n, m, x, y;
    int tt = read();
    for(int _ = 1; _ <= tt; _ ++){
        n = read(), m = read();
        std::vector<pii> D;
        std::map<int, int> R;
        for (int i = 0; i < n; i++) {
            x = read(), y = read();
            R[y] = 0;
            D.push_back(std::make_pair(x, y));
        }
        sort(D.begin(), D.end());
        int L = 1;
        for (std::map<int, int>::iterator it = R.begin();
            it != R.end(); it++)
            it->second = L++;
        for (int i = 0; i < n; i++)
            D[i].second = R[D[i].second];
        memset(UBIT, 0, sizeof(UBIT));
        memset(DBIT, 0, sizeof(DBIT));
        memset(shift, 0, sizeof(shift));		
        memset(used, 0, sizeof used);
        for (int i = 0; i < n; i++) {
            if (used[D[i].second] == 0) {
                shift[0][0][D[i].second] = -1;
                used[D[i].second] = 1;
            }
        }
        modify(UBIT[0][1], 1, 1, L);
        modify(UBIT[0][2], 1, 1, L);
        int ret = 0;
        if (m == 0) ret++;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= m; k++) {
                int dp0 = query(UBIT[k][0], D[i].second) + query(DBIT[k][0], L - D[i].second-1) - shift[k][0][D[i].second];
                int dp1 = query(UBIT[k][1], D[i].second) + query(DBIT[k][1], L - D[i].second-1) - shift[k][1][D[i].second];
                int dp2 = query(UBIT[k][2], D[i].second) + query(DBIT[k][2], L - D[i].second-1) - shift[k][2][D[i].second];
                shift[k][0][D[i].second] += dp0;
                shift[k][1][D[i].second] += dp1;
                shift[k][2][D[i].second] += dp2;
                if (k == m)	ret += dp0;
                if (dp2) {
                    modify(UBIT[k][0], D[i].second+1, dp2, L);
                    modify(UBIT[k+1][1], D[i].second+1, dp2, L);
                    modify(UBIT[k][2], D[i].second+1, dp2, L);
                }
                if (dp1) {
                    modify(DBIT[k][0], L - D[i].second, dp1, L);
                    modify(DBIT[k][1], L - D[i].second, dp1, L);
                    modify(DBIT[k+1][2], L - D[i].second, dp1, L);
                }
            }
        }
        std::cout << "Case "<< _ << ": " << ret << endl; 
    }
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