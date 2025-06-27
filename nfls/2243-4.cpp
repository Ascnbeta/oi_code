#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
int n,a;
int p[maxn],tot;
int minp[maxn<<1];
int nump[maxn][2],num[maxn];
inline void eular_sieve() {
    for (int i = 2; i <= 200000; i++) {
        if (!minp[i]) p[++tot] = i,minp[i] = tot;
        for (int j = 1; j <= minp[i] && 1ll*p[j]*i <= 200000ll; j++) {
            minp[p[j]*i] = j;
        }
    }
}
inline void solve(int x) {
    for (int i = 1; p[i] <= sqrt(200000); i++) {
        int cnt = 0;
        while (x % p[i] == 0) x /= p[i],++cnt;
        if (cnt < nump[i][0]) {
            nump[i][1] = nump[i][0];
            nump[i][0] = cnt;
        }else if(cnt < nump[i][1]) {
            nump[i][1] = cnt;
        }
    }
    if (x != 1) num[minp[x]]++;
}
int ans = 1;
inline int binpow(int base ,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret *= base;
        base *= base;
        b >>= 1;
    }
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    eular_sieve();
    memset(nump,0x3f,sizeof(nump));
    for (int i = 1; i <= n; i++) {
        cin >> a;
        solve(a);
    }
    for (int i = 1; i <= tot; i++) {
        if (p[i] * p[i] > 200000) {
            if (num[i] >= n-1) {
                nump[i][1] = 1;
            }else{
                nump[i][1] = 0;
            }
        }
        ans *= binpow(p[i],nump[i][1]);
    }
    cout << ans << '\n';
    return 0;
}