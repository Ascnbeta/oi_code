#include <iostream>
#include <cstdio>

using namespace std;
const int N = 5e5 + 10;

int n, q, l, r, k, tot;
int head[N], lca[N];
int fa[N], st[N][21], dep[N];
struct Map { int to, nxt; } e[N << 1];

void add (int u, int v) {
	e[++tot] = {v, head[u]};
	head[u] = tot;
}

void dfs (int u, int f) {
	fa[u] = f, dep[u] = dep[f] + 1, st[u][0] = f;
	for(int i = 1; i <= 20; ++i)
		st[u][i] = st[st[u][i - 1]][i - 1];
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == f) continue;
		dfs(v, u);
	} 
}

int Lca (int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i >= 0; --i) 
		if(dep[st[x][i]] >= dep[y])
			x = st[x][i];
	if(x == y) return x;
	for(int i = 20; i >= 0; --i) 
		if(st[x][i] != st[y][i])
			x = st[x][i], y = st[y][i];
	return st[x][0];
}

int main () {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	cin >> n;
	for(int i = 1, u, v; i < n; ++i)
		cin >> u >> v, add(u, v), add(v, u);
	dfs(1, 0);
	cin >> q;
	while(q--) {
		int res = 0;
		cin >> l >> r >> k;
		for(int i = l; i + k - 1 <= r; ++i) {
			int j = i + k - 1;
			int x = i;
			for(int o = i + 1; o <= j; ++o) 
				x = Lca(x, o);
			res = max(res, dep[x]);
		}
		cout << res << endl;
	}
}
