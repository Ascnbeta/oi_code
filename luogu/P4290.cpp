#include <bits/stdc++.h>
using namespace std;
int w,i,n,g;
string a[20],b[20],c[20],d[20],t;
bool dp[204][204][6]; //w -> 1,i -> 2,n -> 3, g -> 4
int f(char s) {
	if (s == 'W') return 1;
	if (s == 'I') return 2;
	if (s == 'N') return 3;
	if (s == 'G') return 4;
}
char h(int s) {
	if (s == 1) return 'W';
	if (s == 2) return 'I';
	if (s == 3) return 'N';
	if (s == 4) return 'G';
}
int main () {
	cin >> w >> i >> n >> g;
	for (int j = 1; j <= w; j++) cin >> a[j];
	for (int j = 1; j <= i; j++) cin >> b[j];
	for (int j = 1; j <= n; j++) cin >> c[j];
	for (int j = 1; j <= g; j++) cin >> d[j];
	cin >> t;
	int lth = t.size();
	t = ' ' + t;
	// cout << t << '\n';
	for (int j = 1; j <= lth; j++) dp[j][j][f(t[j])] = true;
	for (int len = 2; len <= lth; len++) {
		for (int j = 1; j + len - 1 <= lth; j++) {
			int k = j + len - 1;
			for (int m = j; m < k; m++) {
				for (int l = 1; l <= w; l++) {
					int x = f(a[l][0]),y = f(a[l][1]);
					if (dp[j][m][x]&&dp[m+1][k][y]) {
						dp[j][k][1] = true;
						break;
					}
					
				}
				for (int l = 1; l <= i; l++) {
					int x = f(b[l][0]),y = f(b[l][1]);
					if (dp[j][m][x]&&dp[m+1][k][y]) {
						dp[j][k][2] = true;
						break;
					};
				}
				for (int l = 1; l <= n; l++) {
					int x = f(c[l][0]),y = f(c[l][1]);
					if (dp[j][m][x]&&dp[m+1][k][y]) {
						dp[j][k][3] = true;
						break;
					}
				}
				for (int l = 1; l <= g; l++) {
					int x = f(d[l][0]),y = f(d[l][1]);
					if (dp[j][m][x]&&dp[m+1][k][y]) {
						dp[j][k][4] = true;
						break;
					}
				}
			}
			
		}
	}
	int cnt = 0;
	for (int j = 1; j <= 4; j++) {
		if (dp[1][lth][j]) {
			cout << h(j);
			++cnt;
		}
	}
	if (cnt == 0) cout << "The name is wrong!" << '\n';
	return 0;
}