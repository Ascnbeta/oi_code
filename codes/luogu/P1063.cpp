#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[204];
int dp[204][204];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= 2 * n - 1; i++) {
			int j = i + len - 1;
			for (int k = i; k < j; k++) {
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) ans = max(ans,dp[i][i+n-1]);
	cout << ans << '\n';
	return 0;
}