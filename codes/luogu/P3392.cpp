#include <bits/stdc++.h>
using namespace std;
int n,m;
char mp[56][56];
int ans = 0x3f3f3f3f;
int main () {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <=m ;j++) {
			cin >> mp[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n-2; i++) {
		for (int j = i + 1; j <= n-1; j++) {
			cnt = 0;
			for (int k = 1; k <= i; k++) {
				for (int l = 1; l <= m; l++) {
					if (mp[k][l] != 'W') ++cnt;
				}
			}
			for (int k = i+1; k <= j; k++) {
				for (int l = 1; l <= m; l++) {
					if (mp[k][l] != 'B') ++cnt;
				}
			}
			for (int k = j+1; k <= n; k++) {
				for (int l = 1; l <= m; l++) {
					if (mp[k][l] != 'R') ++cnt;
				}
			}
			ans = min(ans,cnt);
		}
	}
	cout << ans << endl;
	return 0;
}
