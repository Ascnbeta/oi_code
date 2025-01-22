#include <bits/stdc++.h>
using namespace std;
int a,b,n;
int ans = 0;
int p[40003],tot;
bool f[40000];
void init() {
	for (int i = 2; i * i <= b; i++) {
		if (!f[i]) {
			p[++tot] = i;
		}
		for (int j = 1; j <= tot && p[j]*i <= sqrt(b); j++) {
			f[p[j]*i] = true;
			if (i%p[j] == 0) break;
		}
	}
	// for (int i = 1; i <= tot; i++) {
	// 	cout << p[i] << ' ';
	// }
	// cout << '\n';
}
int get(int x) {
	if (x == 1) return 1;
	int ret = 1;
	for (int i = 1; i <= tot && p[i] * p[i] <= x  && x != 1 ; i++) {
		if (x % p[i] == 0) {
			int tmp = 0;
			while (x % p[i] == 0) {
				x /= p[i];
				++tmp;
			}
			ret *= tmp+1;
		}
	}
	if (x > 1) {
		ret *= 2;
	}
	return ret;
}
int main () {
	cin >> a >> b >> n;
	init();
	for (int i = a; i <= b; i++) {
		int tmp = 0; 
		tmp = get(i);
		if (tmp == n) {
			++ans;
			// cout << i << '\n';
		}
	}
	cout << ans << '\n';
	return 0;
}