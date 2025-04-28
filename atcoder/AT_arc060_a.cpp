#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 53;
int n,a,ans;
int x[maxn];
int f[maxn][2513];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> a;
    for (int i = 1; i <= n; i++) cin >> x[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 2500; j >= x[i]; j--) {
            for (int k = i; k >= 1; k--) {
                f[k][j] = f[k][j]+f[k-1][j-x[i]];
            }
        }
    } 
    for (int i = 1; i <= n; i++) {
        if (i*a > 2500) break;
        ans += f[i][i*a];
    }
    cout << ans << '\n';
    return 0;
}