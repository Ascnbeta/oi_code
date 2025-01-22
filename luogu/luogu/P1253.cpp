#include <bits/stdc++.h>
#define int long long
#define MIN -100000000000004
using namespace std;
const int maxn =1e6+8;
int n,q;
int a[maxn],t[4*maxn],tagm[4*maxn],tagp[4*maxn];
inline void pushup(int p) {
	t[p] = max(t[p<<1],t[p<<1|1]);
}
inline void pushdown(int p,int l,int r) {
	if (tagm[p] != MIN) {
		t[p<<1] = t[p<<1|1] = tagm[p];
		tagm[p<<1] = tagm[p<<1|1] = tagm[p];
		tagp[p<<1] = tagp[p<<1|1] = 0;
	}
	t[p<<1] += tagp[p];
	t[p<<1|1] += tagp[p];
	tagp[p<<1] += tagp[p];
	tagp[p<<1|1] += tagp[p];
	tagm[p] = MIN,tagp[p] = 0;
}
inline void build(int p,int l,int r) {
	if (l == r) {
		t[p] = a[l];
		return;
	}
	tagm[p] = MIN;
	int mid = (l + r) >> 1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
inline void modifym(int p,int l,int r,int x,int s,int e) {
	if (l <= s && e <= r) {
		t[p] = x;
		tagp[p] = 0;
		tagm[p] = x;
		return;
	}
	int mid = (s + e) >> 1;
	if ((tagp[p] != 0 || tagm[p] != MIN)) pushdown(p,s,e);
	if (l <= mid) modifym(p<<1,l,r,x,s,mid);
	if (r > mid) modifym(p<<1|1,l,r,x,mid+1,e);
	pushup(p);
}
inline void modifyp(int p,int l,int r,int x,int s,int e) {
	if (l <= s && e <= r) {
		t[p] += x;
		tagp[p] += x;
		return;
	}
	int mid = (s + e) >> 1;
	if ((tagp[p] != 0 || tagm[p] != MIN)) pushdown(p,s,e);
	if (l <= mid) modifyp(p<<1,l,r,x,s,mid);
	if (r > mid) modifyp(p<<1|1,l,r,x,mid+1,e);
	pushup(p);
}
inline int query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	if ((tagp[p] != 0 || tagm[p] != MIN)) pushdown(p,s,e);
	int ret = MIN;
	if (l <= mid) ret = max(ret,query(p<<1,l,r,s,mid));
	if (r > mid) ret = max(ret,query(p<<1|1,l,r,mid+1,e));
	return ret;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (q--) {
		int op,l,r;
		cin >> op >> l >> r;
		if (op == 1) {
			int x;
			cin >> x;
			modifym(1,l,r,x,1,n);
		} else if (op == 2) {
			int x;
			cin >> x;
			modifyp(1,l,r,x,1,n);
		} else {
			cout << query(1,l,r,1,n) << '\n';
		}
	}
	return 0;
}
