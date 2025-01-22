#include <bits/stdc++.h>
using namespace std;
int n,cnt;
bool a[1005];
int main () {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n ; i++) {
		int x;
		cin >> x;
		if (!a[x]) {
			cnt++;
			a[x] = true;
		}
	}
	cout << cnt << '\n';
	for (int i = 1; i <= 1000; i++) {
		if (a[i]) {
			cout << i << ' ';
		}
	}
	return 0;
}
