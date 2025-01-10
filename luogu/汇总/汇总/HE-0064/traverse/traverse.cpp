#include <iostream>
#include <cstdio>
using namespace std;
const long long mod = 1e9 + 7;
int c, t;
int n, k;
int x[500005], y[500005];
long long f[500005], fac[500005], fav[500005];
struct sss{
	int t, ne;
}e[500005];
int h[500005], cnt;
inline void add(int u, int v) {
	e[++cnt].t = v;
	e[cnt].ne = h[u];
	h[u] = cnt;
}
inline long long ksm(long long a, long long b) {
	long long ans = 1;
	while(b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
void dfs(int x, int fa, int o) {
	f[x] = 1;
	for (int i = h[x]; i; i = e[i].ne) {
		int u = e[i].t;
		if (u == fa || u == o) continue;
		dfs(u, x, o);
	}
	long long now = 1, sum = 0;
	for (int i = h[x]; i; i = e[i].ne) {
		int u = e[i].t;
		if (u == fa || u == o) continue;
		sum++;
		now = now * f[u] % mod;
	}
	now = now * fac[sum] % mod;
	f[x] = now;
}
int main() {
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	fac[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		fac[i] = fac[i - 1] * i % mod;
		fav[i] = ksm(fac[i], mod - 2);
	}
	while(t--) {
		cin >> n >> k;
		bool hua = true;
		for (int i = 1; i <= n - 1; i++) {
			cin >> x[i] >> y[i];
			if (x[i] != 1 && y[i] != 1) hua = false;
			add(x[i], y[i]);
			add(y[i], x[i]);
		}
		if (k == 1) {
			int z;
			long long ans = 0;
			for (int i = 1; i <= k; i++) {
				cin >> z;
				dfs(x[z], 0, y[z]);
				long long sum = f[x[z]];
				dfs(y[z], 0, x[z]);
				sum = sum * f[y[z]] % mod;
				ans = (ans + sum) % mod;
			}
			cout << ans << '\n';
		} else {
			int z;
			for (int i = 1; i <= k; i++) cin >> z;
			if (!hua) {
				cout << 1 << '\n';
			} else {
				long long sum = fac[k] * fav[2] % mod * fav[k - 2] % mod;
				sum = sum * fac[n - 3] % mod;
				cout << (fac[n - 2] * k % mod - sum + mod) % mod << '\n';
			}
		}
		for (int i = 1; i <= n; i++) h[i] = 0;
		cnt = 0;
	}
	return 0;
}