#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+3;
int n;
int f[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    memset(f,0x3f,sizeof(f));
    f[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        int minn = 0x3f3f3f3f;
        for (int j = 1; j <= i; j++) minn = min(minn,f[i][j]);
        f[i][i] = min(f[i][i],minn+1);
        if (i%2 == 0) f[i][i/2] = min(f[i][i/2],f[i/2][i/2]+1);
        else f[i][i/2+1] = min(f[i][i/2+1],f[i/2+1][i/2+1]+2);
        for (int j = 1; j <= i; j++) {
            if (f[i][j] == 0x3f3f3f3f) continue;
            for (int k = 1; i+k*j <= n;  k += 1) {
                f[i+k*j][j] = min(f[i+k*j][j],f[i][j]+k);
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) ans = min(ans,f[n][i]);
    cout << ans << '\n';
    return 0;
}