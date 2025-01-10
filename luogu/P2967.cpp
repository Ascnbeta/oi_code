#include <bits/stdc++.h>
using namespace std;
int n,V;
int g[53];
vector<int> p[53],v[53];//p是价格,v是价值
int dp[100004],dpt[100004];
int main () {
	cin >> n >> V;
	for (int i = 1; i <= n; i++) {
		cin >> g[i];
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			int y,z;
			cin >> y >> z;
			p[i].push_back(y);
			v[i].push_back(z);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= V; j++) dpt[j] = dp[j];//拷贝dp到dpt中
		for (int j = 0; j < p[i].size(); j++) {
			for (int k = V; k >= 0; k--) {
				if (k >= p[i][j]) {
					dpt[k] = max(dpt[k-p[i][j]]+v[i][j],dpt[k]);//对该主机游戏做01背包
				}
			}
		}
		for (int j = 0; j <= V; j++) {
			if (j >= g[i]) {
				dp[j] = max(dp[j],dpt[j-g[i]]);//对该主机做01背包
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= V; i++) ans = max(ans,dp[i]);
	cout << ans << '\n';
	return 0;
}