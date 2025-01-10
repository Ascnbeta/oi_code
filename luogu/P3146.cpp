#include <bits/stdc++.h>
#define max(x,y) (x)>(y)?(x):(y)
using namespace std;
int n,ans = INT_MIN;
int a[250];
int dp[250][250];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) dp[i][i] = a[i];
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			for (int k = i; k < j; k++) {
				if (dp[i][k]==dp[k+1][j]&&dp[i][k]!=0) {
					// cout << i << ' ' << k << ' ' << k + 1 << ' ' << j << '\n';
					dp[i][j] = max(dp[i][j],dp[i][k]+1);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(dp[i][j],ans);
		}
	}
	cout << ans << '\n';
	return 0;
}