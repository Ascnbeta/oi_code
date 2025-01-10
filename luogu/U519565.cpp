#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int f[20][20];
signed main () {
	cin >> n >> m;
	f[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			f[i][j] = f[i][j-1] + f[i-1][j]; 
		}
	}
	cout << f[n][m] << '\n';
	return 0;
}