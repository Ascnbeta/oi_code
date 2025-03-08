#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+20;
int n,l,ans;
vector<int> e[maxn];
int tot[maxn],ind[maxn];
queue<int> q;
inline void topo() {
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 1) q.push(i);
	}
	while (q.size()) {
		int tot = q.size();
		ans += min(l*2,tot);
		for (int i = 1; i <= tot; i++) {
			int u = q.front();
			q.pop();
			for (auto v : e[u]) {
				ind[v]--;
				if (ind[v] == 1) q.push(v);
			}
		}
	}
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> l;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		ind[u]++;
		ind[v]++;
	}
	topo();
	cout << ans << '\n';
	return 0;
}