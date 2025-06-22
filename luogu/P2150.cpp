#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;ll mod;
const int maxn = 5e2+30;
const unsigned int hlp = (1<<8)-1;
const int p[10] = {0,2,3,5,7,11,13,17,19};
struct node{
    int num,fac;
    unsigned int s = 0;
    bool operator < (const node &y) const{
        return fac < y.fac;
    }
}a[maxn];
inline void solve(int x) {
    int cur = x - 1;
    a[cur].num = x;
    for (int i = 1; i <= 8; i++) {
        if (x % p[i] == 0) {
            a[cur].s |= 1<<(i-1);
            while (x % p[i] == 0) x /= p[i];
        }
    }
    if (x != 1) a[cur].fac = x;
}
ll dp[(1<<8)+10][(1<<8)+10],f1[(1<<8)+10][(1<<8)+10],f2[(1<<8)+10][(1<<8)+10];
ll ans;
int main() {
#ifdef LOCAL
    freopen("E:/OI/exe/a.in","r",stdin);
    freopen("E:/OI/exe/a.out","w",stdout);
#endif
    cin >> n >> mod;
    for (int i = 2; i <= n; i++) solve(i);
    sort(a+1,a+n);
    int l,r;
    dp[0][0] = 1;
    for (l = 1; l < n; l = r + 1) {
        r = l;
        while (r < n-1 && a[r+1].fac == a[l].fac && a[l].fac != 0) ++r;
        memcpy(f1,dp,sizeof(f1));
        memcpy(f2,dp,sizeof(f2));
        for (int i = l; i <= r; i++) {
            for (unsigned int j = (1<<8)-1; j <= (1<<8)-1; j--) {
                for (unsigned int k = (1<<8)-1; k <= (1<<8)-1; k--) {
                    if (j&k) continue;
                    if ((a[i].s & k) == 0) f1[j|a[i].s][k] = (f1[j][k]+f1[j|a[i].s][k])%mod;
                    if ((a[i].s & j) == 0) f2[j][k|a[i].s] = (f2[j][k]+f2[j][k|a[i].s])%mod;
                }
            }
        }
        for (unsigned int j = 0; j < (1<<8); j++) {
            for (unsigned int k = 0; k < (1<<8); k++) {
                if (j&k) continue;
                dp[j][k] = ((f1[j][k]+f2[j][k])%mod-dp[j][k]+mod)%mod;
            }
        }
    }
    for (unsigned int j = 0; j < (1<<8); j++) {
        for (unsigned int k = 0; k < (1<<8); k++) {
            if (j&k) continue;
            ans = (ans + dp[j][k]) % mod;
        }
    }
    printf("%lld",ans);
    return 0;
}