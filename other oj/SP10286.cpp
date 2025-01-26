#include <bits/stdc++.h>
using namespace std;
int t,n,m,k;
int a[504];
int main () {
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1,a+n+1,greater<int>());
		bool f = false;
		for (int i = 1; i <= n; i++) {
			if (a[i] > k) {
				m -= a[i] / (k + 1);
				if (m <= 0) {
					f = true;
					break;
				}
			}else{
				break;
			}
		}
		if (f) puts("YES");
		else puts("NO");
	}
	
	return 0;
}