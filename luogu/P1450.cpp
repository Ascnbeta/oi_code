#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,c[10],d[10],s;ll f[100005];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    for (int i = 1; i <= 4; i++) cin >> c[i];
    cin >> n;
    while (n--) {
        for (int i = 1; i <= 4; i++) cin >> d[i];
        cin >> s;
        memset(f,0,sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= 4; i++) {
            for (int j = c[i]; j <= s; j++) {
                f[j] += f[j-c[i]];
            }
        }
        ll ans = f[s];
        for (int t = 1; t < (1<<4); t++) {
            ll tmp = 0;
            int cnt = __builtin_popcount(t);
            for (int i = 1; i <= 4; i++) {
                if ((t>>(i-1))&1) tmp += 1ll*(d[i]+1)*c[i];
            }
            if (s-tmp < 0) continue;
            if (cnt&1) ans -= f[s-tmp];
            else ans += f[s-tmp];
        }
        cout << ans << '\n';
    }
    return 0;
}