#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
int n, q;
vector<int> edge[MAXN];
int dep[MAXN], sz[MAXN], son[MAXN], fa[MAXN], top[MAXN];
int st[MAXN][25];
int lg2[MAXN];

inline int rd() {
	int x = 0, k = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') k = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return k * x;
}
inline void wt(int num) {
	if (num < 0) putchar('-'), num = -num;
	int st[25], top = 0;
	do {st[++top] = num % 10; num /= 10;} while (num);
	while (top) putchar(st[top--] + '0');
}

void dfs1(int pos, int f) {
	dep[pos] = dep[f] + 1;
	sz[pos] = 1;
	fa[pos] = f;
	for (int to : edge[pos]) {
		if (to == f) continue;
		dfs1(to, pos);
		sz[pos] += sz[to];
		if (sz[to] > sz[son[pos]]) {
			son[pos] = to;
		}
	}
}
void dfs2(int pos, int tp) {
	top[pos] = tp;
	if (!son[pos]) return;
	dfs2(son[pos], tp);
	for (int to : edge[pos]) {
		if (to == fa[pos] || to == son[pos]) continue;
		dfs2(to, to);
	}
}
int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

void buildst() {
	for (int i = 1; i <= n; i++) {
		st[i][0] = i;
	}
	for (int j = 1; j <= 20; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st[i][j] = LCA(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
		}
	}
	for (int i = 2; i <= n; i++) {
		lg2[i] = lg2[i >> 1] + 1;
	}
}

int query(int l, int r) {
	int tmp = lg2[r - l + 1];
	return LCA(st[l][tmp], st[r - (1 << tmp) + 1][tmp]);
}

int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	
	n = rd();
	for (int i = 1; i < n; i++) {
		int u, v; u = rd(); v = rd();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	dfs1(1, 0); dfs2(1, 1);
	buildst();
	
	q = rd();
	for (int i = 1; i <= q; i++) {
		int l, r, k; l = rd(); r = rd(); k = rd();
		int ans = 0;
		for (int i = l; i + k - 1 <= r; i++) {
			int p = query(i, i + k - 1);
			if (dep[p] > dep[ans]) {
				ans = p;
			}
		}
//		cerr << ans << endl;
		wt(dep[ans]); putchar('\n');
	}
	
	return 0;
} 

/*
6
5 6
6 1
6 2
2 3
2 4
3
2 5 2
1 4 1
1 6 3
*/
