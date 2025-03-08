#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100004],tot,maxx;
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tot += a[i];
		maxx = max(a[i],maxx);
	}
	if (tot % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}
	if (maxx * 2 > tot) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}
