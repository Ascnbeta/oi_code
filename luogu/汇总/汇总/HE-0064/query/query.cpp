#include <iostream>
#include <cstdio>
using namespace std;
int n, q;
struct sss{
	int t, ne;
}e[1000005];
int h[1000005], cnt;
inline void add(int u, int v) {
	e[++cnt].t = v;
	e[cnt].ne = h[u];
	h[u] = cnt;
}
int dep[500005], f[500005][21];
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1;
	f[x][0] = fa;
	for (int i = h[x]; i; i = e[i].ne) {
		int u = e[i].t;
		if (u == fa) continue;
		dfs(u, x);
	}
}
inline int lca(int x, int y) {
	if (x == y) return x;
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 9; i >= 0; i--) {
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 9; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
inline int w(int l, int r, int k) {
	int ma = 0;
	for (int i = l; i + k - 1 <= r; i++) {
		int lc = i;
		for (int j = i + 1; j <= i + k - 1; j++) {
			lc = lca(lc, j);
		}
		ma = max(ma, dep[lc]);
	}
	return ma;
}
int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x, y;
	for (int i = 1; i <= n - 1; i++) {
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	cin >> q;
	if (n <= 500 && q <= 500) {
		for (int j = 1; j <= 9; j++) {
			for (int i = 1; i <= n; i++) {
				f[i][j] = f[f[i][j - 1]][j - 1];
			}
		}
		int l, r, k;
		for (int i = 1; i <= q; i++) {
			cin >> l >> r >> k;
			cout << w(l, r, k) << '\n';
		}
	}
	
	return 0;
}