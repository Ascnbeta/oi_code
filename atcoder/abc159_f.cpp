#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
const int maxn = 3e3+10;
int n,s,a[maxn];
ll f[maxn][maxn],ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        f[i-1][0]++;
        for (int j = 0; j <= s; j++) {
            if (j >= a[i])  f[i][j] = (f[i-1][j]+f[i-1][j-a[i]])%mod;
            else f[i][j] = f[i-1][j];
        }
        ans = (ans+f[i][s])%mod;
    }
    cout << ans << '\n';
    return 0;
}