#include <bits/stdc++.h>
using namespace std;
int n,k;
int f[10004],a[104];
int main () {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i < a[j]) break;
			f[i] = max(f[i],i-f[i-a[j]]);
		}
	}
	cout << f[n] << '\n';
	return 0;
}