#include <bits/stdc++.h>
using namespace std;
int ans;
bool a[1004];
int c[10],v[10] = {0,1,2,3,5,10,20},v1[2003],tot;
void pre(int x,int n) {
	int tmp = 1;
	while (n > tmp) {
		v1[++tot] = x*tmp;
		n -= tmp;
		tmp *= 2;
	}
	v1[++tot] = x*n;
}
int main () {
	for (int i = 1; i <= 6; i++) {
		cin >> c[i];
		pre(v[i],c[i]);
	}
	a[0] = 1;
	for (int i = 1; i <= tot; i++) {
		for (int j = 1000; j >= v1[i]; j--) {
			if (a[j-v1[i]]) {
				a[j] = 1;
			}
		}
	}
	for (int i = 1; i <= 1000; i++) {
		if (a[i]) ++ans;
	}
	cout << "Total=" << ans << '\n';
	return 0;
}