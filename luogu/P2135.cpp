#include <bits/stdc++.h>
using namespace std;
int m,c[53],n[53],tot;
long long dp[53][53][1003];
int main () {
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> c[i];
	for (int i = 1; i <= m; i++) cin >> n[i],tot += n[i];
	for (int i = 1; i <= m; i++) {
		for (int k = 0; k <= tot; k++) {
			dp[i][i][k] = (n[i] + k) * (n[i] + k);
		}
	}
	for (int len = 2; len <= m; len++) {
		for (int i = 1; i + len - 1 <= m; i++) {
			int j = i + len - 1;
			for (int k = 0; k <= tot; k++) {
				dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][0]+(n[j]+k)*(n[j]+k));
			}
			for (int l = i; l < j - 1; l++){
				if (c[l] == c[j]) {
					for (int k = 0; k <= tot; k++) {
						dp[i][j][k] = max(dp[i][j][k],dp[i][l][n[j]+k]+dp[l+1][j-1][0]);
					}
				}
			}
		}
	}
	cout << dp[1][m][0] << '\n';
	return 0;
}