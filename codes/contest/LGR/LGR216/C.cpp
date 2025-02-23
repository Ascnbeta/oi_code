#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6+20;
int T;
int n,ans;
int s[maxn];
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) s[i] = 0;
		ans = 0;
		s[1] = 1;
		for (int i = 1; i <= n/2; i++) {
			int k = n / i,cnt = 1;
			// cout << k*i << '\n';
			for (int j = k*i; j > i; j -= i) {
				s[j] = max(s[j],s[i]+cnt);
				++cnt;
			}
			ans += s[i];
			// for (int j = 1; j <= n; j++) cout << s[j] << '\n';
			// cout << '\n';
		}
		for (int i = n/2+1; i <= n; i++) ans += s[i];
		cout << ans << '\n';
	}
	return 0;
}