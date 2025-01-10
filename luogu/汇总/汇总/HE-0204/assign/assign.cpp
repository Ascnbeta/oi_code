#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 5, P = 1e9 + 7;

int n, m, v;

void play() {
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++) {
		int c, d;
		cin >> c >> d;	
	}
	cout << (v * (v - 1) % P + 1) * n % P << '\n';
}

signed main() {
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) play();
	return 0;
}

