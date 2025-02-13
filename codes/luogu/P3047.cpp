#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+10;
int n,k;
vector<int> e[maxn];
int c[maxn];
int f[maxn][25],g[maxn][25];
void dfs1(int u,int fa) {
	for (int i = 0; i <= k; i++) {
		f[u][i] = c[u];
	}
	for (auto &v : e[u]) {
		if (v == fa) continue;
		dfs1(v,u);
		for (int i = 1; i <= k; i++) {
			f[u][i] += f[v][i-1];
		}
	}
}
void dfs2(int u,int fa) {
	for (auto v : e[u]) {
		if (v == fa) continue;
		for (int i = k; i >= 2; i--) {
			f[v][i] -= f[v][i-2];
			f[v][i] += f[u][i-1];
		}
		f[v][1] += f[u][0];
		dfs2(v,u);
	}
}
signed main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs1(1,0);
	// cout << f[1][k] << '\n';
	// cout << "debug: " << '\n';
	// for (int i = 2; i <= n; i++) {
	// 	cout << sum[i] << '\n';
	// }
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		g[i][j] = f[i][j];
	// 	}
	// }
	dfs2(1,0);
	for (int i = 1; i <= n; i++) {
		cout << f[i][k] << '\n';
	}
	return 0;
}