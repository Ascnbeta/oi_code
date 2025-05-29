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
    for (int i = 1; i <= n; i++) cin >> a[i],f[i][0] = 1;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j >= a[i])  f[i][j] = (f[i-1][j]+f[i-1][j-a[i]])%mod;
            else f[i][j] = f[i-1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (s >= a[j]) ans = (((ans+f[j][s])%mod-f[i-1][s]+mod)%mod-f[i-1][s-a[j]]+mod)%mod;
        }
    }
    cout << ans << '\n';
    return 0;
}