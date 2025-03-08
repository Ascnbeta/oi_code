#include <bits/stdc++.h>
using namespace std;
int t,n,m,ans;
int p[104][100],f[10004];
int main () {
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> p[i][j];
        }
    }
    ans = m;
    for (int i = 1; i < t; i++) {
        memset(f,0,sizeof(f));
        for (int j = 1; j <= n; j++) {
            for (int k = p[i][j]; k <= 10000; k++) {
                f[k] = max(f[k],f[k-p[i][j]]+p[i+1][j]-p[i][j]);
            }
        }
        for (int j = 0; j <= ans; j++) {
            m = max(ans,f[j]+ans);
        }
        ans = m;
    }
    cout << ans << '\n';
    return 0;
}