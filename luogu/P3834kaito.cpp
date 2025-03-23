#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define N 200010
using namespace std;
int num[N];
vector<int> a;
struct node {
	int l, r, sum;
}tree[40 * N];
int tot;
int root[N];
void pushup(int u) {
	int lc = tree[u].l;
	int rc = tree[u].r;
	tree[u].sum = tree[lc].sum + tree[rc].sum;
}
int build(int l, int r) {
	int p = ++tot;
	tree[p].sum = 0;
	if (l != r) {
		int mid = (l + r) / 2;
		tree[p].l = build(l, mid);
		tree[p].r = build(mid + 1, r);
	}
	return p;
}
int insert(int last, int l, int r, int pos, int v) {
	int p = ++tot;
	tree[p].l = tree[last].l; tree[p].r = tree[last].r; tree[p].sum = tree[last].sum;
	int mid = (l + r) / 2;
	if (l == r) {
		tree[p].sum += v;
		return p;
	}
	if (pos <= mid) {
		tree[p].l = insert(tree[last].l, l, mid, pos, v);
	}
	else {
		tree[p].r = insert(tree[last].r, mid + 1, r, pos, v);
	}
	pushup(p);
	return p;
}
int query(int p1, int p2, int l, int r, int rank) {
	if (l == r) {
		return l;
	}
	int mid = (l + r) / 2;
	int tmp = tree[tree[p2].l].sum - tree[tree[p1].l].sum;
	if (rank <= tmp) {
		return query(tree[p1].l, tree[p2].l, l, mid, rank);
	}
	else return query(tree[p1].r, tree[p2].r, mid + 1, r, rank - tmp);
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/b.out","w",stdout);
#endif
	int n, m;
	cin >> n >> m;
	a.push_back(-1);
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		a.push_back(num[i]);
	}

	sort(a.begin() + 1, a.end());
	a.erase(unique(a.begin() + 1, a.end()), a.end());
	int siz = a.size() - 1;
	root[0] = build(1, siz);
	for (int i = 1; i <= n; i++) {
		int idx = lower_bound(a.begin(), a.end(), num[i]) - a.begin();
		root[i] = insert(root[i - 1], 1, siz, idx, 1);
	}

	for (int i = 1; i <= m; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		int ans = query(root[l - 1], root[r], 1, siz, k);
		cout << a[ans] << '\n';
	}
	return 0;
}