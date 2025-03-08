#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e5+6;
typedef long long ll;
int n,m;
int a[maxn];
struct node{
	ll v,max;
};
	node t[maxn<<2];
	inline ll max(ll x,ll y) {
		return ((x>y)?(x):(y));
	}
	inline void pushup(int p) {
		t[p].v = t[ls].v + t[rs].v;
		t[p].max = max(t[ls].max,t[rs].max);
	}
	void build(int p,int l,int r) {
		if (l == r) {
			t[p].v = a[l];
			t[p].max = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(p);
	}
	void modifyg(int p,int v,int pos,int s,int e) {
		if (s == e) {
			t[p].v = v;
			t[p].max = v;
			return;
		}
		int mid = (s + e) >> 1;
		if (pos <= mid) modifyg(ls,v,pos,s,mid);
		if (pos > mid) modifyg(rs,v,pos,mid+1,e);
		pushup(p); 
	}
	void modifym(int p,int v,int l,int r,int s,int e) {
		if (t[p].max < v) return;
		if (s == e) {
			t[p].v %= v;
			t[p].max = t[p].v;
			return;
		}
		int mid = (s + e) >> 1;
		if (l <= mid) modifym(ls,v,l,r,s,mid);
		if (r > mid) modifym(rs,v,l,r,mid+1,e);
		pushup(p);
	}
	ll query(int p,int l,int r,int s,int e) {
		if (l <= s && e <= r) {
			return t[p].v;
		}
		int mid = (s + e) >> 1;
		ll ret = 0;
		if (l <= mid) ret += query(ls,l,r,s,mid);
		if (r > mid) ret += query(rs,l,r,mid+1,e);
		return ret;
	}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if (op == 1) {
			int l,r;
			cin >> l >> r;
			cout << query(1,l,r,1,n) << '\n';
		}
		if (op == 2) {
			int l,r,x;
			cin >> l >> r >> x;
			modifym(1,x,l,r,1,n);
		}
		if (op == 3) {
			int k,x;
			cin >> k >> x;
			modifyg(1,x,k,1,n);
		} 
	}
	return 0;
}