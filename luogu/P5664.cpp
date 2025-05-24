#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
const int maxn = 2e3+3;
int n,m;
int a[102][maxn];
ll sum[102],ans;
inline void read(int &x) {
    int f=1;char ch=getchar();
    while (ch <'0' || ch >'9') {
        if (ch == '-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x=x*f;
}
ll f[102][2*maxn+20];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    ans = 1ll;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            read(a[i][j]);
            sum[i] = (sum[i]+a[i][j])%mod;
        }
        ans = (ans*(sum[i]+1))%mod;
    }
    ans=(ans-1+mod)%mod;
    for (int i = 1; i <= m; i++) {
        memset(f,0,sizeof(f));
        f[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= 2*(j-1); k++) {
                f[j][k+2] = (f[j][k+2]+f[j-1][k]*a[j][i]%mod)%mod;
                f[j][k] = (f[j][k]+f[j-1][k]*(sum[j]-a[j][i]+mod)%mod)%mod;
                f[j][k+1] = (f[j][k+1]+f[j-1][k])%mod;
            }
        }
        for (int j = n+1; j <= 2*n; j++) {
            ans = (ans-f[n][j]+mod)%mod;
        }
    }
    printf("%lld",ans);
    return 0;
}