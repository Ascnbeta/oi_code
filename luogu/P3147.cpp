#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+30;
int f[maxn][70];
int n,ans,a[maxn];
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][a[i]]=i;
        ans = max(ans,a[i]);
    }
    for (int i = 1; i <= 70; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[j][i-1] != 0) {
                f[j][i] = f[f[j][i-1]+1][i-1];
                if (f[j][i]) ans = max(ans,i);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}