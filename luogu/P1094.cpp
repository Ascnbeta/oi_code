#include <bits/stdc++.h>
using namespace std;
int w,n,ans;
int p[30006];
bool q[30006];
int main () {
	cin >> w >> n;
	for (int i = 1; i <= n ; i++) {
		cin >> p[i];
	}
	sort(p+1,p+n+1);
	for (int i = n; i >= 1; i--) {
		if (q[i]) break;
		q[i] = true;
		for (int j = 1; j < i ;j++) {
			if (q[j]) continue;
			if (p[j] + p[i] > w ) break;
			q[j] = true;
			break;
		}
		++ans;
	}
	cout << ans;
	return 0;
}
