#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5006];
bool b[5006];
int main () {
	cin >> n;
	for (int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int temp = -1,tot = n;
	while (tot) {
		temp = -1;
		for (int i = 1; i <= n ;i++) {
			if (b[i]) continue;
			if (temp == -1) {
				temp = a[i];
				b[i] = true;
				tot--;
				++ans;
				continue;
			}
			if (temp < a[i]) {
				b[i] = true;
				tot--;
				temp = a[i];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
