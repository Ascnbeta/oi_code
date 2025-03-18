#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
const int mod = 1e5+3;
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret % mod;
}
int n,k,cnt;
int a[maxn];
int f[maxn];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        if (a[i]) {
            ++cnt;
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    if (j != i/j) a[j] ^= 1,a[i/j] ^= 1;
                    else a[j] ^= 1;
                }
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        int ni = binpow(i,mod-2);
        f[i] = (((n-i)*f[i+1]%mod+n)%mod*ni)%mod;
    }
    if (cnt <= k) {
        int sum = cnt;
        for (int i = 1; i <= n; i++) {
            sum = sum * i % mod;
        }
        cout << sum << '\n';
    }else{
        int sum = 0;
        for (int i = k+1; i <= cnt; i++) {
            sum = (sum + f[i]) % mod;
        }
        sum = (sum + k) % mod;
        for (int i = 1; i <= n; i++) {
            sum = sum * i % mod;
        }
        cout << sum << '\n';
    }
    return 0;
}