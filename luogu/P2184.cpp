#include <bits/stdc++.h>
using namespace std;
int n,m,tot,tot1 = -0x3f3f3f3f;
struct zone{
	int l,r,v,tp,p,ans;
}z[200005];
bool cmp1(zone x,zone y) {
	if (x.v == y.v) {
		return x.tp < y.tp;
	}
	return x.v < y.v;
}
bool cmp2(zone x,zone y) {
	return x.p < y.p;
}
int t[100004];
inline int lowbit(int x) {
	return x&(-x);
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
	return p;
}
int main () {
	cin >> n >> m;
	while (m--) {
		int op,l,r;
		cin >> op >> l >> r;
		if (op == 1) {
			z[++tot].tp = 1;
			z[tot].l = l;
			z[tot].r = r;
			z[tot].v = l;
			z[++tot].tp = 2;
			z[tot].l = l;
			z[tot].r = r;
			z[tot].v = r;
		}else{
			z[++tot].tp = 3;
			z[tot].l = l;
			z[tot].r = r;
			z[tot].v = r;
			z[tot].p = ++tot1;
		}
	}
	sort(z+1,z+tot+1,cmp1);
	for (int i = 1; i <= tot; i++) {
		if (z[i].tp == 1) {
			modify(z[i].l,1);
		}
		// if (z[i].tp == 2) {
		// 	modify(z[i].l,-1);
		// }
		if (z[i].tp == 3) {
			z[i].ans = query(z[i].r)-query(z[i].l-1);
		}
	}
	sort(z+1,z+tot+1,cmp2);
	for (int i = 1; i <= tot; i++) {
		if (z[i].tp == 3) {
			cout << z[i].ans << '\n';
		}
	} 
	return 0;
}