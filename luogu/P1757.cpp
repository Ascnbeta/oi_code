#include <bits/stdc++.h>
using namespace std;
long long ans;
int n,m;
vector<int> v[1000],w[1004];
bool g[104];
int k;
int dp[1004];
int main () {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		v[c].push_back(b);
		w[c].push_back(a);
		if (!g[c]) k++;
		g[c] = true;
	}
	memset(dp,0xcf,sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = m; j >= 0; j--) {
			for (int k = 0; k < w[i].size(); k++) {
				if (j >= w[i][k]) {
					dp[j] = max(dp[j],dp[j-w[i][k]]+v[i][k]);
				}
			}
		}
	}
	ans = INT_MIN;
	for (int i = 0; i <= m; i++) {
		ans = max((long long)dp[i],ans);
	}
	cout << ans << '\n';
	return 0;
}