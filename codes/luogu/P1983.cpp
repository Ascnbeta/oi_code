#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
bool f[1003][1003];
vector<int> e[1003];
int ind[1003];
int s[1003];
bool vis[1003];
struct node{
	int p,cnt;
};
queue<node> q;
inline void topo() {
	memset(vis,0,sizeof(vis));
	for (int i = 1; i <= n; i++) if (!ind[i]) q.push({i,1});
	while (!q.empty()) {
		node u = q.front();
		q.pop();
		vis[u.p] = true;
		ans = max(ans,u.cnt);
		for (auto v : e[u.p]) {
			--ind[v];
			if (!ind[v]) {
				q.push({v,u.cnt+1});
			}
		}
	}
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		memset(vis,0,sizeof(vis));
		int cnt;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++) {
			cin >> s[j];
			vis[s[j]] = true;
		}
		for (int j = s[1]; j <= s[cnt]; j++) {
			if (!vis[j]) {
				for (int k = 1; k <= cnt; k++) {
					if (!f[j][s[k]]) e[j].push_back(s[k]),++ind[s[k]],f[j][s[k]] = true;
				}
			}
		}
	}
	topo();
	cout << ans << '\n';
	return 0;
}