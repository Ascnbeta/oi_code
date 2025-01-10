#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5; 

vector <int> e[N]; 

int f[N][25];

void dfs(int u, int fa, int dep) {
	f[u][0] = dep;
	for (int v : e[u]) {
		if (v == fa) continue;
		dfs(v, u, dep + 1);
	} 

} 

int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	cin.tie(0); ios::sync_with_stdio(0);
	int n; cin >> n; 
	
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v; 
		e[u].push_back(v); 
		e[v].push_back(u); 
	} 
	dfs(1, 0, 1); 
	int lg = log2(n);
	for (int i = 1; i <= lg; i++) 
		for (int j = 1 ; j <= n; j++) 
			f[j][i] = min(f[j][i - 1], f[j + (1 << i - 1) + 1][i - 1]);
	
	int q; cin >> q;

	while (q--) {
		int l, r, k; cin >> l >> r >> k;
		int lgs = log2(r - l + 1);
		cout << max(f[l][lgs], f[r - (1 << lgs) + 1][lgs]) << "\n";
	}
	return 0; 
} 
 
