#include <bits/stdc++.h>
#define int long long
using namespace std;
int d,n,m,ans;
int r[100004];
signed main () {
	cin >> d >> n >> m;
	r[n+1] = d;
	for (int i = 2; i <= n; i++) cin >> r[i];
	sort(r+1,r+n+2);
	while (m--) {
		int k;
		cin >> k;
		auto t1 = lower_bound(r+1,r+n+2,k);
		auto t2 = upper_bound(r+1,r+n+2,k)-1;
		ans += min(*(t1)-k,k-*(t2));	
	}
	cout << ans << '\n';
	return 0;
}