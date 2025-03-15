#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int n;
double mat[103][103];
double ans[103];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n+1; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int r = i;
        for (int j = i + 1; j <= n; j++) {
            if (fabs(mat[r][i]) < fabs(mat[j][i])) r = j;
        }
        if (fabs(mat[r][i]) < eps) {
            puts("No Solution");
            return 0;
        }
        if (r != i) swap(mat[i],mat[r]);
        double tmp = mat[i][i];
        for (int j = i; j <= n+1; j++) mat[i][j] /= tmp;
        for (int j = i+1; j <= n; j++) {
            tmp = mat[j][i];
            for (int k = i; k <= n+1; k++) {
                mat[j][k] -= mat[i][k] * tmp;
            }
        }
    }
    ans[n] = mat[n][n+1];
    for (int i = n-1; i >= 1; i--) {
        ans[i] = mat[i][n+1];
        for (int j = i+1; j <= n; j++) {
            ans[i] -= (mat[i][j]*ans[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(2) << ans[i] << '\n';
    }
    return 0;
}