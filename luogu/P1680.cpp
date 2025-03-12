#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+30;
const int mod = 1e9+7;
int n,m,ans;
int a[maxn];
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret % mod;
}
inline int C(int x,int y) {
    int ret = 1;
    for (int i = 1; i <= y; i++) {
        ret = ret * i % mod;
    }
    ret = binpow(ret,mod-2);
    for (int i = x; i > x - y; i--) {
        ret = ret * i % mod;
    }
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        n -= a[i];
    }
    if (n == 0) {
        cout << 1 << '\n';
        return 0;
    }else if (n < 0) {
        cout << 0 << '\n';
        return 0;
    }
    cout << C(n-1,m-1) << '\n';
    return 0;
}