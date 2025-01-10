#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int w[1003];bool f[1003];
int l[1003],r[1003],tmp[2003],tot;
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++ ) {
		cin >> l[i] >> r[i];
		tmp[++tot] = l[i];
		tmp[++tot] = r[i];
	}
	sort(tmp+1,tmp+tot+1);
	tot = unique(tmp+1,tmp+tot+1)-tmp-1;
	for (int i = 1; i <= m; i++) {
		l[i] = lower_bound(tmp+1,tmp+tot+1,l[i])-tmp;
		r[i] = lower_bound(tmp+1,tmp+tot+1,r[i])-tmp;
		// cout << l[i] << ' ' << r[i] << '\n';
		for (int j = l[i]; j <= r[i]; j++) {
			w[j] = i;
		}
	}
	// cout << tot << '\n';
	for (int i = 1; i <= tot; i++) {
		if (!f[w[i]]) {
			++ans;
			f[w[i]] = true;
		}
	}
	cout << ans << '\n';
	return 0;
}