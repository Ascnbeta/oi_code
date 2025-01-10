#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt[200005];
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x,y;
		cin >> x >> y;
		++cnt[x],++cnt[y];
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i]%2) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}