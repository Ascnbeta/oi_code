#include <bits/stdc++.h>
using namespace std;
int n,r;
int main () {
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		int a,d;
		cin >> d >> a;
		if (d == 1) {
			if (r >= 1600 && r <= 2799) r += a;
		}
		if (d == 2) {
			if (r >=1200 && r <= 2399) r += a;
		}
	}
	cout << r << '\n';
	return 0;
}