#include <bits/stdc++.h>
using namespace std;
const int mod = 19650827;
int n,a[1200];
int dp[1200][1200],ans = INT_MIN;
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i],dp[i][i] = 1;
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			if (a[i] < a[i+1]) dp[i][j] = (dp[i][j] + dp[i+1][j]) % mod;
			if (a[i] < a[j] && i + 1 != j) dp[i][j] = (dp[i][j] + dp[j][i+1]) % mod;
			if (a[j] > a[i]) dp[j][i] = (dp[j][i] + dp[i][j-1]) % mod;
			if (a[j] > a[j-1] && j - 1 != i) dp[j][i] = (dp[j][i] + dp[j-1][i]) % mod; 
		}
	}
	cout << (dp[1][n] + dp[n][1]) % mod << '\n';
	return 0;
}