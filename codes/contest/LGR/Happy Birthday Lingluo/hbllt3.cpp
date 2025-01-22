#include <bits/stdc++.h>
using namespace std;
int n,k;
bool is[1000006];
void solve(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			is[i] = is[x/i] = false;
		}
	}
}
int main () {
	cin >> n >> k;
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	if (k == 0) {
		int tot = 1;
		is[1] = false;
		for (int i = 2 * n - 1; i >= 2; i--) {
			if(!is[i]) {
				cout << i << ' ';
				solve(i);
				++tot;
			}
			if (tot == n) break;
		}
		return 0;
	}
	return 0;
}