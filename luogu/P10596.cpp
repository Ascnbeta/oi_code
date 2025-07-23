#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e6+5;
int n,k;
int ans,g[maxn];
int jc[maxn],jc_inv[maxn],p1[maxn];
inline int binpow(int base,int b) {
    int ret = 1;
    while(b) {
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
    jc[0] = jc_inv[0] = p1[0] = 1;
    for (int i = 1; i <= n; i++) {
        jc[i] = 1ll*jc[i-1]*i%mod;
        jc_inv[i] = binpow(jc[i],mod-2);
        p1[i] = 1ll*p1[i-1]*2%(mod-1);
    }
    for (int i = k; i <= n; i++) {
        g[i] = 1ll*jc[n]*jc_inv[i]%mod*jc_inv[n-i]%mod*(binpow(2,p1[n-i])-1)%mod;
    }
    for (int i = k; i <= n; i++) {
        int tmp = 1;
        if ((i-k)&1) tmp = -1;
        ans = ((ans+1ll*tmp*jc[i]%mod*jc_inv[k]%mod*jc_inv[i-k]%mod*g[i]%mod)%mod+mod)%mod;
    }
    cout << ans << '\n';
    return 0;
}