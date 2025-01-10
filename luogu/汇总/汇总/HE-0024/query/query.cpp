#include <bits/stdc++.h>

using namespace std;

const int maxN = 5e5 + 3;

#define vec vector
#define eb emplace_back

int n;
vec<int> g[maxN];

int dfn[maxN], tot;
int dep[maxN];

int st[22][maxN], lg[maxN];
int get(int x, int y) {
  return dep[x] < dep[y] ? x : y;
}
int ask(int l, int r) {
  if (l == r) return l;
  l = dfn[l], r = dfn[r];
  l > r ? swap(l, r) : void();
  l++;
  int t = lg[r - l + 1];
  return get(st[t][l], st[t][r - (1 << t) + 1]);
}
void dfs(int x, int f) {
  dfn[x] = ++tot;
  dep[x] = dep[f] + 1;
  st[0][dfn[x]] = f;
  for (int to : g[x]) {
    if (to == f) continue;
    dfs(to, x);
  }
}
int val[maxN];

struct ques {
  int l, r, k, id;
  friend bool operator < (const ques &A, const ques &B) {
    return A.k < B.k;
  }
} q[maxN];
int ans[maxN];

int main() {
  freopen("query.in", "r", stdin);
  freopen("query.out", "w", stdout);

  cin.tie(nullptr) -> sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v);
    g[v].eb(u);
  }
  dfs(1, 0);
  for (int t = 1; t <= 19; t++)
    for (int i = 1; i + (1 << t) - 1 <= n; i++)
      st[t][i] = get(st[t - 1][i], st[t - 1][i + (1 << (t - 1))]);
  lg[1] = 0;
  for (int i = 2; i <= n; i++)
    lg[i] = lg[i >> 1] + 1;

  int Q;
  cin >> Q;
  for (int i = 1; i <= Q; i++) {
    cin >> q[i].l >> q[i].r >> q[i].k;
    q[i].id = i;
  }
  sort(q + 1, q + Q + 1);

  for (int i = 1; i <= n; i++) val[i] = i;
  int now = 1;
  for (int i = 1; i <= Q; i++) {
    while (now < q[i].k) {
      val[now] = -1;
      now++;
      for (int j = now; j <= n; j++)
        val[j] = ask(val[j], j - now + 1);
    }
    auto &[l, r, k, id] = q[i];
    int &res = ans[id];
    for (int j = l + k - 1; j <= r; j++)
      res = max(res, dep[val[j]]);
  }

  for (int i = 1; i <= Q; i++)
    cout << ans[i] << '\n';
}
