#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn = 1e4+30;
const ll maxa = 604;
int n;
ll a[maxn],cf[maxn];
template <typename T>
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
ll f[2][maxa*maxn];
int maxv = 0;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i < n; i++) cf[i] = a[i+1]-a[i];
    sort(cf+1,cf+n);
    maxv = a[n];
    int st = 0;     
    for (int i = 1; i < n; i++) if (cf[i] == 0) st = i;
    for (int i = 1; i < n; i++) a[i] = a[i-1]+cf[i];
    memset(f,0x3f,sizeof(f));
    f[st&1][0] = 0;
    for (int i = st+1; i < n; i++) {
        for (int j = 0; j <= maxv*n; j++) f[i&1][j] = 0x3f3f3f3f3f3f3f3f;
        for (int j = 0; j <= maxv*n; j++) {
            if (f[(i&1)^1][j] == 0x3f3f3f3f3f3f3f3f) continue;
            f[i&1][j+a[i]] = min(f[i&1][j+a[i]],f[(i&1)^1][j]+a[i]*a[i]);
            f[i&1][j+cf[i]*i] = min(f[i&1][j+cf[i]*i],f[(i&1)^1][j]+2*j*cf[i]+i*cf[i]*cf[i]);
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i <= maxv*n; i++) {
        if (f[(n&1)^1][i] != 0x3f3f3f3f3f3f3f3f) {
            ans = min(ans,1ll*n*f[(n&1)^1][i]-1ll*i*i);
        }
    }
    printf("%lld",ans);
    return 0;
}