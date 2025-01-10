#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5, p = 1e9 + 7;

int T, n, m, v, c[N], d[N], a[N], b[N], vis[N], w[N];

int qkm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1ll) res = res * a % p;
		a = a * a % p;
		b >>= 1ll;
	}
	return res % p;
}

int ans;

bool check() {
	for (int i = 1; i <= n; i++) {
		w[i] = vis[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		if (w[i]) {
			if (a[i] == w[i]) {
				if (w[i + 1] && (w[i + 1] != b[i])) return 0;
				w[i + 1] = b[i];
			} 
		} 
	}
	return 1;
}

void dfs(int deep) {
	if (deep > n - 1) {
		if (check()) {
			ans = (ans + 1) % p; 
		} 
		return;
	}
	a[deep] = 1, b[deep] = 2;
	dfs(deep + 1);
	a[deep] = 1, b[deep] = 1;
	dfs(deep + 1);
	a[deep] = 2, b[deep] = 1;
	dfs(deep + 1);
	a[deep] = 2, b[deep] = 2;
	dfs(deep + 1);
	return; 
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	cin >> T;
	while (T--) {
		ans = 0;
		bool flag = 0;
		cin >> n >> m >> v;
		memset(vis, 0, sizeof vis);
		memset(c, 0, sizeof c);
		memset(d, 0, sizeof d);
		for (int i = 1; i <= m; i++) {
			cin >> c[i] >> d[i];	
		}
		if (n == m) {
			cout << qkm( ((v - 1ll) * v % p + 1ll) % p, n - 1ll) << '\n';
		} else if(m == 1) {
			cout << qkm(v, (2 * n  - 2) ) << '\n';
		} else if (n <= 12) {
			for (int i = 1; i <= n; i++) {
				if (vis[c[i]] && d[i] != vis[c[i]]) {
					flag = 1;
				}
				vis[c[i]] = d[i];
			}
			if (flag) {
				cout << 0 << '\n';
				continue; 
			}
			dfs(1);
			cout << ans << '\n';
		}
	}
	return 0;
} 
