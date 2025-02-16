#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans = 0;
map<int,int> mp;
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		if (u > v) swap(u,v);
		if (u == v) {
			++ans;
			continue;
		}
		if (mp.find(200000*u+v) == mp.end()) {
			mp[200000*u+v] = 1;
		}else{
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}