#include <bits/stdc++.h>
using namespace std;
const int maxn = 403;
int T;
int n,K,mod;
int f[maxn][maxn][maxn];
int sum[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n >> K >> mod;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= K; j++) {
                for (int k = 0; k <= K; k++) f[i][j][k] = 0;
            }
        }
        memset(sum,0,sizeof(sum));
        for (int i = 0; i <= K; i++) {
            for (int j = i; j <= K; j++) f[2][j][i] = 1;
        }
        for (int i = 0; i <= K; i++) {
            for (int j = K; j >= 0; j--) sum[i][j] = (sum[i][j+1]+f[2][i][j])%mod;
        }
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j <= K; j++) {
                for (int k = 0; k <= K; k++) {
                    int tmp = max(k-j,0);
                    f[i][j][k] = sum[k][tmp];
                }
            }
            for (int j = 0; j <= K; j++) {
                sum[j][K+1] = 0;
                for (int k = K; k >= 0; k--) {
                    sum[j][k] = (sum[j][k+1]+f[i][j][k])%mod;
                }
            }
        }
        // for (int i = 0; i <= K; i++) {
        //     for (int j = 0; j <= K; j++) {
        //         cout << f[4][i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        int ans = 0;
        for (int i = 0; i <= K; i++) {
            for (int j = i; j <= K; j++) {
                ans = (ans + f[n][i][j]) % mod;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}