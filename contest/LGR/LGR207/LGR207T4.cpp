#include <bits/stdc++.h>
// #define int long long

using namespace std;
int n,a[1004],ans;
#ifdef int
signed main () {
	
	return 0;
}
#else
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int tmp = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] > tmp) {
			++ans;
			tmp = a[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
#endif

