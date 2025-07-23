#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int mod = 1e9+7;
int n,s,t;
int f[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> s >> t;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i!=s && i!=t) {
                f[i][j] = (1ll*(j-(i>s)-(i>t))*f[i-1][j-1]%mod+1ll*j*f[i-1][j+1]%mod)%mod;
            }else{
                f[i][j] = (f[i-1][j-1]+f[i-1][j])%mod;
            }
        }
    }
    cout << f[n][1] << '\n';
    return 0;
}