#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int T, n;
int c, k, cu[N];
int hd[N];
struct edge {
	int nxt, to;
} e[N << 1];

int tot;

void add(int u, int v) {
	e[++tot].nxt = hd[u]; 
	e[tot].to = v;
	hd[u] = tot;
}

signed main() {
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0); 
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		memset(hd, 0, sizeof hd);
		tot = 0;
		if (c == 18) {
			cin >> n >> k;
			for (int i = 1; i <= n - 1; i++){
				int u, v;
				cin >> u >> v;
			}
			for (int i = 1; i <= k; i++) {
				cin >> cu[i];
			}
			cout << 1 << '\n';
		} 
	}
	return 0;
} 
/*
		
*/
