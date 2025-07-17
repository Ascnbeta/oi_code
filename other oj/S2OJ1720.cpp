#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 102;
const int maxm = 203;
const ll mod = 998244353;
int n,m;
int a[maxn];
ll C[maxn*maxn][maxn<<1],f[maxn][maxm],g[maxn][maxm];
inline ll binpow(ll base,int b) {
    ll ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i < n; i++) cin >> a[i];
    sort(a+1,a+n,greater<int>());
    C[0][0] = 1;
    for (int i = 1; i <= n*(n-1)/2; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    f[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= min(m,i*(i-1)/2); j++) {
            for (int p = 1; p <= i-1; p++) {
                for (int q = 0; q <= j; q++) {
                    g[i][j] = (g[i][j]+f[p][q]*C[(i-p)*(i-p-1)/2][j-q]%mod*C[i-1][p-1]%mod)%mod;
                }
            }
            f[i][j] = (C[i*(i-1)/2][j]-g[i][j]+mod)%mod;
        }
    }
    int l = 4,r = 4;
    while (l > 1 && a[l-1] == a[4]) --l;
    while (r < n-1 && a[r+1] == a[4]) ++r;
    int cnt = r-l+1,mst = l-1;ll ans = 0;
    for (int i = 5; i <= n; i++) {
        for (int j = 0; j <= min(m,i*(i-1)/2); j++) {
            for (int k = 4-mst; k <= cnt && 1+mst+k <= i; k++) {
                ans = (ans+f[i][j]*C[cnt][k]%mod*C[n-1-mst-cnt][i-1-mst-k]%mod*C[(n-i)*(n-i-1)/2][m-j]%mod)%mod;
            }
        }
    }
    cout << ans * binpow(C[n*(n-1)/2][m],mod-2) % mod << '\n';
    return 0;
}