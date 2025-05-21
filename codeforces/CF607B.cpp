#include <bits/stdc++.h>
using namespace std;
const int maxn = 502;
int n;
int c[maxn];
int f[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    memset(f,0x3f,sizeof(f));
    for (int i = 1; i <= n; i++) cin >> c[i],f[i][i] = 1;
    for (int i = 1; i < n; i++) {
        if (c[i] == c[i+1]) f[i][i+1] = 1;
        else f[i][i+1] = 2;
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i+len-1 <= n; i++) {
            int j = i+len-1;
            if (c[i]==c[j]) f[i][j] = min(f[i][j],f[i+1][j-1]);
            for (int k = i; k < j; k++) f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]);
        }
    }
    cout << f[1][n] << '\n';
    return 0;
}