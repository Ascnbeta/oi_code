#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n == 4 || n == 10) cout << n + 1 << '\n';
		else cout << n - 1 << '\n';
	}
	return 0;
}