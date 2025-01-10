#include <bits/stdc++.h>
#define vc vector
#define pb push_back
#define IL inline
using namespace std;

const int N = 5e5 + 5;
int n, I[N], tot, f[20][N], dep[N], st[20][N];
vc<int> g[N];
void D(int u, int fa) {
  f[0][I[u] = ++tot] = fa;
  dep[u] = dep[fa] + 1;
  for (int v : g[u]) if (v ^ fa) {
    D(v, u);
  }
}
IL int C(int u, int v) { return dep[u] < dep[v] ? u : v; }
void init() {
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n - (1 << j) + 1; i++)
      f[j][i] = C(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
}
IL int lca(int u, int v) {
  if (u == v) return u;
  if ((u = I[u]) > (v = I[v])) swap(u, v);
  int k = __lg(v - u++);
  return C(f[k][u], f[k][v - (1 << k) + 1]);
}
void init2() {
  for (int i = 1; i <= n; i++) st[0][i] = i;
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n - (1 << j) + 1; i++)
      st[j][i] = lca(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
IL int Q(int l, int r) {
  int k = __lg(r - l + 1);
  return lca(st[k][l], st[k][r - (1 << k) + 1]);
}

signed main() {
#ifdef wkh
  cin.tie(0) -> sync_with_stdio(false);
#else
  ifstream cin("query.in");
  ofstream cout("query.out");
#endif
  cin >> n;
  for (int i = 2, u, v; i <= n; i++)
    cin >> u >> v, g[u].pb(v), g[v].pb(u);
  D(1, 0), init(), init2();
  int q; cin >> q;
  if (n <= 5e3)
  {
  for (int tim = 1; tim <= q; tim++) {
    int l, r, k; cin >> l >> r >> k;
    int A = 0;
    for (int i = l; i <= r - k + 1; i++)
      A = max(A, dep[Q(i, i + k - 1)]);
    cout << A << '\n';
  }
  }
  else {
  for (int tim = 1; tim <= q; tim++) {
    int l, r, k; cin >> l >> r >> k;
    cout << dep[Q(l, r)] << '\n';
  }
  }
  return 0;
}
