#include <bits/stdc++.h>
using namespace std;
int d,g,maxx = 10;
struct rubbish{
    int t,f,h;
    bool operator < (const rubbish &y) const{
        return t < y.t;
    }
}r[105];
int dp[105][156][3034];
int main () {
    cin >> d >> g;
    for (int i = 1; i <= g ;i++) cin >> r[i].t >> r[i].f >> r[i].h;
    sort(r+1,r+g+1);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][10] = 0;
    for (int i = 1; i <= g; i++) {
        int dt = r[i].t - r[i-1].t;
        for (int j = r[i].h; j <= d + 25; j++) {
            for (int k = 0; k <= 3025 - dt; k++) {
                dp[i][j][k] = dp[i-1][j-r[i].h][k+dt]+dt;
                if (dp[i][j][k] < 0x3f3f3f3f) maxx = max(maxx,dp[i][j][k]+k);
            }
        }
        for (int j = 0; j <= d; j++) {
            for (int k = r[i].f; k <= 3025; k++) {
                if (k+dt-r[i].f <= 3025 && k+dt-r[i].f >= 0)dp[i][j][k] = min(dp[i-1][j][k+dt-r[i].f]+dt,dp[i][j][k]);
                if (dp[i][j][k] < 0x3f3f3f3f) maxx = max(maxx,dp[i][j][k]+k);
            }
        }
        int ans = 0x3f3f3f3f,minn = 0x3f3f3f3f;
        for (int j = 0; j <= d + 25; j++) {
            for (int k = 0; k <= 3025; k++) {
                if (j >= d) ans = min(ans,dp[i][j][k]);
                minn = min(minn,dp[i][j][k]);
            }
        }
        if (ans != 0x3f3f3f3f) {
            cout << ans << '\n';
            return 0;
        }
    }
    cout << maxx << '\n';
    return 0;
}