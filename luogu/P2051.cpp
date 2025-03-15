#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 9999973;
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}
int n,m,ans;
int f[103][103][103];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    const int ni = binpow(2,mod-2);
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; j + k <= m; k++) {
                f[i][j][k] = (f[i][j][k]+f[i-1][j][k])%mod;
                if (j < m && k > 0) f[i][j][k] = (f[i][j][k]+f[i-1][j+1][k-1]*(j+1)%mod)%mod;
                if (j > 0) f[i][j][k] = (f[i][j][k]+f[i-1][j-1][k]*(m-j+1-k)%mod)%mod;
                if (j < m-1 && k > 1) f[i][j][k] = (f[i][j][k]+f[i-1][j+2][k-2]*(j+2)%mod*(j+1)%mod*ni%mod)%mod;
                if (j > 1) f[i][j][k] = (f[i][j][k]+f[i-1][j-2][k]*(m-j+2-k)%mod*(m-j+1-k)%mod*ni%mod)%mod;
                if (k > 0) f[i][j][k] = (f[i][j][k]+f[i-1][j][k-1]*j%mod*(m-j-k+1)%mod)%mod;
            }
        }
    }
    for (int i = 0;i <= m; i++) {
        for (int j = 0; i+j <= m; j++){
            ans = (ans+f[n][i][j])%mod;
        }
    }
    cout << ans << '\n';
    return 0;
}