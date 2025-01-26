#include <bits/stdc++.h>
using namespace std;
int n,a[100005],maxx;
inline bool check(long long x) {
	int cnt
	for (int i )
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i],maxx = max(a[i],maxx);
	long long l = 0,r = maxx,ans = 0;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	} 
	return 0;
}