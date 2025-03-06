#include <bits/stdc++.h>
using namespace std;
int n,maxx,minn=0x3f3f3f3f;
int s[5004];
int v[1000004];
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i],maxx=max(maxx,s[i]),minn=min(minn,s[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			v[abs(s[i]-s[j])] = 1;
		}
	}
	for (int i = 1; i <= maxx-minn; i++) {
		if (v[i] == 0) {
			bool f = true;
			for (int j = i; j <= maxx-minn; j += i) {
				if (v[j] == 1) {
					f = false;
					break;
				}
			}
			if (f) {
				cout << i << '\n';
				return 0;
			}
		}
	}
	cout << maxx << '\n';
	return 0;
}