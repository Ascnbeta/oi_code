#include <bits/stdc++.h>
using namespace std;
int h,w;
char mp[504][504],r[504][504],b[504][504];
int main () {
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> mp[i][j];
		}
	}
	for (int i = 1; i <= h; i++) {
		if (i % 2 == 0) {
			r[i][1] = '#',b[i][1] = '.';
			for (int j = 2; j < w; j++) {
				r[i][j] = '#',b[i][j] = mp[i][j];
			}
			r[i][w] = '.',b[i][w] = '#';
		}else{
			r[i][1] = '#',b[i][1] = '.';
			for (int j = 2; j < w; j++) {
				r[i][j] = mp[i][j],b[i][j] = '#';
			}
			r[i][w] = '.',b[i][w] = '#';
		}
	}
	for (int i = 1; i <= h; i ++) {
		for (int j = 1; j <= w; j++) {
			cout << r[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 1; i <= h; i ++) {
		for (int j = 1; j <= w; j++) {
			cout << b[i][j];
		}
		cout << '\n';
	}
	return 0;
}