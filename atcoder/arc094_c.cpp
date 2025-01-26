#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,sum;
int a[200005],b[200005];
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		sum += b[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i]>b[i]) {
			ans = max(ans,sum-b[i]);
		}
	}
	cout << ans << '\n';
	return 0;
}