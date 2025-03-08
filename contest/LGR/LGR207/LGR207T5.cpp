#include <bits/stdc++.h>
// #define int long long

using namespace std;
int n,x,ans[7],c[7];
#ifdef int
signed main () {

	return 0;
}
#else
int main() {
	cin >> x >> n;
	for (int i = 1; i <= n; i++) {
		cin>> c[1] >> c[2] >> c[3] >> c[4] >> c[5];
		sort(c+1,c+6);
		for (int j = 5; j >= 1; j--) {
			if (x >= c[j]) {
				++ans[c[j]];
				x -= c[j];
				break;
			}
		}
	}
	for (int i = 1; i <= 5; i++) {
		cout << ans[i] << ' ';
	}

	cout << '\n' << x << '\n';
	return 0;
}
#endif

 