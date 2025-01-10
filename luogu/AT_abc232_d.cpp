#include <bits/stdc++.h>
using namespace std;
int h,w,ans;
int mp[103][103];
int dp[103][103];
int main () {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') mp[i][j] = 1;
        }
    }
    for (int i = h; i >= 1; i--) {
        for (int j = w; j >= 1; j--) {
            if (mp[i][j] == 1) {
                dp[i][j] = 0;
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]) + 1;
            }
        }
    }
    cout << dp[1][1] << endl;
    return 0;;
}