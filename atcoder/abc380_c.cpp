#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;
int main () {
	cin >> n >> k;
	cin >> s;
	s = ' ' + s;
	bool f = false;
	int cnt = 0;
	int l = 0,r = 0,rr = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			if (!f) {
				++cnt;
				f = true;
				if (cnt == k) {
					l = i;
				}
			}
			if (cnt == k) {
				s[i] = '0';
			}
		}else{
			if (f) {
				f = false;
				if (cnt == k) {
					r = i - 1;
				}else if (cnt == k - 1) {
					rr = i;
				}
			}
		}
	}
	if (r == 0) {
		r = n;
	}
	// cout << l << ' ' << r << ' ' << rr << '\n';
	for (int i = rr; i <= r - l + rr; i++) {
		s[i] = '1';
	}
	for (int i = 1; i <= n; i++) {
		cout << s[i];
	}
	return 0;
}