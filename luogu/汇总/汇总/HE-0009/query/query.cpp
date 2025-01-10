#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 5e5 + 10;
struct Query {
	int l, r, k;
} que[N];
struct edge {
	int to, nxt;
} eg[N];
int head[N], egtot;
int n, q, dep[N], p[N];
int st[30][N], root[N];
bool flag2;

void add (int u, int v) {
	eg[++egtot].to = v;
	eg[egtot].nxt = head[u];
	head[u] = egtot;
}

void dfs (int x, int fa) {
	dep[x] = dep[fa] + 1;
	st[0][x] = fa;
	for (int i = 1; i <= 25; i++)
		st[i][x] = st[i - 1][st[i - 1][x]];
	for (int i = head[x]; i; i = eg[i].nxt) {
		int to = eg[i].to;
		if (to == fa) continue; 	
		dfs (to, x);
	} 
} 

int lca (int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	int k = dep[x] - dep[y];
	for (int i = 0; k; i++, k >>= 1)
		if (k & 1) x = st[i][x];
	if (x == y) return x;
	for (int i = 20; i >= 0; i--)
		if (st[i][x] != st[i][y]) 
			x = st[i][x], y = st[i][y];
	return st[0][x];
}

namespace Segment {
	int sum[N << 2];
	void update (int pos) {
		sum[pos] = lca(sum[pos << 1], sum[pos << 1 | 1]); 
	} 
	void build (int pos, int l, int r) {
		if (l == r) {sum[pos] = l; return ;}
		int mid = (l + r) >> 1;
		build (pos << 1, l, mid);
		build (pos << 1 | 1, mid + 1, r);
		update (pos); 
	}
	int query (int pos, int l, int r, int x, int y) {
		if (x <= l && r <= y) return sum[pos];
		int mid = (l + r) >> 1;
		if (y <= mid) return query (pos << 1, l, mid, x, y);
		if (x >= mid + 1) return query (pos << 1 | 1, mid + 1, r, x, y);
		return lca(query (pos << 1, l, mid, x, y), query (pos << 1 | 1, mid + 1, r, x, y));
	}
}

void solve1 () {
	dfs (1, 0);
	Segment::build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int aqz = 0; 
		for (int beg = que[i].l; beg + que[i].k - 1 <= que[i].r; beg++) 
			aqz = std::max(aqz, dep[Segment::query(1, 1, n, beg, beg + que[i].k - 1)]);
		std::cout << aqz << '\n';
	}
}

namespace stu {
	struct Node {
		int num, lmax, rmax, cnt, len;
		int lson, rson;
		Node () {lson = rson = num = lmax = rmax = cnt = len = 0;}
	} a[N * 25];
	int cnt = 0;
	Node operator+ (Node x, Node y) {
		Node z;
		z.cnt = x.cnt + y.cnt;
		z.len = x.len + y.len;
		
		z.lmax = x.lmax;
		if (x.cnt == x.len) z.lmax = std::max(z.lmax, x.len + y.lmax);
		z.rmax = y.rmax;
		if (y.cnt == y.len) z.rmax = std::max(z.rmax, y.len + x.rmax);
		z.num = std::max(x.num, y.num);
		z.num = std::max(z.num, x.rmax + y.lmax);
		return z;
	}
	void modify (int &pos, int last, int l, int r, int k) {
		if (!pos) pos = ++cnt;
//		std::cout << pos << ' ' << l << ' ' << r << '\n';
		if (l == r) {
			a[pos].lmax = a[pos].rmax = a[pos].len = a[pos].cnt = a[pos].num = 1;
			return ;
		}
		int mid = (l + r) >> 1;
		if (k <= mid) {
			a[pos].rson = a[last].rson;
			modify (a[pos].lson, a[last].lson, l, mid, k);
		} else {
			a[pos].lson = a[last].lson;
			modify (a[pos].rson, a[last].rson, mid + 1, r, k);
		}
		int lson = a[pos].lson, rson = a[pos].rson;
		if (!rson) a[pos] = a[lson], a[pos].rmax = 0;
		else if (!lson) a[pos] = a[rson], a[pos].lmax = 0;
		else a[pos] = a[lson] + a[rson];
		a[pos].lson = lson, a[pos].rson = rson;
		a[pos].len = r - l + 1;
	}
	Node query (int pos, int l, int r, int x, int y) {
//		std::cout << pos << '\n'; 
		if (x <= l && r <= y) {
			if (!pos) {
				Node zyt;
				zyt.len = r - l + 1;
				return zyt;
			} else return a[pos];
		}
		int mid = (l + r) >> 1;
		if (y <= mid) return query (a[pos].lson, l, mid, x, y);
		else if (x >= mid + 1) return query (a[pos].rson, mid + 1, r, x, y);
		else return query (a[pos].lson, l, mid, x, y) + query (a[pos].rson, mid + 1, r, x, y);
	}
} 

bool cmp (int x, int y) {
	return dep[x] > dep[y];
}

void solve2 () {
	dfs (1, 0);
	for (int i = 1; i <= n; i++) p[i] = i;
	std::sort (p + 1, p + n + 1, cmp);
	for (int i = 1; i <= n; i++) 
		stu::modify(root[i], root[i - 1], 1, n, p[i]);
	for (int i = 1; i <= q; i++) {
		int L = 1, R = n;
		while (L < R) {
			int mid = (L + R) >> 1;
			int now = stu::query (root[mid], 1, n, que[i].l, que[i].r).num;
			if (now < que[i].k) L = mid + 1;
			else R = mid;
		}
		std::cout << n - L + 1 << '\n';
	}
}

int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	std::cin >> n;
	for (int i = 1, x, y; i < n; i++) {
		std::cin >> x >> y;
		add(x, y), add(y, x);
	}
	std::cin >> q;
	for (int i = 1; i <= q; i++) {
		std::cin >> que[i].l >> que[i].r >> que[i].k; 
		if (que[i].k != que[i].r - que[i].l + 1) flag2 = true;
	}
	if (n <= 5000 || !flag2) solve1 ();
	else solve2 ();
	return 0;
} 
