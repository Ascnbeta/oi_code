#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100004],m,p1,s1,s2;
int l,h;
signed main () {
    cin >> n;
    for (int i = 1; i <= n ;i++) cin >> a[i];
    cin >> m >> p1 >> s1 >> s2;
    a[p1] += s1;
    for (int i = 1; i <= n; i++) {
        if (i < m) l += a[i] * (m - i);
        if (i > m) h += a[i] * (i - m);
    }
    if (l == h) {
        cout << m << '\n';
    }else if (l < h) {
        int min = h - l,ans = m;
        for (int i = 1; i < m; i++) {
            if (abs(l + s2 * (m - i) - h) < min || ((ans == m) && abs(l + s2 * (m - i) - h) == min)) {
                min = abs(l + s2 * (m - i) - h);
                ans = i;
            }
        }
        cout << ans << '\n';
    }else{
        int min = l - h,ans = m;
        for (int i = m + 1; i <= n; i++) {
            if (abs(h + s2 * (i - m) - l) < min || ((ans == m) && abs(h + s2 * (i - m) - l) == min)) {
                min = abs(h + s2 * (i - m) - l);
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}