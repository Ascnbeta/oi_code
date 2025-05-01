#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e3+30;
const int mod = 998244353;
int n,maxx,ans;
struct num{
    int a,b;
    bool operator < (const num &y) const{
        return a < y.a;
    }
}s[maxn];
int f[maxn];
signed main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i].a,maxx = max(maxx,s[i].a);
    for (int i = 1; i <= n; i++) cin >> s[i].b;
    sort(s+1,s+n+1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = maxx; j >= s[i].b; j--) {
            f[j] = (f[j]+f[j-s[i].b]) % mod;
            if (j <= s[i].a)ans = (ans + f[j-s[i].b]) % mod;
        }
        
    }
    cout << ans << '\n';
    return 0;
}