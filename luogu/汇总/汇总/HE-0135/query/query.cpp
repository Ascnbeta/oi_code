#include<bits/stdc++.h>
using namespace std;
int n, a, b, k, q;
map<int, vector<int> > l;
map<int, int> dep;
map< pair<int, int> , int> lca_dep;
void dfs(int c, int d) {
	dep[c] = d;
	for (int i = 0; i < l[c].size(); i++) if (!dep[l[c][i]]) dfs(l[c][i], d + 1);
}
int getlca(int a, int b) {
	if (lca_dep[make_pair(a, b)]) return lca_dep[make_pair(a, b)];
	int la = a, lb = b;
	while (dep[a] > dep[b]) for (int i = 0; i < l[a].size(); i++) if (dep[l[a][i]] < dep[a]) a = l[a][i]; 
	while (dep[b] > dep[a]) for (int i = 0; i < l[b].size(); i++) if (dep[l[b][i]] < dep[b]) b = l[b][i]; 
	if (dep[a] != dep[b]) for (int i = 0; i < l[a].size(); i++) if (dep[l[a][i]] < dep[a]) a = l[a][i]; 
	lca_dep[make_pair(la, lb)] = a;
	return a;
}
int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		l[a].push_back(b);
		l[b].push_back(a);
	}
	dfs(1, 1);
	cin >> q;
	while (q--) {
		cin >> a >> b >> k;
		int ans = 1;
		for (int i = a; i + k - 1 <= b; i++) {
			ans = max(ans, getlca(i, i + k -1));
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
