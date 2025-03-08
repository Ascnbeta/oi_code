#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int x[404],l[404];
int p[80223],tot,x1[404];
inline bool check(int s) {
	for (int i = 1; i <= n; i++) {
		x1[i] = abs(x[i]-s);
	}
	sort(x1+1,x1+n+1);
	for (int i = 1; i <= n; i++) {
		if (x1[i] > l[i]) return false;
	}
	return true;
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			p[++tot] = x[i]-l[j],p[++tot] = x[i]+l[j];
		}
	}
	sort(p+1,p+tot+1);
	int tot1 = unique(p+1,p+tot+1)-p-1;
	for (int i = 1; i <= tot1; i++) {
		if (i != tot1 && check(p[i]+1)) ans += p[i+1]-p[i]-1;
		if (check(p[i])) ans += 1;
	}
	cout << ans << '\n';
	return 0;
}