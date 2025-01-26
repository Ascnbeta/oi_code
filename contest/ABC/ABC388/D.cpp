#include <bits/stdc++.h>
using namespace std;
int n;
int a[500004],op[500004],tmp;
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		tmp += op[i];
		a[i] += tmp;
		if (a[i] > 0) {
			++tmp;
			if (i+a[i]+1 <= n) op[i+a[i]+1] += -1;
			a[i] -= n - i;
		}
		if (a[i] < 0) a[i] = 0;
	}
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << '\n';
	return 0;
}