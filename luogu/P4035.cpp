#include <bits/stdc++.h>
using namespace std;
int n;
double a[13][13];
double mat[13][13];
double ans[13];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            mat[i][j] = -2*a[i][j];
            mat[i][n+2] += -a[i][j]*a[i][j];         
        }
        mat[i][n+1] = 1;
    }
    for (int i = 1; i <= n+1; i++) {
        int r = i;
        for (int j = i+1; j <= n+1; j++) {
            if (fabs(mat[r][i]) < fabs(mat[j][i])) r = j;
        }
        if (r != i) swap(mat[i],mat[r]);
        double tmp = mat[i][i];
        for (int j = i; j <= n+2; j++ ) mat[i][j] /= tmp;
        for (int j = i+1; j <= n+1; j++) {
            tmp = mat[j][i];
            for (int k = i; k <= n+2; k++) {
                mat[j][k] -= mat[i][k]*tmp;
            }
        }
    }
    ans[n+1]=mat[n+1][n+2];
    for (int i = n; i >= 1; i--) {
        ans[i] = mat[i][n+2];
        for (int j = i+1; j <= n+1; j++) {
            ans[i] -= ans[j]*mat[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%.3f ",ans[i]);
    }
    return 0;
}