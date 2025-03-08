#include <bits/stdc++.h>
using namespace std;
int n,m;
int dp[36][36];
int up(int x) {
    x += 1;
    if (x > n) x = 1;
    return x;
}
int down(int x) {
    x -= 1;
    if (x < 1) x = n;
    return x;
}
int main () {
    cin >> n >> m;
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][up(j)] + dp[i-1][down(j)];
        }
    } 
    cout << dp[m][1]<< '\n';
    return 0;
}