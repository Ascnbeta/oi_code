#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int de[N];
int n, q;
vector<int> g[N];
inline void dfs(int u, int fa){
	de[u] = de[fa] + 1;
	for(int i = 0 ; i < (int)g[u].size() ; i++){
		int v = g[u][i];
		if(v == fa) continue;
		dfs(v, u);
	}
}
signed main(){
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n - 1 ; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> q;
	dfs(1, 0);
	while(q--){
		int l, r, k;
		int ans = 0x3f3f3f3f3f;
		cin >> l >> r >> k;
		for(int i = l ; i <= r ; i++){
			ans = min(ans, de[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}

