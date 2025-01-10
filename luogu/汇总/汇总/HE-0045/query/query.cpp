#include <bits/stdc++.h>
#define lep(i, a, b) for (int i = a; i <= b; ++i)
#define rep(i, a, b) for (int i = a; i >= b; --i)
#define ep(i, u) for (int i = H[u]; i; i = e[i].n)

const int _ = 5e5 + 7;
const int lim = 22;

int n, q, dep[_], fa[_][lim + 1], idx, fid[_];
int st[_][lim + 1], ed[_][lim + 1], Log[_];
std::vector <int> e[_];

void D(int u, int f) {
	dep[u] = dep[fa[u][0] = f] + 1, fid[u] = ++idx;
	lep(i, 1, lim) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v : e[u]) if (v != f) D(v, u);
}
int L(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	rep(i, lim, 0) if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	rep(i, lim, 0) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void I() {
	lep(i, 1, n) st[i][0] = ed[i][0] = i;
	lep(j, 1, lim)
		lep(i, 1, n - (1 << j) + 1)
			st[i][j] = fid[st[i][j - 1]] < fid[st[i + (1 << j - 1)][j - 1]] ? st[i][j - 1] : st[i + (1 << j - 1)][j - 1],
			ed[i][j] = fid[ed[i][j - 1]] > fid[ed[i + (1 << j - 1)][j - 1]] ? ed[i][j - 1] : ed[i + (1 << j - 1)][j - 1];
	Log[2] = 1;
	lep(i, 3, n) Log[i] = Log[i >> 1] + 1;
}
int Mx(int l, int r) {
	int k = Log[r - l + 1];
	return fid[ed[l][k]] > fid[ed[r - (1 << k) + 1][k]] ? ed[l][k] : ed[r - (1 << k) + 1][k];
}
int Mn(int l, int r) {
	int k = Log[r - l + 1];
	return fid[st[l][k]] < fid[st[r - (1 << k) + 1][k]] ? st[l][k] : st[r - (1 << k) + 1][k];
}
int S(int l, int r, int k) {
	if (r - l + 1 < k) return 0;
	int x = Mx(l, r), n = Mn(l, r), res = 0;
	if (n < x) std::swap(n, x);
	res = dep[L(x, n)];
	res = std::max(res, std::max(S(l, n - 1, k), S(x + 1, r, k)));
	return res;
}
int read() {
	int x = 0; char c = getchar();
	while (c < '0' or c > '9') c = getchar();
	while (c >= '0' and c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}

int main() {
	
	freopen("query.in", "r", stdin);
	freopen("query.out","w",stdout);
	
	n = read(); int u, v;
	lep(i, 1, n - 1) u = read(), v = read(), e[u].push_back(v), e[v].push_back(u);
	
	q = read();
	D(1, 0); I(); int l, r, k;
	while (q--) {
		l = read(), r = read(), k = read();
		printf("%d\n", S(l, r, k));
	}
	return 0;
}
