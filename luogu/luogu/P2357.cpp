#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn = 2e5+6;
int n,m;
ll a[maxn];
ll t[maxn<<2],tag[maxn<<2];
inline void pushup(int p) {
	t[p] = t[ls] + t[rs];
}
inline void pushdown(int p,int l,int r){
	int mid = (l + r) >> 1;
	tag[ls] += tag[p];
	tag[rs] += tag[p];
	t[ls] += tag[p]*(mid-l+1);
	t[rs] += tag[p]*(r-mid);
	tag[p] = 0;
}
void build(int p,int l,int r){
	if (l == r){
		t[p] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(p);
}
void modify(int p,ll v,int l,int r,int s,int e){
	if (l <= s && e <= r) {
		t[p] += v*(e-s+1);
		tag[p] += v;
		return;
	}
	int mid = (s + e) >> 1;
	if (s != e && tag[p] != 0) pushdown(p,s,e);
	if (l <= mid) modify(ls,v,l,r,s,mid);
	if (r > mid) modify(rs,v,l,r,mid+1,e);
	pushup(p); 
}
ll query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	if (s != e && tag[p] != 0) pushdown(p,s,e);
	ll ret = 0;
	if (l <= mid) ret += query(ls,l,r,s,mid);
	if (r > mid) ret += query(rs,l,r,mid+1,e);
	return ret;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1,1,n);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			ll l,r,k;
			cin >> l >> r >> k;
			modify(1,k,l,r,1,n);
		}else if (op == 2) {
			ll k;
			cin >> k;
			modify(1,k,1,1,1,n);
		}else if (op == 3) {
			ll k;
			cin >> k;
			modify(1,-k,1,1,1,n);
		}else if (op == 4) {
			int l,r;
			cin >> l >> r;
			cout << query(1,l,r,1,n) << '\n';
		}else{
			cout << query(1,1,1,1,n) << '\n';
		}
	}
	return 0;
}