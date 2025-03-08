#include <bits/stdc++.h>
using namespace std;
int p,q;
int a[103];
int dp[1004][1004];
int main () {
	cin >> p >> q;
	for (int i = 1; i <= q; i++) {
		cin >> a[i];
	}
	a[q+1] = p+1;
	for (int len = 1; len <= q; len++){
		for (int i = 1; i<= q; i++) {
			int j = i + len - 1;
			dp[i][j] = 0x3f3f3f3f;
			for (int k = i; k <= j; k++) {
				dp[i][j] = min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[j+1]-a[i-1]-2);
			}
		}
	}
	cout << dp[1][q] << '\n';
	return 0;
}