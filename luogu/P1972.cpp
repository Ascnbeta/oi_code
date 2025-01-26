#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000006],sum[1000006],t[1000005];
int pos[1000006];
struct zone{
	int l,r,cnt,ans;
}z[1000005];
bool cmp1(zone x,zone y) {
	if (x.r == y.r) return x.l < y.l;
	return x.r < y.r;
}
bool cmp2(zone x,zone y) {
	return x.cnt < y.cnt;
}
inline int lowbit(int x) {
	return x&-x;
}
inline void modify(int p,int x) {
	while(p <= n) {
		t[p] += x;
		p += lowbit(p);
	}
}
inline int query(int p) {
	int ret = 0;
	while(p > 0) {
		ret += t[p];
		p -= lowbit(p);
	}
	return ret;
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> z[i].l >> z[i].r,z[i].cnt = i;
	sort(z+1,z+m+1,cmp1);
	int j = 0;
	for (int i = 1; i <= m; i++) {
		if (z[i].r != j) {
			for (int k = j + 1; k <= z[i].r; k++) {
				if (pos[a[k]]) {
					modify(pos[a[k]],-1);
					modify(k,1);
					pos[a[k]] = k;
				}else{
					modify(k,1);
					pos[a[k]] = k;
				}
			}
			j = z[i].r;
		}
		z[i].ans = query(z[i].r) - query(z[i].l-1);
	}
	sort(z+1,z+m+1,cmp2);
	for (int i = 1; i <= m; i++) {
		cout << z[i].ans << '\n';
	}
	return 0;
}