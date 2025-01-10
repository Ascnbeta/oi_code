#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,tmp1,tmp2,tmp3,tmp4;
string c;
signed main () {
    cin >> T;
    while (T--) {
        cin >> n >> c;
        tmp1 = tmp2 = tmp3 = tmp4 = 0;
        ans = 0;
        for (int i = 1; i <= n - 1; i++) {
            if (c[i] == '<') {
                ans += i - tmp1;
                tmp2 = i;
                if (c[i] != '<') tmp1 = i;
            }else if (c[i] == '=') {
                if (tmp2 > tmp4) {
                    ans += tmp2 - tmp1;
                }else{
                    ans += tmp4 - tmp3 + 1;
                }
                if (c[i+1])
            }else{
                ans += i - tmp3;
                tmp4 = i;
                if (c[i-1] != '>') tmp3 = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}