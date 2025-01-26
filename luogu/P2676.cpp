#include <bits/stdc++.h>
using namespace std;
int n,b,cnt,sum;
int h[20005];
int main () {
	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	sort(h+1,h+n+1);
	for (int i = n; i >= 1; i--) {
		sum += h[i];
		++cnt;
		if (sum >= b) {
			cout << cnt << endl;
			return 0;
		}
	}
	return 0;
}
