#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+7;
int n,c,m;
int pos[maxn][2];
int a[maxn];
int t1[maxn],t2[maxn];
struct zone{
	int l,r,p,ans;
}z[maxn];
bool cmp(const zone x,const zone y) {
	return x.r < y.r;
}
bool cmp1(const zone x,const zone y) {
	return x.p < y.p;
}
inline int lowbit(int x) {
	return x&-x;
}
inline void modify1(int p,int x) {
	while (p <= n) {
		t1[p] += x;
		p += lowbit(p);
	}
}
inline void modify2(int p,int x) {
	while (p <= n) {
		t2[p] += x;
		p += lowbit(p);
	}
}
inline int query1(int p) {
	int ret = 0;
	while (p > 0) {
		ret += t1[p];
		p -= lowbit(p);
	}
	return ret;
}
inline int query2(int p) {
	int ret = 0;
	while (p > 0) {
		ret += t2[p];
		p -= lowbit(p);
	}
	return ret;
}
inline void print(int p) {

	for (int i = 1; i <= p; i++) cout << t1[p] << ' ';
	cout << '\n';
	for (int i = 1; i <= p; i++) cout << t2[p] << ' ';
	cout << '\n';
}
int main () {
	cin >> n >> c >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> z[i].l >> z[i].r,z[i].p = i;
	sort(z+1,z+m+1,cmp);
	int j = 0;
	// for (int i = 1; i <= m; i++) cout << z[i].l << ' ' << z[i].r << '\n';
	// cout << '\n';
	for (int i = 1; i <= m; i++) {
		if (j < z[i].r) {
			for (int k = j + 1; k <= z[i].r; k++) {
				if (pos[a[k]][1] == 0) {
					pos[a[k]][1] = k;
				}else if (pos[a[k]][0] == 0) {
					// cout << 1 << '\n';
					pos[a[k]][0] = pos[a[k]][1];
					pos[a[k]][1] = k;
					modify1(k,1);
					modify2(pos[a[k]][0],1);
					// print(k);
				}else{
					// cout << 2 << '\n';
					modify1(pos[a[k]][1],-1);
					modify2(pos[a[k]][0],-1);
					pos[a[k]][0] = pos[a[k]][1];
					pos[a[k]][1] = k;
					modify1(k,1);
					modify2(pos[a[k]][0],1);
					// print(k);
				}
			}
			j = z[i].r;
		}
		// cout << 2 << '\n';
		z[i].ans = query1(z[i].r) - query2(z[i].l-1);
	}
	// for (int i = 1; i <= c; i++) {
	// 	cout << pos[i][0] << ' ' << pos[i][1] << '\n';
	// }
	sort(z+1,z+m+1,cmp1);
	for (int i = 1; i <= m; i++) { 
		cout << z[i].ans << '\n';
	}
	return 0;
}