#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
int n,m;
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret % mod;
}
inline int fact(int x) {
    if (x == 0) return 1;
    int ret = 1;
    for (int i = x; i >= 1; i--) {
        ret = ret * i % mod;
    }
    return ret;
}
inline int C(int dn,int up) {
    if (up == 0) return 1;
    if (up > dn) return 0;
    int tmp1 = fact(dn);
    int tmp2 = binpow(fact(up)*fact(dn-up)%mod,mod-2);
    return tmp1*tmp2%mod;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    int ans = fact(n);
    int tmp1 = n*(n+1)%mod*C(n+3,m)%mod*fact(m)%mod;
    int tmp2 = 2*m%mod*(n+1)%mod*C(n+2,m-1)%mod*fact(m-1)%mod;
    tmp1 = (tmp1 + tmp2) % mod;
    ans = ans * tmp1 % mod;
    cout << ans << '\n';
    return 0;
}