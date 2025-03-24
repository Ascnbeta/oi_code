#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
int n,m;
int a[3000003];
int sum = 0;
signed main() {
#ifdef LOCAL
	freopen("E:/codes/exe/a.in","r",stdin);
	freopen("E:/codes/exe/a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (a[x] != 0 && x > 0) {
			--x;
		}
		if (x != 0) a[x] = 1;
		sum = (sum + i * x % mod) % mod;
	}
	cout << sum << '\n';
	return 0;
}