#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const long long mod = 1e9 + 7;
int t;
long long n, m, v;
long long c[100005], d[100005], a[1000005];
int main() {
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> m >> v;
		bool vv = false;
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= m; i++) {
			cin >> c[i] >> d[i];
			if (a[c[i]] != 0 && a[c[i]] != d[i]) {
				vv = true;
				break;
			}
			a[c[i]] = d[i];
		}
		if (vv) {
			cout << 0 << endl;
			continue;
		}
		long long ans = 1;
		for (int i = 1; i <= n - 1; i++) {
			long long sum = 0;
			if (a[i] != 0 && a[i + 1] != 0) {
				// cout << 1 << endl;
				sum = (1 + (v - 1) * v % mod) % mod;
				ans = ans * sum % mod;
			} else if (a[i] != 0) {
				sum = ((v - 1) % mod * v % mod + v) % mod;
				ans = ans * sum % mod;
			} else {
				ans = ans * v % mod * v % mod;
			}
		}
		cout << ans << endl;
		// for (int i = 1; i <= m; i++) {
		// 	a[c[i]] = 0;
		// }
	}
	return 0;
}