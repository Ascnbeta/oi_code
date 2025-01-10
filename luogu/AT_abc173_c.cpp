#include <bits/stdc++.h>
using namespace std;
int h,w,q,hh = 1,ans;
char ch;
int m[10][10];
bool c[20];
int main () {
	cin >> h >> w >> q;
	for (int i = 1; i <=h ; i++) {
		for (int j = 1; j  <= w; j++) {
			cin >> ch;
			if (ch == '#') {
				m[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= h + w; i++) hh *= 2;
	hh--;
//	cout << hh << endl;
	for (int i = 0; i <= hh; i++) {
		int t = i,cnt = 1,sum = 0;
		for (int j = 1; j <= h + w; j++) {
			c[j] = false;
		}
		while (t) {
			if (t&1) {
				c[cnt] = true;
			}
			t>>=1;
			++cnt;
		}

		for (int j = 1; j <= h; j++) {
			for (int k = 1; k <= w; k++) {
				if (m[j][k] == 1 && (!c[j] && !c[h+k])) {
					++sum;
					
				}
			}
		}
		if (sum == q) {
			++ans;
//			for (int i = 1; i <= h + w; i++) {
//				cout << c[i] << ' ';
//			}
//			cout << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
