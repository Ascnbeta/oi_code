#include <bits/stdc++.h>
using namespace std;
int n,k;
struct num{
	int p,a;
}a[200004];
bool cmp(num x,num y) {
	if (x.a == y.a) return x.p > y.p;
	return x.a > y.a;
}
int ans[200004];
int main () {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i].a,a[i].p = i;
	sort(a+1,a+n+1,cmp);
	int tmp = 0, j = 1;
	for (int i = 2; i <= n; i++) {
		if (a[j].a == a[i].a) {
			ans[a[i].p] = 0;
		}else{
			int t = (a[j].a- a[i].a - 1) / k;
			if (t > ans[a[j].p]) ans[a[i].p] = 0;
			else ans[a[i].p] = ans[a[j].p] - t + 1;
			j = i; 
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}