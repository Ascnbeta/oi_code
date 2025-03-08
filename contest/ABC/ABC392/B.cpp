#include <bits/stdc++.h>
using namespace std;
int n,m,a[10003],b[10003],cnt;
int main () {
	cin >> n >> m;
	cnt = n;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		if (b[a[i]] == 0) --cnt;
		b[a[i]]++;
	}
	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (!b[i]) cout << i << ' ';
	}
	cout << '\n';
	return 0;
}