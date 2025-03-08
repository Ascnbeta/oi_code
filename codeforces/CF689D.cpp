#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int n;
int a[maxn],b[maxn],f[maxn];
int sta[maxn],stb[maxn];
inline void init() {
	for (int i = 2; i <= n; i++) f[i] = f[i>>1] + 1;
	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			sta[j][i] = max(sta[j][i-1],sta[j+(1<<(i-1))][i-1]);
			stb[j][i] = min(stb[j][i-1],stb[j+(1<<(i-1))][i-1]);
		}
	}
}
int main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i],sta[i][0] = a[i];
	for (int i = 1; i <= n; i++) cin >> b[i],stb[i][0] = b[i];
	init();
	for (int i = 1; i <= n; i++) {
		int l = 1,r = n,ans =;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {

			}
		}
	}
	return 0;
}