#include <bits/stdc++.h>
using namespace std;
int n;
int dp[50][50];
int rt[50][50];
bool vis[50];
void solve(int l,int r){
	if (l > r || vis[rt[l][r]]) return; 
	cout << rt[l][r] << ' ';
	vis[rt[l][r]] = true;
	if (l == r) return;
	solve(l,rt[l][r]-1);
	solve(rt[l][r]+1,r);
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> dp[i][i],rt[i][i] = i;
	for (int i = 1; i <= n+1; i++) dp[i][i-1] = 1;
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j; k++) {
				if (dp[i][k-1]*dp[k+1][j]+dp[k][k] > dp[i][j]) {
					dp[i][j] = max(dp[i][j],dp[i][k-1]*dp[k+1][j]+dp[k][k]);
					rt[i][j] = k;
				}
			}
		}
	}
	cout << dp[1][n] << '\n';
	solve(1,n);
	return 0;
}