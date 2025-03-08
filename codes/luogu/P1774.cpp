#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[500005],b[500005];
int t[500005];
inline int lowbit(int x) {
	return x&-x;
}
inline void modify(int p,int x) {
	while (p <= n) {
		t[p] += x;
		p += lowbit(p);
	}
}
inline int query(int p) {
	int ret = 0;
	while (p > 0) {
		ret += t[p];
		p -= lowbit(p);
	}
	return ret;
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i],b[i] = a[i];
	sort(b+1,b+n+1);
	int n1 = unique(b+1,b+n+1)-b-1;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(b+1,b+n+1,a[i])-b;
	}
	for (int i = 1; i <= n; i++) {
		ans += query(n)-query(a[i]);
		modify(a[i],1);
	}
	cout << ans << '\n';
	return 0;
}