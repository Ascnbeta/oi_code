#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4+3;
int T;
int n;
int a[maxn];
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			if (i == 2) continue;
			a[2] /= __gcd(a[2],a[i]);
		}
		if (a[2] == 1) puts("Yes");
		else puts("No");
	}
	return 0;
}