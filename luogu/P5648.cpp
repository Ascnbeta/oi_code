#include <bits/stdc++.h>
using namespace std;
int n,q;
long long ans;
int a[500004],t[2000004];
void pushup(int p) {
	t[p] = max(t[p<<1],t[p<<1|1]);
}
void build(int l,int r,int p) {
	if (l == r) {
		t[p] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	pushup(p);
}
int query(int l,int r,int s,int e,int p) {
	if (l <= s && e <= r) {
		return a[l];
	}
	int mid = (s + e) >> 1;
	int ret = 0;
	if (l <= mid) ret = max(ret,query(l,r,s,mid,p<<1));
	if (r > mid) ret = max(ret,query(l,r,mid+1,e,p<<1|1));
	return ret;
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (q--) {
		int x,y;
		cin >> x >> y;
		x = 1 + (x ^ ans) % n;
		y = 1 + (y  ^ (ans + 1)) % (n - x + 1);
		y = x + y - 1;
		ans = query(x,y,1,n,1);
		cout << ans << '\n';
	}
	return 0;
}