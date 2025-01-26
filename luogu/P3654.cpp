#include <bits/stdc++.h>
using namespace std;
int r,c,k;
int d[105][105];
char ch;
int ans;
int main () {
	cin >> r >> c >>k ;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> ch;
			if (ch == '#') {
				d[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (d[i][j] == 1) continue;
			bool x = false, y = false;
			for (int l = 1; l <= k-1; l++) {
				if (j + l > c || d[i][j+l] == 1) {
					x = true;
					break;
				}
			} 
			for (int l = 1; l <= k-1; l++) {
				if (i + l > r || d[i+l][j] == 1) {
					y = true;
					break;
				}
			}
			if (!x) ans++;
			if (!y) ans++;
		}
	}
	if (k == 1) {
		cout << ans / 2 << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
