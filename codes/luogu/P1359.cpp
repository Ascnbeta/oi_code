#include <bits/stdc++.h>
using namespace std;
int n;
int s[204][204];
int dp[204];
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = min (dp[i],dp[j]+s[j][i]);
        }
    }
    cout << dp[n];
    return 0;
}