#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m;
inline bool check(int x){
    for (int i = x / n; i <= n && i*i <= x ; i++) {
        if (i != 0 && x % i == 0 && x / i <= n) return true;
    }
    return false;
}
signed main () {
    cin >> n >> m;
    if (n == 0 && m == 0) {
        cout << 0 << '\n';
        return 0;
    }
    if (n*n < m) {
        cout << -1 << '\n';
        return 0;
    }
    int tmp = m/n+1;
    if (m % n == 0) --tmp;
    for (int i = m; i <= tmp*n; i++) {
        if (check(i)) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}