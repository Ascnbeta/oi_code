#include <bits/stdc++.h>
using namespace std;
int n,k;
long long ans;
long long f[12][1024][100];
inline bool check(int a,int b) {
    if ((a << 1) & a) return false;
    if ((a >> 1) & a) return false;
    if ((b >> 1) & b) return false;
    if ((b << 1) & b) return false;
    if (a & b) return false;
    if ((a << 1) & b) return false;
    if ((a >> 1) & b) return false;
    return true;
}
int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            int cnt = __builtin_popcount(j);
            if (i == 1) {
                if (!check(j,0)) continue;
                f[i][j][cnt] = 1;
                continue;
            }
            for (int l = 0; l < (1 << n); l++) {
                if (!check(j,l)) continue;
                for (int m = cnt; m <= k; m++) {
                    f[i][j][m] += f[i-1][l][m-cnt];
                }
            }
        }
    }
    for (int i = 0; i < (1 << n); i++) if (check(i,0)) ans += f[n][i][k];
    cout << ans << '\n';
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < (1 << n); j++) {
    //         for (int l = 0; l <= k; l++) {
    //             cout << f[i][j][l] << ' ';
    //         }
    //         cout << "   ";
    //     }
    //     cout << '\n';
    // }
    return 0;
}