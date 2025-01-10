#include <bits/stdc++.h>

using namespace std;

#define emp emplace

const int maxN = 1e5 + 5;

int n;

struct Str {
  string s, t;
  int col[maxN], tot;
  int c[2][maxN];
  void init() {
    for (int i = 1; i <= n; i++) {
      if (t[i] == '1' && t[i - 1] != '1')
        tot++;
      if (t[i] == '1') {
        col[i] = tot;
        c[s[i] - '0'][col[i]]++;
      }
    }
  }
  void clear() {
    for (int i = 1; i <= tot; i++) c[0][i] = c[1][i] = 0;
    for (int i = 1; i <= n; i++) col[i] = 0;
    tot = 0;
  }
} A, B;

void Main() {
  cin >> n;
  cin >> A.s >> B.s;
  cin >> A.t >> B.t;
  A.s = '@' + A.s, B.s = '%' + B.s;
  A.t = '!' + A.t, B.t = '^' + B.t;
  A.init(), B.init();
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!A.col[i] && !B.col[i])
      ans += A.s[i] == B.s[i];
    else {
      if (A.col[i] && B.col[i]) {
        int ca = A.col[i], cb = B.col[i];
        if (A.c[0][ca] && B.c[0][cb])
          ans++, A.c[0][ca]--, B.c[0][cb]--;
        else if (A.c[1][ca] && B.c[1][cb])
          ans++, A.c[1][ca]--, B.c[1][cb]--;
        else if (A.c[0][ca])
          A.c[0][ca]--, B.c[1][cb]--;
        else if (A.c[1][ca])
          A.c[1][ca]--, B.c[0][cb]--;
      } else if (A.col[i]) {
        int l = B.s[i] - '0';
        if (A.c[l][A.col[i]])
          ans++, A.c[l][A.col[i]]--;
        else A.c[l ^ 1][A.col[i]]--;
      } else {
        int l = A.s[i] - '0';
        if (B.c[l][B.col[i]])
          ans++, B.c[l][B.col[i]]--;
        else B.c[l ^ 1][B.col[i]]--;
      }
    }
  }

  cout << ans << '\n';

  A.clear(), B.clear();
}

int main() {
  freopen("edit.in", "r", stdin);
  freopen("edit.out", "w", stdout);
  
  cin.tie(nullptr) -> sync_with_stdio(false);

  int tims;
  cin >> tims;
  while (tims--)
    Main();
}
