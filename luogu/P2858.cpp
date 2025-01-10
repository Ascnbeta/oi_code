#include <bits/stdc++.h>
using namespace std;
int n,a[2004];
int f[2004][2004];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int len = n; len >= 1; len--) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			f[i+1][j] = max(f[i+1][j],f[i][j]+a[i]*(n-len+1));
			f[i][j-1] = max(f[i][j-1],f[i][j]+a[j]*(n-len+1));
		}
	}
	long long ans = -1;
	for (int i = 1; i <= n; i++) ans = max(ans,(long long)f[i+1][i]);
	cout << ans << '\n';
	return 0;
}