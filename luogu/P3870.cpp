#include <bits/stdc++.h>
using namespace std;
int n,m;
int t[400004],lz[400004];
inline void pushup(int p) {
	t[p] = t[p<<1] + t[p<<1|1];
}
inline void pushdown(int p) {
	lz[p<<1] += lz[p];
	lz[p<<1|1] += lz[p];
	lz[p] = 0;
}
void modify(int l,int r,int s,int e,int p) {
	if (l <= s && e <= r) {
		t[p] = e - s + 1 - t[p];
		lz[p]++;
		return;
	}
	int mid = (s + e) >> 1;
	if (lz[p]) {
		if (lz[p] % 2 == 1) {
			t[p<<1] = mid - s + 1 - t[p<<1];
			t[p<<1|1] = e - mid - t[p<<1|1];
		}
		pushdown(p);
	}
	if (l <= mid) modify(l,r,s,mid,p<<1);
	if (r > mid) modify(l,r,mid+1,e,p<<1|1);
	pushup(p);
}
int query(int l,int r,int s,int e,int p) {
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	if (lz[p]) {
		if (lz[p] % 2 == 1) {
			t[p<<1] = mid - s + 1 - t[p<<1];
			t[p<<1|1] = e - mid - t[p<<1|1];
		}
		pushdown(p);
	}
	int sum = 0;
	if (l <= mid) sum += query(l,r,s,mid,p<<1);
	if (r > mid) sum += query(l,r,mid+1,e,p<<1|1);
	return sum;
}
int main () {
	cin >> n >> m;
	while (m--){
		int x,y,z;
		cin >> x >> y >> z;
		if (x == 0) {
			modify(y,z,1,n,1);
			// for (int i = 1; i <= 4 * n; i++) {
			// 	cout << t[i] <<' ';
			// }
			// cout << '\n';
		}else{
			cout << query(y,z,1,n,1) << '\n';
		}
	}
	return 0;
}