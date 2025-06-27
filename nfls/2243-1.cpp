#include <bits/stdc++.h>
using namespace std;
int n,ans;
inline bool check(int x) {
    string s = to_string(x);
    for (int i = 2; i < s.size(); i++) {
        if (s[i] - s[i-1] != s[1] - s[0]) return false;
    }
    return true;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (check(i)) ++ans;
    }
    cout << ans << '\n';
    return 0;
}