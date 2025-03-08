#include <bits/stdc++.h>
using namespace std;
int n,q;
struct object{
	int a,b,c;
	bool operator < (const object &y) const{
		return a < y.a;
	}
}o[2004];
struct ask{
	int m,k,s,id;
	bool ans;
	bool operator < (const ask &y) const{
		return m < y.m;
	}
}a[2000005];
bool cmp(ask &x,ask &y) {
	return x.id < y.id;
}
int f[100005];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> o[i].c >> o[i].a >> o[i].b;
	sort(o+1,o+n+1);
	cin >> q;
	for (int i = 1; i <= q; i++) cin >> a[i].m >> a[i].k >> a[i].s,a[i].id = i;
	sort(a+1,a+q+1);
	int lst = 1;
	f[0] = 0x3f3f3f3f;
	for (int i = 1; i <= q; i++) {
		int j = lst;
		for (; o[j].a <= a[i].m && j <= n; j++) {
			for (int k = 100000; k >= o[j].c; k--) {
				f[k] = max(f[k],min(f[k-o[j].c],o[j].b));
			}
		}
		lst = j;
		if (f[a[i].k] > a[i].m + a[i].s) a[i].ans = true;
	}
	sort(a+1,a+q+1,cmp);
	for (int i = 1; i <= q; i++) {
		if (a[i].ans) puts("TAK");
		else puts("NIE");
	}
	return 0;
}