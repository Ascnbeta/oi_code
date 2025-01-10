#include <bits/stdc++.h>
using namespace std; 
const int N = 1e5 + 100; 

int n; 
struct Edge {
	int next, to; 
} e[N << 1]; int head[N], cnt; 
inline void add(int x, int y) {
	++ cnt, e[cnt].next = head[x], e[cnt].to = y, head[x] = cnt; 
}
int Size[N], depth[N]; 
void dfs(int x, int fa, int l, int r) {
	Size[x] = (l <= x && x <= r); 
	depth[x] = depth[fa] + 1; 

	for (int i = head[x]; i; i = e[i].next) {
		int y = e[i].to; 
		if (y != fa) {
			dfs(y, x, l, r), Size[x] += Size[y]; 
		}
	}
}

#define lson(x) t[x].son[0]
#define rson(x) t[x].son[1]
#define mid ((l + r) >> 1)

struct node {
	int data, son[2]; 
} t[N * 30]; int numbol, root[N]; 

void updata(int &now, int id, int l, int r, int x, int c) {
	now = ++ numbol; t[now] = t[id]; 
	if (l == r) return t[now].data += c, void(); 
	if (x <= mid) updata(lson(now), lson(id), l, mid, x, c); 
	else updata(rson(now), rson(id), mid + 1, r, x, c); 
	t[now].data = t[lson(now)].data + t[rson(now)].data; 
}
int Query(int fir, int sec, int l, int r, int k) {
	if (l == r) return l; 
	if (t[lson(fir)].data - t[lson(sec)].data >= k) return Query(lson(fir), lson(sec), l, mid, k); 
	else return Query(rson(fir), rson(sec), mid + 1, r, k - t[lson(fir)].data + t[lson(sec)].data); 
}

#undef mid

int q; 

signed main() {
	freopen("query.in", "r", stdin); 
	freopen("query.out", "w", stdout); 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	cin >> n; 
	for (int i = 1, x, y; i < n; ++ i) {
		cin >> x >> y, add(x, y), add(y, x); 
	}
	if (n <= 10000) {
		cin >> q; 
		for (int i = 1; i <= q; ++ i) {
			int l, r, k; cin >> l >> r >> k; 
			dfs(1, 0, l, r); int ans = 0; 
			for (int j = 1; j <= n; ++ j) {
				if (Size[j] >= k) ans = max(ans, depth[j]); 
			}
			cout << ans << '\n'; 
		}
		return 0; 
	}

	cin >> q; 
	dfs(1, 0, 1, 1); 
	for (int i = 1; i <= n; ++ i) updata(root[i], root[i - 1], 1, n, depth[i], 1); 
	for (int i = 1; i <= q; ++ i) {
		int l, r, k; cin >> l >> r >> k; 
		cout << Query(root[r], root[l - 1], 1, n, r - l + 2 - k) << '\n'; 
	}
}