#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64=long long;
using u64=unsigned long long;
using u32=unsigned int;
using pii=std::pair<int,int>;
//using i128=__int128;
template<class T>inline void up(T &a, T b){if(a < b) a = b;}
template<class T>inline void down(T &a, T b){if(a > b) a = b;}
bool Mbe;
const int N = 51, inf = 1e9, mod = 1e9 + 7;
template<class T>inline void Mod(T &a){return (a > mod || a < 0) && ((a += mod) %= mod), void();}
int n;
i64 k;
struct Matrix
{
	i64 mat[N][N];
	Matrix(){memset(mat, 0, sizeof mat);for(int i = 1; i <= n; i ++) mat[i][i] = 1;}	
	Matrix operator*(const Matrix &b){
		Matrix res;
		for(int i = 1; i <= n; i ++){
			res.mat[i][i] = 0;
		}
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				for(int k = 1; k <= n; k ++){
					res.mat[i][j] += 1ll * mat[i][k] * b.mat[k][j] % mod;
					Mod(res.mat[i][j]);
				}
			}
		}
		return res;
	}
	i64 count(){
		i64 ans = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				ans += mat[i][j];
				Mod(ans);
			}
		}
		return ans;
	}
};
Matrix ori;
bool Med;
Matrix qpow(i64 b){
	Matrix res;
	while(b){
		if(b & 1) res = res * ori;
		ori = ori * ori;
		b >>= 1;
	}
	return res;
}
inline i64 read() {
	i64 x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
signed main() {
	// freopen("ni.in","r",stdin);
	// freopen("ni.out","w",stdout);
	std::cerr<<1.00*(&Med-&Mbe)/1024/1024<<"MB"<<endl;
	n = read(), k = read();
	clock_t be = clock();
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			ori.mat[i][j] = read();
		}
	}
	std::cout << qpow(k).count() << endl;
    std::cerr<<clock()-be<<"ms"<<endl;
	return 0;
}