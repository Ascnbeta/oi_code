#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
#define double long double
const int maxn = 1e5+10;
int n,m;
double a[maxn];
struct node{
	double v,pfh;
	double tag;
};
struct segment_tree{
	node t[maxn<<2];
	inline void pushup(int p) {
		t[p].v = t[ls].v + t[rs].v;
		t[p].pfh = t[ls].pfh + t[rs].pfh;
	}
	inline void pushdown(int p,int l,int r) {
		int mid = (l + r) >> 1;
		t[ls].tag += t[p].tag,t[rs].tag += t[p].tag;
		t[ls].pfh += 2*t[p].tag*t[ls].v+(mid-l+1)*t[p].tag*t[p].tag;
		t[rs].pfh += 2*t[p].tag*t[rs].v+(r-mid)*t[p].tag*t[p].tag;
		t[ls].v += (mid-l+1)*t[p].tag;
		t[rs].v += (r-mid)*t[p].tag;
		t[p].tag = 0;
	}
	void build(int p,int l,int r) {
		if (l == r) {
			t[p].v = a[l];
			t[p].pfh = a[l]*a[l];
			t[p].tag = 0;
			return;
		}
		int mid = (l + r) >> 1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(p);
	}
	void modify(int p,double v,int l,int r,int s,int e) {
		if (l <= s && e <= r) {
			t[p].pfh += 2*v*t[p].v+(e-s+1)*v*v;
			t[p].v += v*(e-s+1);
			t[p].tag += v;
			return;
		}
		int mid = (s + e) >> 1;
		if (s != e && t[p].tag) pushdown(p,s,e);
		if (l <= mid) modify(ls,v,l,r,s,mid);
		if (r > mid) modify(rs,v,l,r,mid+1,e);
		pushup(p);
	}
	double query1(int p,int l,int r,int s,int e) {
		if (l <= s && e <= r) {
			return t[p].v;
		}
		int mid = (s + e) >> 1;
		if (s != e && t[p].tag) pushdown(p,s,e);
		double ret = 0;
		if (l <= mid) ret += query1(ls,l,r,s,mid);
		if (r > mid) ret += query1(rs,l,r,mid+1,e);
		return ret;
	}
	double query2(int p,int l,int r,int s,int e) {
		if (l <= s && e <= r) {
			return t[p].pfh;
		}
		int mid = (s + e) >> 1;
		if (s != e && t[p].tag) pushdown(p,s,e);
		double ret = 0;
		if (l <= mid) ret += query2(ls,l,r,s,mid);
		if (r > mid) ret += query2(rs,l,r,mid+1,e);
		return ret; 
	}
}tree;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	tree.build(1,1,n);
	while (m--) {
		int op,x,y;
		cin >> op >> x >> y;
		if (op == 1) {
			double k;
			cin >> k;
			tree.modify(1,k,x,y,1,n);
		}else if (op == 2) {
			double ans = 1.0*tree.query1(1,x,y,1,n)/(y-x+1);
			cout << fixed << setprecision(4) << ans << '\n';
		}else{
			double sum1 = tree.query1(1,x,y,1,n),sum2 = tree.query2(1,x,y,1,n);
			// cout << sum2 << '\n';
			double avg = sum1/(y-x+1);
			double ans = (sum2-avg*2*sum1+avg*avg*(y-x+1))/(y-x+1);
			cout << fixed << setprecision(4) << ans << '\n';
		}
	}
	return 0;
}