#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int main () {
	cin >> T;
	while (T--) {
		cin >> n;
		if (n <= 4) {
			puts("-1");
			continue;
		}else{
			int x = n,tot = 0;
			for (int i = 1; i <= n; i += 2) {
				if (i == 5) continue;
				cout << i << ' ';
			}
			cout << "5 4" << ' ';
			for (int i = 2; i <= n; i += 2) {
				if (i == 4) continue;
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}