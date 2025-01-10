#include <bits/stdc++.h>
#define vc vector
using namespace std;

signed main() {
#ifdef wkh
  cin.tie(0) -> sync_with_stdio(false);
#else
  ifstream cin("assign.in");
  ofstream cout("assign.out");
#endif
  const int P = 1e9 + 7;
  auto Q = [&] (int a, int b) {
    int r = 1;
    for (; b; a = 1LL * a * a % P, b >>= 1)
      if (b & 1) r = 1LL * r * a % P;
    return r;
  };
  int _T; cin >> _T;
  for (int tim = 1; tim <= _T; tim++)
  {
  int n, m, v; cin >> n >> m >> v;
  vc<int> c(m + 1), d(m + 1);
  for (int i = 1; i <= m; i++) cin >> c[i] >> d[i];
  if (m == 1) {
    cout << Q(1LL * v * v % P, n - 1) << '\n';
    continue;
  }
  }
  return 0;
}
