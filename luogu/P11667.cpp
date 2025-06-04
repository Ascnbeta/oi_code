#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+20;
int T;
int n,a,b;
char mp[maxn][maxn];
bool f[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        int ans = 0;
        for (int i = 1;i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mp[i][j];f[i][j] = false;
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (mp[i][j] == 'W') continue;
                else if (mp[i][j] == 'B') {
                    f[i][j] = true;
                    if (i-b >= 1 && j-a >= 1 && f[i-b][j-a]) {
                        ++ans;
                        f[i-b][j-a] = false;
                    }else{
                        cout << -1 << '\n';
                        flag = false;
                        break;
                    }
                }else{
                    f[i][j] = true;
                }
            }
            if (!flag) break;
        }
        for (int i = n; i >= 1; i--) {
            for (int j = n; j >= 1; j--) {
                if (f[i][j]) {
                    if (i-b >= 1 && j-a >= 1 && f[i-b][j-a]) {
                        ++ans;
                        f[i-b][j-a] = false;
                        f[i][j] = false;
                    }else{
                        ++ans;
                        f[i][j] = false;
                    }
                }
            }
        }
        if (!flag) continue;
        cout << ans << '\n';
    }
    return 0;
}