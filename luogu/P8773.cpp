#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+5;
int n,m,x;
int a[maxn],b[maxn],lst[(1<<20)+20][0];
int f[maxn]
signed main () {
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) cin >> a[i],b[i] = x ^ a[i];
	for (int i = 1; i <= n; i++) {
		lst[a[i]] = i;
	}
	for (int i = 2; i <= n; i++) {
		f[i]=f[i/2]+1;
	}
	for (int i = 1; (1<<i) <= n; i++) {
		for (int j = 1; j+(1<<i)-1 <= n; j++) {
			lst[j][i] = max(lst[j][i-1],lst[j+(1<<i)][i-1]);
		}
	}
	for (int i = 1; i <= m; i++) {
		int l,r;
		cin >> l >> r;

	}
	return 0;
}