#include <bits/stdc++.h>

#define ls k << 1
#define rs k << 1 | 1

const int N = 5e5 + 5;

int n, u, v, q, l, r, k;
int head[N], cnt;
struct edge {
    int nxt, to;
} e[N << 1];
int dep[N], fa[N][25]; //20
struct node {
    int l, r;
    int data;
} c[N << 2];

int read() {
	int res = 0, i = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') i = -i;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * i;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void dfs(int k, int f) {
    dep[k] = dep[f] + 1;
    fa[k][0] = f;
    for (int i = 1; i <= 20; ++i)
        fa[k][i] = fa[fa[k][i - 1]][i - 1];
    for (int i = head[k]; i; i = e[i].nxt)
        if (e[i].to != f)
            dfs(e[i].to, k);
}

int LCA(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    int tmp = dep[x] - dep[y], cnt = 0;
    while (tmp) {
        if (tmp & 1) x = fa[x][cnt];
        ++cnt;
        tmp >>= 1;
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; --i)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

void build(int k, int l, int r) {
    c[k].l = l, c[k].r = r;
    if (l == r) return c[k].data = l, void();
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    c[k].data = LCA(c[ls].data, c[rs].data);
}

int query(int k, int l, int r) {
    if (l <= c[k].l && c[k].r <= r) return c[k].data;
    int mid = c[k].l + c[k].r >> 1;
    if (l <= mid && r > mid)
        return LCA(query(ls, l, r), query(rs, l, r));
    if (l <= mid) return query(ls, l, r);
    if (r > mid) return query(rs, l, r);
}

int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
    n = read();
    for (int i = 1; i < n; ++i) {
        u = read(), v = read();
        add(u, v), add(v, u);
    }
    dfs(1, 0);
    build(1, 1, n);
    q = read();
    while (q--) {
        l = read(), r = read(), k = read();
        int ans = 0;
        for (int i = 1; i <= r - k + 1; ++i)
            ans = std::max(ans, dep[query(1, i, i + k - 1)]);
        write(ans), puts("");
    }
    return 0;
}
