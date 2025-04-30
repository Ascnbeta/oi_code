#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 532;
int n,p[maxn];
int f[maxn][maxn];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i],f[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i+len-1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i+1; k <= j; k++) {
                if (p[i+1] < p[k+1]||k==j) {
                    f[i][j] = (f[i][j]+(f[i+1][k]*f[k][j]%mod))%mod;
                }
            }
        } 
    }
    cout << f[1][n] << '\n';
    return 0;
}