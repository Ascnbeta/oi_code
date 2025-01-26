#include <bits/stdc++.h>
#define int long long
using namespace std;
int f,v,ans;
int a[103][103];
int dp[103][103];
vector<int> vec;
void dfs(int x,int p) {
	if (p == 0) {
		for (int i = vec.size()-1;i >= 0; i--) {
			cout << vec[i] << ' ';
		}
		exit(0);
	}
	for (int i = 1; i <= v; i++) {
		if (dp[p][i] == x) {
			vec.push_back(i);
			dfs(x-a[p][i],p-1);
			vec.pop_back();
		}
	} 
}
signed main () {
	cin >> f >> v;
	for (int i = 1; i <= f; i++) {
		for (int j = 1; j <= v; j++) {
			cin >> a[i][j];
		}
	}
	//memset(dp,0xcf,sizeof(dp));
	for (int j = 1; j <= v; j++) {
		dp[1][j] = a[1][j];
	}
	for (int i = 2; i <= f; i++) {
		for (int j = i; j <= v; j++) {
			for (int k = i-1; k < j; k++) {
				dp[i][j] = max(dp[i][j],dp[i-1][k]+a[i][j]);
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		ans = max(dp[f][i],ans);
	}
	cout << ans << '\n';
	dfs(ans,f);
	return 0;
}