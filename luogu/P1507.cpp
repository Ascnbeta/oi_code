#include <bits/stdc++.h>
using namespace std;
int H,T,n;
int h[53],t[53],k[53];
int dp[403][403];
int ans;
int main () {
    cin >> H >> T >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> t[i] >> k[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = H; j >= 0; j--) {
            for (int l = T; l >= 0; l--) {
                if (j >= h[i] && l >= t[i]) {
                    dp[j][l] = max(dp[j][l],dp[j-h[i]][l-t[i]]+k[i]);
                }
            }
        }
    }
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= T; j++) {
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}