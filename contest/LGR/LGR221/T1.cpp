#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
int n,t;
int l[maxn],r[maxn];
int ans;
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        if (i >= 2 && l[i] - r[i-1] >= t) ans += l[i]-r[i-1]-t;
    }
    cout << ans << '\n';
    return 0;
}