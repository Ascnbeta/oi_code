#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4+6;
int n,a[maxn];
long long ans;
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int cnt1 = 0,cnt2 = 0;
		for (int j = 1; j <= i - 1; j++) if (a[j]<a[i]) ++cnt1;
		for (int j = i+1; j <= n; j++) if (a[j]>a[i]) ++cnt2;
		ans += (long long)cnt1*cnt2;
	}
	cout << ans << '\n';
	return 0;
}