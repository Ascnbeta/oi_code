#include <bits/stdc++.h>
using namespace std;
int q;
int main () {
	cin >> q;
	while (q--) {
		long long x,y;
		cin >> x >> y;
		if (x == y) {
			cout << 0 << '\n';
			continue;
		}
		if (x > y) swap(x,y);
		if (y % x == 0) {
			cout << y << '\n';
		}else{
			cout << x + y << '\n';
		}
	}
	return 0;
}