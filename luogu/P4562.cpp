#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret % mod;
}
int l,r,n,k;
bool f[10000003];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> l >> r;
    int n = r - l + 1;
    for (int i = l; i <= r; i++) {
        if (!f[i]) {
            ++k;
            for (int j = i; j <= r; j += i) f[j] = true;
        }
    }
    int ans = k*binpow(k+1,mod-2)%mod;
    for (int i = 1; i <= n+1; i++) {
        ans = ans * i % mod;
    }
    cout << ans << '\n';
    return 0;
}