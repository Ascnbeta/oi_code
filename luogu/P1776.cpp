#include <bits/stdc++.h>
using namespace std;
int n,W;
int v[103],w[103],m[103];
int dp[40005];
long long ans;
int main () {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> m[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= 0; j--) {
            for (int k = 1; k <= min(m[i],j/w[i]); k++) {
                dp[j] = max(dp[j],dp[j-k*w[i]]+k*v[i]);
            }
        }
    }
    for (int i = 0; i <= W; i++) {
        ans = max((long long)dp[i],ans);
    }
    cout << ans << '\n';
    return 0;
}