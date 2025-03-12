#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k;
    ans = n * k;
    for (int l = 1,r; l <= n; l=r+1) {
        if (k/l != 0) r = min(k/(k/l),n);
        else r = n;
        ans -= (l+r)*(r-l+1)/2*(k/l);
    }
    cout << ans << '\n';
    return 0;
}