#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;ll mod,lim = 1e6;
ll jc[1000005],jc_inv[1000005];
inline ll binpow(ll base,int b) {
    ll ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}
inline ll C(ll n,ll m) {
    if (n < 0 || m > n) return 0;
    if (n <= lim) return jc[n]*jc_inv[m]%mod*jc_inv[n-m]%mod;
    return C(n/mod,m/mod)*C(n%mod,m%mod)%mod;
}
const int maxn = 1e6+5;
ll siz[maxn],ans[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> mod;
    lim = min(1ll*n,mod-1);
    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= lim; i++) jc[i] = jc[i-1]*i%mod,jc_inv[i]=binpow(jc[i],mod-2);
    for (int i = n; i >= 1; i--) {
        siz[i] = 1;ans[i] = 1;
        if ((i<<1)>n) continue;
        if (!ans[i<<1]) ans[i<<1] = 1;
        if (!ans[i<<1|1]) ans[i<<1|1] = 1;
        siz[i] += siz[i<<1]+siz[i<<1|1];
        ans[i] = C(siz[i]-1,siz[i<<1])*ans[i<<1]%mod*ans[i<<1|1]%mod;
    }
    cout << ans[1] << '\n';
    return 0;
}