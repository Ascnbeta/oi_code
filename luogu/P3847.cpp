#include <bits/stdc++.h>
using namespace std;
int n;
int c[3004];
int f[3004][3004];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			if (c[i] == c[j]) {
				f[i][j] = f[i+1][j-1];
			}else{
				f[i][j] = min(f[i+1][j]+1,min(f[i][j-1]+1,f[i+1][j-1]+1));
			}
		}
	}
	cout << f[1][n] << '\n';
	return 0;
}