#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 803;
const ll mod = 1e9+7;
int n,m,K;
int f[maxn][maxn][20][2];
ll ans;
inline void read(int &x) {
	int f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch == '-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
int a[maxn][maxn];
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	read(n),read(m),read(K);
	++K;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			read(a[i][j]);
			f[i][j][a[i][j]%K][1] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < K; k++) {
				f[i][j][k][1] = (f[i][j][k][1]+f[i-1][j][(k-a[i][j]+K)%K][0])%mod;
				f[i][j][k][1] = (f[i][j][k][1]+f[i][j-1][(k-a[i][j]+K)%K][0])%mod;
				f[i][j][k][0] = (f[i][j][k][0]+f[i-1][j][(k+a[i][j])%K][1])%mod;
				f[i][j][k][0] = (f[i][j][k][0]+f[i][j-1][(k+a[i][j])%K][1])%mod;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) ans = (ans+f[i][j][0][0])%mod;
	}
	printf("%lld",ans);
	return 0;	
}