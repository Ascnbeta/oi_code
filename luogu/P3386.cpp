#include <bits/stdc++.h>
using namespace std;
const int maxn = 504;
int n,m,E,ans;
vector<int> e[maxn];
bool f[maxn][maxn];
int vis[maxn];
int match[maxn];
bool hungary(int p,int cur) {
	if (vis[p] == cur) return false;
	vis[p] = cur; 
	for (const auto &v : e[p]) {
		if (!match[v] || hungary(match[v],cur)) {
			match[v] = p;
			return true;
		}
	}
	return false;
}
int main () {
	cin >> n >> m >> E;
	for (int i = 1; i <= E; i++) {
		int u,v;
		cin >> u >> v;
		if (f[u][v]) continue;
		e[u].push_back(v);
		f[u][v] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (hungary(i,i)) ++ans;
	}
	cout << ans << '\n';
	return 0;
}