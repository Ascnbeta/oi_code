#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 +10;
int n;
string s1, s2, t1, t2;
string ans1, ans2;

void solve() {
	cin >> n;
	cin >> s1 >> s2 >> t1 >> t2;
	s1 = " " + s1; s2 = " " + s2;
	t1 = " " + t1; t2 = " " + t2;
	ans1 = s1; ans2 = s2;
	
	int i1 = 1, i2 = 1;
	int c01 = 0, c02 = 0, c11 = 0, c12 = 0;
	while (i1 <= n && i2 <= n) {
//		cerr << i1 << " " << i2 << endl;
		int j1 = i1, j2 = i2;
		if (i1 == 1 || t1[i1 - 1] == '0') {
			c01 = c11 = 0;
			while (t1[j1] == '1') {
				c01 += (s1[j1] == '0');
				c11 += (s1[j1] == '1');
				j1++;
			}
		}
		if (i2 == 1 || t2[i2 - 1] == '0') {
			c02 = c12 = 0;
			while (t2[j2] == '1') {
				c02 += (s2[j2] == '0');
				c12 += (s2[j2] == '1');
				j2++;
			}
		}
//		cerr << j1 << " " << j2 << " " << c01 << " " << c11 << " " << c02 << " " << c12 << endl; 
		bool b1 = 0, b2 = 0;
		if (t1[i1] == '0') {
			ans1[i1] = s1[i1];
			i1++;
			b1 = 1;
 		}
		if (t2[i2] == '0') {
			ans2[i2] = s2[i2];
			i2++;
			b2 = 1;
		}
		if (b1 && !b2) {
			if (s1[i1 - 1] == '0' && c02) {
				c02--;
				ans2[i1 - 1] = '0';
				i2++;
			}
			else if (s1[i1 - 1] == '1' && c12) {
				c12--;
				ans2[i1 - 1] = '1';
				i2++;
			}
			else if (c02) {
				c02--;
				ans2[i1 - 1] = '0';
				i2++;
			}
			else if (c12) {
				c12--;
				ans2[i1 - 1] = '1';
				i2++;
			}
//			else {
//				assert(0);
//			}
		}
		else if (b2 && !b1) {
			if (s2[i2 - 1] == '0' && c01) {
				c01--;
				ans1[i2 - 1] = '0';
				i1++;
			}
			else if (s2[i2 - 1] == '1' && c11) {
				c11--;
				ans1[i2 - 1] = '1';
				i1++;
			}
			else if (c01) {
				c01--;
				ans1[i2 - 1] = '0';
				i1++;
			}
			else if (c11) {
				c11--;
				ans1[i2 - 1] = '1';
				i1++;
			}
//			else {
//				assert(0);
//			}
		}
		else if (!b1 && !b2) {
			if (c01 && c02) {
				ans1[i1] = '0';
				ans2[i2] = '0';
				c01--; c02--;
			}
			else if (c11 && c12) {
//				cerr << i1 << " " << i2 << endl;
				ans1[i1] = '1';
				ans2[i2] = '1';
				c11--; c12--;
			}
			else {
				if (c01) {
					ans1[i1] = '0';
					c01--;
				}
				else {
					ans1[i1] = '1';
					c11--;
				}
				if (c02) {
					ans2[i2] = '0';
					c02--;
				}
				else {
					ans2[i2] = '1';
					c12--; 
				}
			}
			i1++; i2++;
		}
	}
	
//	cerr << endl << ans1 << endl << ans2 << endl;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (ans1[i] == ans2[i]);
	}
	
	cout << ans << '\n';
}

int main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}

/*
1
6
011101
111010
111010
101101
*/
