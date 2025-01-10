#include <bits/stdc++.h>
using namespace std;
mt19937 t(time(0));
int cr(int l,int r) {
    int ret = (int)((1.0 * t() / UINT_MAX) * (r - l + 1)) + l;
    return ret;
}
bool d[4],a[4];
int c[4];
int suc,fai;
int main () {
	int num;
	cin >> num;
	
	for (int j = 1; j <= num; j++) {
		d[1] = d[2] = d[3] = a[1] = a[2] = a[3] = false;
		int x = cr(1,3),y = cr(1,3);
		// cout << x << ' ' << y << '\n';
		a[y] = true;
		d[x] = true;
		int tot = 0;
		if (x == y) 
		
	}
	cout << 1.0 * suc / num << '\n';
	return 0;
}