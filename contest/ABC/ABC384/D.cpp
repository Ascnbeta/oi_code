#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[400005],sum[400005],s1;
int s;
signed main () {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i],a[i+n] = a[i],s1 += a[i];
	n *= 2;
	if (s % s1 == 0) {
		puts("Yes");
		return 0;
	}
	s = s % s1;
	for (int i = 1; i <= n; i++) sum[i]=sum[i-1]+a[i];
	for (int i = 1; i <= n; i++) {
		int x = lower_bound(sum+i,sum+n+1,sum[i]+s)-sum;
		if (sum[x] - sum[i] == s) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}