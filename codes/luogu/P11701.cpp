#include <bits/stdc++.h>
#define int long long
using namespace std;
int d,l,r,ans;
map<int,int> mp;
void solve(int x) {
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			int a = i,b = x / i;
			if ((a + b) % 2 == 0 && mp.find(a+b) == mp.end()) {
				int p = (a+b)/2,q = (b-a)/2;
				if (q*q >= l && p*p <= r) {
					// cout << q << ' ' << p << '\n';
					++ans;
				}
				mp[a+b] = 1;
			}
		}
	}
} 
signed main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> d >> l >> r;
	solve(d);
	cout << ans << '\n';
	return 0;
}