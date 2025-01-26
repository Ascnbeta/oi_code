#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+7;
int n,m;
int a[maxn],t[maxn<<2];
inline void pushup(int p) {
	t[p] = t[p<<1] + t[p<<1|1];
}
inline void build(int p,int l,int r) {
	if (l == r) {
		t[p] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
inline void modify(int p,int l,int r,int s,int e) {
	if (t[p] == (e - s + 1)) {
		return;
	}
	if (e == s) {
		t[p] = sqrt(t[p]);
		return;
	}
	int mid = (s + e) >> 1;
	if (l <= mid) modify(p<<1,l,r,s,mid);
	if (r > mid) modify(p<<1|1,l,r,mid+1,e);
	pushup(p);
}
inline int query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	int ret = 0;
	if (l <= mid) ret += query(p<<1,l,r,s,mid);
	if (r > mid) ret += query(p<<1|1,l,r,mid+1,e);
	return ret;  
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	cin >> m;
	while(m--) {
		int k,l,r;
		cin >> k >> l >> r;
		if (l > r) swap(l,r);
		if (k == 0) modify(1,l,r,1,n);
		if (k == 1) cout << query(1,l,r,1,n) << '\n';
	}
	return 0;
}