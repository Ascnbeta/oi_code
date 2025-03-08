#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,k,l;
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> T;
	while (T--) {
		cin >> a >> b >> k >> l;
		int ans = 0;
		if (l == 0) {
			cout << a + b << '\n';
			continue;
		}
		if (a / l + b / l <= k) {
			k -= a/l+b/l,a %= l,b %= l;
			if (k == 0) {
				cout << a + b << '\n';
			}else if (k == 1) {
				int c = l - a;
				int d = l - b;
				if (c > l / 2 && d > l / 2) {
					cout << a + b << '\n';
				}else if (d <= l / 2 && c > l / 2) {
					cout << a + d << '\n';
				}else if (c <= l / 2 && d > l / 2) {
					cout << c + b << '\n';
				}else{
					if (c <= d) {
						cout << c + b << '\n';
					}else{
						cout << a + d << '\n';
					}
				}
			}else{
				int c = l - a;
				int d = l - b;
				if (c <= l / 2) {
					ans += c;
				}else{
					ans += a;
				}
				if (d <= l / 2) {
					ans += d;
				}else{
					ans += b;
				}
				cout << ans << '\n';
			}
		}else{
			int c = a,d = b;
 			a -= min(a/l,k)*l;
			k -= min(c/l,k);
			b -= min(b/l,k)*l;
			k -= min(d/l,k);
			cout << a + b << '\n';
		}
	}
	return 0;
}