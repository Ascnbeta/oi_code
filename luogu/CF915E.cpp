#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.5e7+3;
int n,q;
struct node {
	int ls,rs,v;
}t[maxn];
int tag[maxn],tot;
inline void add() {
	t[++tot].v = 0;
	tag[tot] = -1;
}
inline void pushdown(int p,int l,int r) {
	tag[t[p].ls]=tag[t[p].rs]=tag[p];
	int mid = (l + r) >> 1;
	t[t[p].ls].v = (mid-l+1)*tag[p];
	t[t[p].rs].v = (r-mid)*tag[p];
	tag[p] = -1;
}
inline void pushup(int p) {
	t[p].v = t[t[p].ls].v + t[t[p].rs].v;
}
void modify(int p,int v,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		t[p].v = (e-s+1)*v;
		tag[p] = v;
		return;
	}
	int mid = (s + e) >> 1;
	if (t[p].ls == 0) {
		add();
		t[p].ls = tot;
	}
	if (t[p].rs == 0) {
		add();
		t[p].rs = tot;
	}
	if (s != e && tag[p] != -1) pushdown(p,s,e);
	if (l <= mid) modify(t[p].ls,v,l,r,s,mid);
	if (r > mid) modify(t[p].rs,v,l,r,mid+1,e);
	pushup(p);
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	t[1].v = 0,tag[1] = -1,tot = 1;
	while (q--) {
		int l,r,x;
		cin >> l >> r >> x;
		if (x == 1) {
			modify(1,1,l,r,1,n);
			cout << n-t[1].v << '\n';
		}else{
			modify(1,0,l,r,1,n);
			cout << n-t[1].v << '\n';
		}
	}
	return 0;
}