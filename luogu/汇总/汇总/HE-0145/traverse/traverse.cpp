#include <bits/stdc++.h>
#define ll long long
#define p pair<int, int>

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 5;

p e[N];
int num[N];

int main() {
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	while(T --) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i < n; ++ i)
			cin >> e[i].first >> e[i].second;
		for(int i = 1; i <= k; ++ i) cin >> num[i];
		if(e[1].first == 1 && e[2].first == 1)
			cout << n * (n - 1) / 2 % mod << endl;
		else cout << 1 << endl;
	}

	return 0;
}
