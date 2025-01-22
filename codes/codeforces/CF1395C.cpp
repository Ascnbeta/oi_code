#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[205],b[205];
int res[205][205];
bool check(int s) {
	for (int i = 1; i <= n; i++) {
		bool f = false;
		for (int j = 1; j <= m; j++) {
			if ((res[i][j] | s) == s) {
				f = true;
			}
		}
		if (!f) return false;
	}
	return true;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			res[i][j] = a[i] & b[j];
//			res1[i][j] = Bit(bres[i][j]);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << res[i][j] << ' '; 
//		}
//		cout << "\n";
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << bres[i][j] << ' '; 
//		}
//		cout << "\n";
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << res1[i][j] << ' '; 
//		}
//		cout << "\n";
//	}
	for (int i = 0; i < 512; i++) {
		if (check(i)) {
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
} 
