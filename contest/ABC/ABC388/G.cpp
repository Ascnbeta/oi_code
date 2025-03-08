#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int a[500009],b[500009];
bool f[500009];
bool check(int x) {
	int tmp = 0,cnt = 0;
	for (int i = n; i >= 1; i--) {
		if (b[i] > tmp) {
			++tmp;
			++cnt;
		}
	}
	if (cnt >= x) return true;
	else return false;
}
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		b[i] = n-(lower_bound(a+1,a+n+1,a[i]*2)-a)+1;
	}
	int l = 0,r = n / 2;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}