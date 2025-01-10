#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e5 + 5, mod = 1e9 + 7;

struct node {
	int id, d;
} a[M];

bool cmp(node a, node b) {
	return a.id < b.id;
}

int qpow(int a, int b) {
	if (b < 0) return 1;
	int ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1; 
	}
	return ans;
}

signed main() { 
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	cin.tie(0); ios::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		int n, m, v; cin >> n >> m >> v;
		
		bool t = 1; 
		for (int i = 1; i <= m; i++) { 
			cin >> a[i].id >> a[i].d; 
			if (a[i].id != i) t = 0; 
		} 
		
//		if (t && n == m) {
//			cout << qpow(v -;
//			continue; 
//		} 
		
		if (m == 1) {
//			cout << 2 * (n - 1 ) << " "   << v << " "; 
			cout << qpow(v, 2 *(n - 1)) << "\n";
			continue; 
		} 
		sort(a + 1, a + 1 + m, cmp);
		
		int ans = 1, len = 0;
		for (int i = 1; i <= m + 1; i ++) {
			if (a[i].id == a[i - 1].id) {
				ans = 0;
				break;
			} 
			if (a[i].id == a[i - 1].id + 1) {
				len ++; 
			} else {
				(ans *= (qpow(v - 1, len - 1) * len % mod + 1) % mod) %= mod;
				len = 0;
				//(ans *= qpow(v, a[i].id - a[i - 1].id + 1)) %= mod;
			} 
		}
		//cout << n - a[m].id << "\n";
		(ans *= qpow(v, (n - a[m].id) * 2 - 1)) %= mod;
		cout << ans << "\n";
	} 
	return 0;
}
