#include <bits/stdc++.h>
using namespace std;
mt19937 r(time(0));
int n,m;
int main () {
	n = r() % 10000 + 1;
	m = r() % 10000 + 1;
	cout << n << ' ' << m << '\n';
	for (int i = 1; i <= n; i++) {
		if (i != n) cout << r()%2 << ' ';
		else cout << r()%2;
	}
	cout << '\n';
	while (m--) {
		cout << r() % 5 << ' ';
		int l = r() % n;
		int R = r() % n;
		if (l > R) swap(l,R);
		cout << l << ' ' << R << '\n';
	}
	return 0;
}