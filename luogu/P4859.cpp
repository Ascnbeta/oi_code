#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod = 1e9+9;
const int maxn = 2004;
int n,k;
int p[maxn],a[maxn];
int ans,g[maxn],h[maxn][maxn];
int jc[maxn],jc_inv[maxn];
inline int binpow(int base,int b) {
    int ret = 1;
    while (b){
        if (b&1) ret = 1ll*ret*base%mod;
        base = 1ll*base*base%mod;
        b >>= 1;
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k;
    k = (n-k)/2;
    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= n; i++) jc[i] = 1ll*jc[i-1]*i%mod,jc_inv[i]=binpow(jc[i],mod-2);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    sort(p+1,p+n+1);
    h[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i][0] = 1;
        int cnt = lower_bound(p+1,p+n+1,a[i])-p-1;
        for (int j = 1; j <= n; j++) {
            if (j <= i && j <= cnt) h[i][j] = (1ll*h[i-1][j]+1ll*(cnt-j+1)*h[i-1][j-1]%mod)%mod;
            else h[i][j] = h[i-1][j];
        }
    }
    for (int i = 0; i <= n; i++) g[i] = 1ll*h[n][i]*jc[n-i]%mod;
    for (int i = k; i <= n; i++) {
        int tmp;
        if ((i-k)&1) tmp = -1;
        else tmp = 1;
        ans = ((1ll*ans+1ll*tmp*g[i]%mod*jc[i]%mod*jc_inv[k]%mod*jc_inv[i-k]%mod)%mod+mod)%mod;
        
    }
    cout << ans << '\n';
    return 0;
}