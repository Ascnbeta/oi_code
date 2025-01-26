#include <bits/stdc++.h>
using namespace std;
int x1,_y1,x2,y2,n,ans = INT_MAX;
struct dd{
	int x,y;
	int d1,d2;
}d[100005];
int max_d2[100005]; 
bool cmp1(dd x,dd y) {
	return x.d1 < y.d1;
}
bool cmp2(dd x,dd y) {
	if (x.d2 == y.d2) return x.d1 < y.d1;
	return x.d2 > y.d2;
}
int main () {
	cin >> x1 >> _y1 >> x2 >> y2 >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i].x >> d[i].y;
		d[i].d1 = (d[i].x-x1)*(d[i].x-x1)+(d[i].y-_y1)*(d[i].y-_y1);
		d[i].d2 = (d[i].x-x2)*(d[i].x-x2)+(d[i].y-y2)*(d[i].y-y2);;
	}
//	for (int i = 1; i <= n; i++) {
//		cout << d[i].d1 << ' ' << d[i].d2 << endl;
//	}
	sort(d+1,d+n+1,cmp1);
	max_d2[n] = 0;
	for (int i = n-1; i >= 1; i--) {
		if (i == n-1) max_d2[i] = d[i+1].d2;
		else max_d2[i] = max((int)d[i+1].d2,max_d2[i+1]);
	}
	for (int i = 1; i <= n; i++) {
		if (d[i].d1 + max_d2[i] < ans) {
			ans = d[i].d1 + max_d2[i];
		}
	}
	cout << ans << endl;
	return 0;
}
