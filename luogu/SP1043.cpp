#include <bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 5e4+10;
int n,m;
int a[maxn];
struct node{
	int msum,lsum,rsum,lp,rp;
	node() {
		msum = lsum = rsum = -0x3f3f3f3f;
		lp = rp = 0;
	}
}t[maxn<<2];
inline void pushup(int p,int l,int r) {
	int mid = (l + r) >> 1;
	t[p].msum = max(t[ls].msum,t[rs].msum);
	if (t[rs].lsum + t[ls].rsum > t[p].msum) {
		t[p].msum = t[rs].lsum + t[ls].rsum;
	}
	if (t[ls].lp == mid && t[rs].lsum != 0) {
		t[p].lsum = t[ls].lsum + t[rs].lsum;
		t[p].lp = t[rs].lp;
	}else{
		t[p].lsum = t[ls].lsum;
		t[p].lp = t[ls].lp;
	}
	if (t[rs].rp == mid+1 && t[ls].rsum != 0) {
		t[p].rsum = t[rs].rsum + t[ls].rsum;
		t[p].rp = t[ls].rp;
	}else{
		t[p].rsum = t[rs].rsum;
		t[p].rp = t[rs].rp;
	}
}

void build(int p,int l,int r) {
	if (l == r) {
		t[p].msum = t[p].lsum = t[p].rsum = a[l];
		t[p].lp = l;
		t[p].rp = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(p,l,r);
}
node query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	node ret,t1,t2;
	if (l <= mid) {
		t1 = query(ls,l,r,s,mid);
	}
	if (r > mid) {
		t2 = query(rs,l,r,mid+1,e);
	}
	if (l <= mid && r <= mid) {
		ret = t1;
	}
	if (l > mid && r > mid) {
		ret = t2;
	}
	if (l <= mid && r > mid) {
		ret.msum = max(t1.msum,t2.msum);
		if (t1.rsum + t2.lsum > ret.msum) {
			ret.msum = t2.lsum + t1.rsum;
		}
		if (t1.lp == mid && t2.lsum != 0) {
			ret.lsum = t1.lsum + t2.lsum;
			ret.lp = t2.lp;
		}else{
			ret.lsum = t1.lsum;
			ret.lp = t1.lp;
		}
		if (ret.rp == mid+1 && t1.rsum != 0) {
			ret.rsum = t2.rsum + t1.rsum;
			ret.rp = t1.rp;
		}else{
			ret.rsum = t2.rsum;
			ret.rp = t2.rp;
		}
	}
	return ret;
}
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	cin >> m;
	while(m--) {
		int l,r;
		cin >> l >> r;
		cout << query(1,l,r,1,n).msum << '\n';
	}
	return 0;
}