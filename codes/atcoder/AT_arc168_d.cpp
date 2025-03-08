#include <bits/stdc++.h>
using namespace std;
int n,m;
int l[125030],r[125030];
int f[504][504],g[504][504][504];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> l[i] >> r[i];
	for (int i = 1; i <= m; i++) {
		for (int j = l[i];j <= r[i]; j++) {
			g[l[i]][r[i]][j] = 1;
		}
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j; k++) {
				g[i][j][k] |= (g[i+1][j][k]|g[i][j-1][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) f[i][i] = g[i][i][i];
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