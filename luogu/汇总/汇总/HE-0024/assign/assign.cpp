#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = 1e5 + 7;
const int mod = 1e9 + 7;

int ksm(int a, int b) {
  a %= mod;
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int n, m, v;

struct lim {
  int p, v;
} a[maxN];

int f[maxN], g[maxN];

void Main() {
  cin >> n >> m >> v;
  for (int i = 1; i <= m; i++)
     cin >> a[i].p >> a[i].v;
  sort(a + 1, a + m + 1, [](lim A, lim B) {
    return A.p < B.p;
  });

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (i == 1) {
      f[1] = 0;
      g[1] = 0;
      continue;
    }
    if (i > 1 && a[i].p == a[i - 1].p && a[i].v != a[i - 1].v)
      return cout << "0\n", void();

    if (i > 1 && a[i].p == a[i - 1].p) {
      f[i] = f[i - 1];
      g[i] = g[i - 1];
      continue;
    }
    f[i] = (ksm(v * v, a[i - 1].p - 1) - g[i - 1] + mod) % mod * ksm(v, a[i].p - a[i - 1].p - 1) % mod * (v - 1) % mod;
    g[i] = (f[i] + g[i - 1] * ksm(v * v, a[i].p - a[i - 1].p) % mod + mod) % mod;
//    cout << i << " : " << f[i] << '\n';
//    cout << ksm(v * v, a[i - 1].p - 1) - g[i - 1] << '\n';
    ans += f[i] * ksm(v * v, n - a[i].p) % mod;
    ans %= mod;
  }
  //cerr << '\n';

  ans = ksm(v * v, n - 1) - ans + mod;
  ans %= mod;
  cout << ans << '\n';
}

signed main() {
  freopen("assign.in", "r", stdin);
  freopen("assign.out", "w", stdout);
  //freopen("in.in", "r", stdin);

  cin.tie(nullptr) -> sync_with_stdio(false);

  int Tims;
  cin >> Tims;
  while (Tims--)
    Main();
}
