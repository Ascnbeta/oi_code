#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 5;

int n;

struct E {
	int v, nxt;
}e[N << 1];
int hd[N], cnt = 1;

void add(int u, int v) {
	e[++cnt] = (E){v, hd[u]};
	hd[u] = cnt;
}

int dep[N], t, f[N][35], son[N], flagA = 1;

void init(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for (int i = hd[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == fa) continue;
		son[u]++;
		f[v][0] = u;
		for (int j = 1; j <= t; j++) f[v][j] = f[f[v][j - 1]][j - 1];
		init(v, u);
	}
	if (son[u] > 1) flagA = 0;
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = t; i >= 0; i--) if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	if (x == y) return x;
	for (int i = t; i >= 0; i--) {
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}

signed main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	t = log2(n) + 1;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	init(1, 0);
	if (flagA) {
		int q;
		cin >> q;
		for (int i = 1; i <= q; i++) {
			int l, r, k;
			cin >> l >> r >> k;
			priority_queue<int> q;
			for (int i = l; i <= r; i++) q.push(dep[i]);
			k--;
			while (k--) q.pop();
			cout << q.top() << '\n';
		}
		return 0;
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		int ans = 0, fa;
//		if (q <= 500 && n <= 500) {
		for (int j = l; j <= r - k + 1; j++) {
			fa = j;
			for (int idx = j + 1; idx <= j + k - 1; idx++) {
				fa = lca(fa, idx);
			}
			ans = max(ans, dep[fa]);
		}
		cout << ans << '\n';
//			continue;
//		}
		
//		fa = l;
//		for (int i = l; i <= r; i++) {
//			fa = lca(i, fa);
//		}
//		cout << dep[fa] << '\n';
	}
	return 0;
}

