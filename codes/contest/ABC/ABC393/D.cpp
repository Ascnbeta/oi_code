#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
string s;
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> s;
	s = ' ' + s;
	int cnt = 0,pt = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') ++cnt;
	}
	int tmp = 0;
	// cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			++tmp;
			if (tmp == cnt/2+1) pt = i;
		}
	}
	// cout << pt << '\n';
	cnt = pt-1;
	for (int i = pt-1; i >= 1; i--) {
		if (s[i] == '1') {
			ans += cnt-i;
			--cnt;
		}
	}
	cnt = pt+1;
	for (int i = pt+1; i <= n; i++) {
		if (s[i] == '1') {
			ans += i-cnt;
			++cnt;
		}
	}
	cout << ans << '\n';
	return 0;
}  