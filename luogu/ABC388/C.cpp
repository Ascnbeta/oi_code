#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int a[500004];
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		int p = upper_bound(a+1,a+n+1,a[i]/2)-a-1;
		ans += p;
	}
	cout << ans << '\n'; 
	return 0;
}