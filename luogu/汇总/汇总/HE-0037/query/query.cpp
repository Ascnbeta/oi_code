#include <iostream>

using namespace std;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void print(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
	return;
}

const int N = 5e5 + 5;
const int inf = 1e9;

int head[N], to[N << 1], nxt[N << 1], tot;
void add(int u, int v) {
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
	return;
}

int dep[N], fa[N][20];
void dfs(int p, int f) {
	dep[p] = dep[f] + 1;
	fa[p][0] = f;
	for(int i = 1; (1 << i) <= dep[p]; i++) fa[p][i] = fa[fa[p][i - 1]][i - 1];
	
	for(int i = head[p]; i; i = nxt[i]) {
		int y = to[i];
		if(y == f) continue;
		dfs(y, p);
	}
	return;
}
int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--) {
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if(x == y) return x;
	for(int i = 19; i >= 0; i--) {
		if(fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	
	int n = read();
	for(int i = 2; i <= n; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	
	int q = read();
	while(q--) {
		int L = read(), R = read(), k = read();
		int ans = 0;
		for(int l = L; l + k - 1 <= R; l++) {
			int r = l + k - 1, tmp = l;
			for(int p = l + 1; p <= r; p++) tmp = lca(tmp, p);
			ans = max(ans, dep[tmp]);
		}
		
		print(ans);
		putchar('\n');
	}
	return 0;
}
