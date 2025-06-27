#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 33;
const int maxm = 103;
const ll mod = 998244353;
int n,m,K;
ll v[maxm];
ll f[maxm][maxn][maxn][maxn];
ll C[maxn][maxn],vp[maxm][maxn];
inline void init() {
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1; 
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    for (int i = 0; i <= m; i++) {
        vp[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            vp[i][j] = vp[i][j-1] * v[i] % mod;
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> K;
    for (int i = 0; i <= m; i++) cin >> v[i];
    init();
    f[0][0][0][0] = 1;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= K; k++) {
                for (int p = 0; p <= n; p++) {
                    for (int l = 0; j+l <= n; l++) {
                        if ((p+l)%2+k > K || (p+l)/2 > n) continue;
                        f[i+1][j+l][k+(p+l)%2][(p+l)/2] = (f[i+1][j+l][k+(p+l)%2][(p+l)/2]+f[i][j][k][p]*vp[i][l]%mod*C[n-j][l]%mod)%mod;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j <= K; j++) {
        for (int k = 0; k <= n; k++) {
            if (j + __builtin_popcount(k) <= K) ans = (ans + f[m+1][n][j][k]) % mod;
        }
    }
    cout << ans << '\n';
    return 0;
}