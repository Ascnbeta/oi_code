#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r,anss;
inline int LOG__(int x) {
	int y = x,a=0;
	while (y) {
		a++;
		y >>= 1;
	} 
	return a;
}
bool dfs(const int x,int p) {
	if (x == 1) {
		return true;
	}
	if (x == 0) {
		return false;
	}
	int i = LOG__(x);
	int ans = 1;
	for (int j = 1; j <= i-1; j++) {
		ans *= 2;
	}
//	cout << ans << endl;
	if (p < ans) {
		return dfs(x/2,p);
	}
	if (p > ans) {
		return dfs(x/2,p-ans);
	}
	return (x%2 == 1);
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r;
//	cout << LOG(n) << endl;//jj
	for (int i = l; i <= r; i++) {
		if (dfs(n,i)) ++anss;
	}
	cout << anss << endl;
	return 0;
}
