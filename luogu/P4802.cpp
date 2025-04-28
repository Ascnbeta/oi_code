#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n,m;
int e[maxn][maxn];
int f[(1<<maxn)][maxn];
int main () {
#ifdef LOCAL
	freopen("D:/codes/exe/a.in","r",stdin);
	freopen("D:/codes/exe/a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u][v] = max(e[u][v],w);
	}
	memset(f,0xc0,sizeof(f));
	f[1][0] = 0;
	for (int i = 1; i < (1<<n); i++) {
		if (i & 1) {
			for (int j = 0; j < n; j++) {
				if ((i>>j)&1) {
					for (int k = 1; k < n; k++) {
						if (((i>>k)&1) && e[j][k]) {
							f[i][k] = max(f[i][k],f[i^(1<<k)][j]+e[j][k]);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < (1<<n); i++) {
		if ((i&1) && (i&(1<<(n-1)))) {
			ans = max(ans,f[i][n-1]);
		}
	}
	cout << ans << '\n';
	return 0;
}