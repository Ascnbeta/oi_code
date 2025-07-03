#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e3+5;
int n,m,w;
ll ap[maxn],bp[maxn],as[maxn],bs[maxn];
ll f[maxn][maxn],l,r,q[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) {
        cin >> ap[i] >> bp[i] >> as[i] >> bs[i];
    }
    memset(f,0xc0,sizeof(f));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= as[i]; j++) f[i][j] = -ap[i]*j;
        for (int j = 0; j <= m; j++) f[i][j] = max(f[i-1][j],f[i][j]);
        if (i > w) {
            l=1,r=0;
            for (ll j = 0; j <= m; j++) {
                while (l<=r&&f[i-w-1][q[r]]+q[r]*ap[i]<=f[i-w-1][j]+j*ap[i]) --r;
                while (l<=r&&j-q[l]>as[i]) ++l;
                q[++r] = j;
                f[i][j] = max(f[i][j],f[i-w-1][q[l]]-(j-q[l])*ap[i]);
            }
            l=1,r=0;
            for (ll j = m; j >= 0; j--) {
                while (l<=r&&f[i-w-1][q[r]]+q[r]*bp[i]<=f[i-w-1][j]+j*bp[i]) --r;
                while (l<=r&&q[l]-j>bs[i]) ++l;
                q[++r] = j;
                f[i][j] = max(f[i][j],f[i-w-1][q[l]]+(q[l]-j)*bp[i]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) ans = max(ans,f[n][i]);
    cout << ans << '\n';
    return 0;
}