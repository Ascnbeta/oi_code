#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+30;
const int mod = 1e9+7;
int n;
struct zone{
    int l,r;
    bool operator < (const zone &y) const{
        return r < y.r;
    }
}a[maxn];
inline void read(int &v) {
    int x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x<<3)+(x<<1)+(ch^48);
        ch = getchar();
    }
    v = x*f;
    return;
}
inline void write(ll x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
ll f[maxn],sum[maxn];
int idx[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i].l),read(a[i].r);
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) idx[i] = a[i].r;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        ll p = lower_bound(idx+1,idx+n+1,a[i].l)-idx;
        f[i] = (sum[p-1]+p+mod)%mod;
        f[i] = (f[i]+sum[i-1]-sum[p-1]+mod)%mod;
        sum[i] = (sum[i-1]+f[i])%mod;
    }
    write(sum[n]);
    return 0;
}