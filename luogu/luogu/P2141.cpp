#include <bits/stdc++.h>
using namespace std;
int n,a[104],ans;
inline bool check(int x) {
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        for (int j = 1; j <= n; j++) {
            if (i == j || j == x) continue;
            if (a[i] == a[j]) continue;
            if (a[x] == a[i] + a[j]) return true;
        }
    }
    return false;
}
int main () {
    cin >> n;
    for (int i = 1; i <= n ; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}