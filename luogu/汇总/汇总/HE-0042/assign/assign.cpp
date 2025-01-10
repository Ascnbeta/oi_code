#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m, v, c[N], d[N], a[N];
map < int, int > mp;
void solv1() {
	n--;
	memset(a, 0, sizeof(a));
	int ans = 1;
	for (int i = 1; i <= m; i++) a[c[i]] = d[i];
	int i;
	for (i = 1; i <= n; i++) {
		if (a[i] != 0) break;
		ans = (ans * 4) % MOD;
	}
	for (; i <= n;) {
		int j;
		for (j = i + 1; j <= n; j++) {
			if (a[j] != 0) break;
		}
		for (int k = 3; k - 2 <= j - i; k++) ans = (ans * k) % MOD;
		i = j;
	}
	cout << ans << endl;
}
long long qpow(long long x, long long y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	if (y & 1) {
		return (x * qpow(x, y - 1)) % MOD;
	} else {
		int tmp = qpow(x, y / 2);
		return tmp * tmp % MOD;
	}
}
void solv2() {
	cout << qpow(v, (n - 1) * 2) << endl;
}
void solv3() {
	cout << qpow((v * v - v + 1), n - 1) << endl;
}
signed main() {
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		mp.clear();
		bool flag = false;
		cin >> n >> m >> v;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &c[i], &d[i]);
			if (mp.count(c[i]))  {
				if (mp[c[i]] != d[i]) {
					cout << 0 << endl;
					flag = true;
					break;
				}
			}
			mp[c[i]] = d[i];
		}
		if (flag) continue;
		if (m == 1) solv2();
		else if (v == 2) solv1();
		else solv3();
	}
	return 0;
}
