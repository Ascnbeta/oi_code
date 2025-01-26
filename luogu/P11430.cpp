#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int p[5004],t[5004],o[5004];
int f[5004],g[5004];
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> t[i] >> o[i];
		for (int j = 0; j <= m; j++) {
			f[j] = g[j];
		}
		for (int j = t[i]; j <= m; j++) {
			f[j] = max(f[j],f[j-t[i]]+o[i]);
		}
		for (int j = p[i]; j <= m; j++) {
			g[j] = max(g[j],f[j-p[i]]);
		}
	}
	for (int i = 0; i <= m; i++) ans = max(g[i],ans);
	cout << ans << '\n';
	return 0;
}