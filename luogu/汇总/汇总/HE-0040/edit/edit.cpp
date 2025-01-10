#include <bits/stdc++.h>
#define vc vector
#define ct count
using namespace std;

const int N = 1e5 + 5;
char s1[N], s2[N], t1[N], t2[N];

signed main() {
#ifdef wkh
  cin.tie(0) -> sync_with_stdio(false);
#else
  ifstream cin("edit.in");
  ofstream cout("edit.out");
#endif
  int _T; cin >> _T;
  for (int tim = 1; tim <= _T; tim++)
  {
  int n;
  cin >> n >> (s1 + 1) >> (s2 + 1) >> (t1 + 1) >> (t2 + 1);
  vc<int> a1(n + 1), a2(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    a1[i] = a1[i - 1] + s1[i] - '0';
    a2[i] = a2[i - 1] + s2[i] - '0';
    c[i] = c[i - 1] + (s1[i] == s2[i]);
  }
  auto S1 = [&] (int l, int r) { return a1[r] - a1[l - 1]; };
  auto S2 = [&] (int l, int r) { return a2[r] - a2[l - 1]; };
  /*if (ct(t1 + 1, t1 + 1 + n, '0') == 1 && ct(t2 + 1, t2 + 1 + n, '0') == 1) {
    cerr << "qwq : " << string(t1 + 1).find('0') << ", " << string(t2 + 1).find('0') << endl;
    cerr << "ans = " << min(S1(1, n), S2(1, n)) + min(n - S1(1, n), n - S2(1, n)) << endl;
  }*/
  vc<int> b(n + 2);
  for (int i = 1, l1 = 1, l2 = 1; i <= n; i++) {
    if (i == n || t1[i] != t1[i + 1]) {
      if (t1[i] == '1' && i - l1 + 1 >= 2 && S1(l1, i) != 0 && S1(l1, i) != i - l1 + 1) ++b[l1], --b[i + 1];
      l1 = i + 1;
    }
    if (i == n || t2[i] != t2[i + 1]) {
      if (t2[i] == '1' && i - l2 + 1 >= 2 && S2(l2, i) != 0 && S2(l2, i) != i - l2 + 1) ++b[l2], --b[i + 1];
      l2 = i + 1;
    }
  }
  for (int i = 1; i <= n; i++) b[i] += b[i - 1];
  int A = 0;
  for (int i = 1, l = 1; i <= n; i++) {
    if (i == n || bool(b[i]) != bool(b[i + 1])) {
      if (b[i]) {
        A += min(S1(l, i), S2(l, i)) + min((i - l + 1) - S1(l, i), (i - l + 1) - S2(l, i));
      }
      else {
        A += c[i] - c[l - 1];
      }
      l = i + 1;
    }
  }
  cout << A << '\n';
  }
  return 0;
}
