#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret % mod;
}
int n,a,b,p,q,ans;

int f[160][150][150];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> a >> b >> p >> q;
    const int ni = binpow(p*q,mod-2);
    // cout << ni << '\n';
    f[0][a][b] = 1;
    for (int cnt = 1; cnt <= n; cnt++) {
        for (int i = a; i < n+p; i++) {
            for (int j = b; j < n+q; j++) {
                for (int k = 1; k <= min(i,p); k++) {
                    for (int l = 1; l <= min(j,q); l++) {
                        if (i-k < n && j-l < n) {
                            f[cnt][i][j] = (f[cnt][i][j]+f[cnt-1][i-k][j-l]*ni%mod)%mod;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n; j < n+p; j++) {
            for (int k = 1; k < n+q; k++) ans = (ans+f[i][j][k])%mod;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j < n+p; j++) {
    //         for (int k = 1; k < n+q; k++) {
    //             cout << i << ' ' << j << ' ' << k << ": " << f[i][j][k] << '\n';
    //         }
    //     }
    // }
    cout << (ans+mod)%mod << '\n';
    return 0;

}