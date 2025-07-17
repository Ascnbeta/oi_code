#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int n,m,k;
int f[maxn][maxn*maxn];
int suma,b[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x < k) {
            puts("Impossible");
            return 0;
        }
        suma += x;
    }
    for (int i = 1; i <= m; i++) cin >> b[i];
    memset(f,0xcf,sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < b[i]; j++) {
            f[i][j] = f[i-1][j];
        }
        for (int j = b[i]; j <= 90000; j++) {
            f[i][j] = max(f[i-1][j],f[i-1][j-b[i]]+min(n,b[i]));
        }
    }
    for (int i = suma; i <= 90000; i++) {
        if (f[m][i] >= n*k) {
            cout << i-suma << '\n';
            return 0;
        }
    }
    puts("Impossible");
    return 0;
}