#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e3+20;
int n;
int minp[maxn],p[maxn],tot;
inline void eular(int x) {
    for (int i = 2; i <= x; i++) {
        if (!minp[i]) minp[i] = ++tot,p[tot] = i;
        for (int j = 1; i*p[j] <= x && j <= minp[i]; j++) {
            minp[i*p[j]] = j;
        }
    }
}
int f[maxn],ans;
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    scanf("%lld",&n);
    if (n == 1) {
        puts("1");
        return 0;
    }
    eular(n);
    f[0] = 1;
    for (int i = 1; i <= tot; i++) {
        for (int j = n; j >= p[i]; j--) {
            for (int k = p[i]; k <= j; k *= p[i]) f[j] += f[j-k];
        }
    }
    for (int i = 0; i <= n; i++) ans += f[i];
    printf("%lld",ans);
    return 0;
}