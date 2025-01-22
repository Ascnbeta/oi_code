#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,c,ans;
struct coin{
	int v,b;
	bool operator < (const coin &x) const{
		return v > x.v;
	}
}a[23];
signed main () {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].v >> a[i].b;
	}
	sort(a+1,a+n+1);
	for (int i = 1,j = n; i <= n; i++) {
		if (a[i].v >= c) {
			ans += a[i].b;
			continue;
		}
	}
	return 0;
}