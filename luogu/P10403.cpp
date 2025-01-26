#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[600005];
int st[600005][30];
int f[600005];
inline void init() {
	for (int i = 1; (1<<i) <= n; i++) {
		for (int j = 1; j+(1<<i)-1 <= n; j++) {
			st[j][i] = __gcd(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
inline int query(int l,int r) {
	int j = f[r-l+1];
	return __gcd(st[l][j],st[r-(1<<j)+1][j]);
}
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i],st[i][0] = a[i];
	f[1] = 0;
	for (int i = 2; i <= n; i++) f[i] = f[i/2] + 1;
	init();
	for (long long i = 1; i <= n; i++) {
		long long l = 1,r = (n-i)/2+1,L = INT_MAX,R = INT_MIN;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (query(i,(mid-1)*2+i) > 3) l = mid + 1;
			else if (query(i,(mid-1)*2+i) == 3) R = max(R,(mid-1)*2+i),l = mid + 1;
			else r = mid - 1;
		}
		if (R != INT_MIN) {
			l = 1,r = (R-i)/2+1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (query(i,(mid-1)*2+i) < 3) r = mid - 1;
				else if (query(i,(mid-1)*2+i) == 3) L = min(L,(mid-1)*2+i),r = mid - 1;
				else l = mid + 1;
			}
		}
		if (R != INT_MIN && L != INT_MAX) {
			ans += (L-i+1+R-i+1)*((R-L)/2+1)/2;
		}
		l = 1,r = (n-i+1)/2,L = INT_MAX,R = INT_MIN;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (query(i,mid*2-1+i) > 2) l = mid + 1;
			else if (query(i,mid*2-1+i) == 2) R = max(R,mid*2-1+i),l = mid + 1;
			else r = mid - 1;
		}
		if (R != INT_MIN) {
			l = 1,r = (R-i+1)/2;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (query(i,mid*2-1+i) < 2) r = mid - 1;
				else if (query(i,mid*2-1+i) == 2) L = min(L,mid*2-1+i),r = mid - 1;
				else l = mid + 1;
			}
		}
		if (R != INT_MIN && L != INT_MAX) {
			ans += (L-i+1+R-i+1)*((R-L)/2+1)/2;
		}
	}
	cout << ans << '\n';
	return 0;
}
