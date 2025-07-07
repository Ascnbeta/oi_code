#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int t,n,a[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = 1;
        for (int i = 2; i < n; i++) {
            ans += (a[i-1]>a[i]&&a[i]<a[i+1]);
        }
        cout << ans << '\n';
    }
    return 0;
}