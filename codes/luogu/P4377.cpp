<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int n,W;
long double w[256],t[256];
long double f[1003];
inline bool check(long double x) {
	for (int i = 1; i <= W; i++) f[i] = -1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = W; j >= 0; j--) {
			int tmpj = min(j+w[i],(long double)W);
			f[tmpj] = max((long double)f[tmpj],f[j]+t[i]-x*w[i]);
		}
	}
	return f[W] >= 0;
}
int main () {
	cin >> n >> W;
	for (int i = 1; i <= n; i++) cin >> w[i] >> t[i];
	long double l = 0,r = 2.5e5;
	while (r - l > eps) {
		long double mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
		}else{
			r = mid;
		}
	}
	cout << (int)((l+eps)*1000) << '\n';
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int n,W;
long double w[256],t[256];
long double f[1003];
inline bool check(long double x) {
	for (int i = 1; i <= W; i++) f[i] = -1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = W; j >= 0; j--) {
			int tmpj = min(j+w[i],(long double)W);
			f[tmpj] = max((long double)f[tmpj],f[j]+t[i]-x*w[i]);
		}
	}
	return f[W] >= 0;
}
int main () {
	cin >> n >> W;
	for (int i = 1; i <= n; i++) cin >> w[i] >> t[i];
	long double l = 0,r = 2.5e5;
	while (r - l > eps) {
		long double mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
		}else{
			r = mid;
		}
	}
	cout << (int)((l+eps)*1000) << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}