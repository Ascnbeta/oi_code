#include <bits/stdc++.h>
using namespace std;
const int maxn = 53;
int m,n;
int a[maxn][maxn];
int f[maxn<<1][maxn][maxn];
int main () {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m+n-2; i++) {
		for (int x1 = 1; x1 <= m; x1++) {
			for (int x2 = 1; x2 <= m; x2++) {
				if (i - x1 + 2 < 1 || i - x2 + 2 < 1 || i - x1 + 2 > n || i - x2 + 2 > n) continue;
				int tmp;
				if (x1 == x2) {
					tmp = a[x1][i-x1+2];
				}else{
					tmp = a[x1][i-x1+2]+a[x2][i-x2+2];
				}
				f[i][x1][x2] = max(max(f[i-1][x1][x2],f[i-1][x1-1][x2]),max(f[i-1][x1][x2-1],f[i-1][x1-1][x2-1]))+tmp;
			}
		}
	}
	cout << f[m+n-2][m][m] << '\n';
	return 0;
}