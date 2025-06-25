#include <bits/stdc++.h>
using namespace std;
int n,m,c;
double f[2003][102];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    while (1) {
        cin >> c;
        if (c == 0) break;
        cin >> n >> m;
        if (m > n || m > c || n%2!=m%2) {
            puts("0.000");
            continue;
        }
        if (n > 2000) n = 2000;
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= c; j++) {
                f[i][j] = 0;
                if (j < c) f[i][j] += 1.0*(j+1)/c*f[i-1][j+1];
                if (j > 0) f[i][j] += 1.0*(c-(j-1))/c*f[i-1][j-1];
            }
        }
        printf("%.3f\n",f[n][m]);
    }
    return 0;
}