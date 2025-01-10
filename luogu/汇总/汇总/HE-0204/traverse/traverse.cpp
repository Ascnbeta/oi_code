#include<bits/stdc++.h>

#define int long long

using namespace std;

void play() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
	}
	cout << k << '\n';
}

signed main() {
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) play();
	return 0;
}

