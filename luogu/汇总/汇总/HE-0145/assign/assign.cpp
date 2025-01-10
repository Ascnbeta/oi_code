#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int M = 1e5 + 5, mod = 1e9 + 7;

int c[M], d[M];

int main() {
	freopen("assign.int","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T --) {
		int n, m, v;
		ll ans = 1;
		cin >> n >> m >> v;
		for(int i = 1; i <= m; ++ i) cin >> c[i] >> d[i];
		for(int i = 1; i <= n; ++ i)
			ans = (ans * (v - 1) % mod * v % mod + ans) % mod;
		cout << ans << endl;
	}

	return 0;
}
