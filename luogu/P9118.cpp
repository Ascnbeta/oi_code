#include <bits/stdc++.h>
#define int long long
using namespace std;
long long n,k,ans = 1,p[1000010];
map<long long,int> m;
inline int sq(int x) {
	int l = 1, r = x;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (mid*mid >= x) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}
signed main () {
	cin >> n >> k;
	//~ cout << sq(n) << '\n';
	if (k == 1) {
		cout << n << '\n';
	}
	if (k == 2) {
		ans = sq(n);
		k = 3;
		for (int i = 1; i <= 1000; i++) p[i*i] = 1;
		for (int i = 2; ; i++) {
			if (m.find(i) != m.end() || p[i]) continue;
			int x = 1;
			bool f = false;
			for (int j = 1; j <= k; j++) {
				if (x > n / i) {
					f = true;
					break;
				}
				x *= i;
			}
			if (f) break;
			for (int j = k; ;j++) {
				if (m.find(x) == m.end() && j % 2 == 1) ++ans;
				m[x] = 1;
				if (x > n / i) break;
				x *= i;
			}
		}
	}
	if (k >= 3) {
		for (int i = 2; ; i++) {
			if (m.find(i) != m.end()) continue;
			int x = 1;
			bool f = false;
			for (int j = 1; j <= k; j++) {
				if (x > n / i) {
					f = true;
					break;
				}
				x *= i;
			}
			if (f) break;
			while(1) {
				if (m.find(x) == m.end()) ++ans;
				m[x] = 1;
				if (x > n / i) break;
				x *= i;
			}
		}
		
	}
	if (k != 1)cout << ans << '\n';
	return 0;
}
