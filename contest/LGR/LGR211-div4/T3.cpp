#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int sum;
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a,b;
		cin >> a >> b;
		if (b == 0) sum += 20;
		else sum += a;
	}
	cout << sum << '\n';
	return 0;
}