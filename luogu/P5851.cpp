#include <bits/stdc++.h>
using namespace std;
int n,m;
int w[45004],l[45004],r[45004];
int f[305][305],g[305][305][305];
int max(int x,int y) {
	return (x>y)?x:y;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> w[i] >> l[i] >> r[i];
		for (int j = l[i]; j <= r[i]; j++) {
			g[l[i]][r[i]][j] = w[i];
		}
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j; k++) {
				g[i][j][k] = max(g[i][j][k],max(g[i+1][j][k],g[i][j-1][k]));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i][i] = g[i][i][i];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j; k++) {
				f[i][j] = max(f[i][j],f[i][k-1]+f[k+1][j]+g[i][j][k]);
			}
		}
	}
	cout << f[1][n] << '\n';
	return 0;
}