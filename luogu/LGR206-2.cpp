#include <bits/stdc++.h>
using namespace std;
int n,q;
int a[1000004],sum[1000004];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	while (q--) {
		int l,r,k;
		cin >> l >> r >> k;
		int s = sum[r] - sum[l-1];
		if (s == r - l + 1) { // all 1
			 int p = 1;
			 if (s - p == k) {
			 	cout << 0 << '\n';
			 }else if (s - p > k) {
			 	cout << 1 + s - p - k << '\n';
			 }else {
			 	cout << -1 << '\n';
			 }
		}else{
			int p = 0;
			if (s - p == k) {
				cout << 0 << '\n';
			}else if (s - p > k) {
				if (s >= s - p - k) cout << s - p - k << '\n';
				else cout << -1 << '\n';
			}else{
				int c0 = r - l + 1 - s;
				if (k - (s - p) <= c0 - 1) {
					cout << k - (s - p) << '\n';
				}else{
					cout << -1 << '\n';
				}
			}
		}
	}
	return 0;
}