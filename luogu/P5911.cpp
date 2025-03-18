#include <bits/stdc++.h>
using namespace std;
int W,n;
int t[20],w[20];
bool f[1<<18];
int s[1<<18],dp[1<<18];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> W >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> w[i];
    }
    for (int i = 0; i < (1<<n); i++) {
        int tt = i,tmp = 0,cnt = 1,tme = 0;
        while (tt) {
            if (tt&1) tmp += w[cnt],tme = max(tme,t[cnt]);
            ++cnt;
            tt >>= 1;
        }   
        if (tmp > W) f[i] = false;
        else f[i] = true;
        s[i] = tme;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < (1<<n); i++) {
        int tmp = i;
        while(tmp) {
            tmp -= 1;
            tmp = tmp&i;
            if (f[i-tmp]) {
                dp[i] = min(dp[i],dp[tmp]+s[i-tmp]);
            }
        }
    }
    // for (int i = 0; i < (1<<n); i++) {
    //     cout << i << ' ' << dp[i] << '\n';
    // }
    cout << dp[(1<<n)-1] << '\n';
    return 0;
}