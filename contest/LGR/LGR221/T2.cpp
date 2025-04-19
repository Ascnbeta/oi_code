#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int f[503][503];
int v[503];
int a[503];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> f[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int cnt = 0;
            for (int k = 1; k <= m; k++) {
                if (f[i][k] == f[j][k] && f[i][k] == 1) ++cnt;
            }
            if (i == 1) a[j] = cnt;
            if (cnt > v[i]) v[i] = cnt;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (f[1][i]) continue;
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (j == 1) continue;
            if (f[j][i]) {
                if (a[j]+1 >= v[j]) ++tmp;
                else if (a[j] == v[j]) ++tmp;
            }else{
                if (a[j] == v[j]) ++tmp;
            }
            
        }
        ans = max(tmp,ans);
    }
    cout << ans << '\n';
    return 0;
}