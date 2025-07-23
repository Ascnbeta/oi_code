#include <bits/stdc++.h>
using namespace std;
const int maxn = 1004;
int T;
int n;
int t[maxn],b[maxn];
int f[maxn][1<<8][30];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> t[i] >> b[i];
        memset(f,0x3f,sizeof(f));
        f[1][0][7] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1<<8); j++) {
                for (int k = -8; k <= 7; k++) {
                    if (f[i][j][k+8] == 0x3f3f3f3f) continue;
                    if ((j&1)&&k!=-8) f[i+1][j>>1][k+7] = min(f[i+1][j>>1][k+7],f[i][j][k+8]);
                    else {
                        int tmp = 0x3f3f3f3f;
                        for (int h = 0; h <= 7; h++) {
                            if (!((j>>h)&1)) {
                                if (i+h > tmp) break;
                                tmp = min(tmp,i+h+b[i+h]);
                                f[i][j|(1<<h)][h+8] = min(f[i][j|(1<<h)][h+8],f[i][j][k+8]+(i+k?(t[i+k]^t[i+h]):0));
                            }
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < (1<<8); i++) {
        //     for (int j = -8; j <= 7; j++) {
        //         cout << f[n][i][j+8] << ' ';
        //     }
        //     cout << '\n';
        // }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i <= 8; i++) ans = min(ans,f[n+1][0][i]);
        cout << ans << '\n';
    }
    return 0;
}