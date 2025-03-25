#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+40;
int n,a[maxn],ans;
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        ans += max(a[i-1],a[i]);
    }
    cout << ans << '\n';
    return 0;
}