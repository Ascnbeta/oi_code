#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],ans;
int l[200005];
void dfs(int x) {
	if (x == n + 1) {
		int r = 0,b = 0,c = 0;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				if (l[i] == 1) r = 1;
				else b = 1;
				continue;
			}
			if (l[i] == 1) {
				if (r != 0) {
					if (a[r] == a[i]) c += a[i];
				}
				r = i;
			}
			if (l[i] == 2) {
				if (b != 0) {
					if (a[b] == a[i]) c += a[i];
				}
				b = i;
			}
		}
		ans = max(ans,c);
		return;
	}
	l[x]=1;
	dfs(x+1);
	l[x]=2;
	dfs(x+1);
}
signed main() {
	// freopen("color.in","r",stdin);
	// freopen("color.out","w",stdout);
	cin >> T;
	while(T--) {
		ans = 0;
		cin >> n;
		if (n > 20) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}
