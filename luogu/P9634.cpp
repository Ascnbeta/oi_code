#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e3+30;
int n,T;
int hp[maxn],siz[maxn];
vector<int> e[maxn];
int f[maxn][maxn][2];
void dfs(int u) {
    siz[u] = 1;
    memset(f[u],0x3f,sizeof(f[u]));
    f[u][0][0] = hp[u],f[u][1][1] = 0;
    for (auto v : e[u]) {
        dfs(v);
        for (int i = siz[u]+siz[v]; i >= 0; i--) {
            if (i) f[u][i][1] += f[v][0][0];
            f[u][i][0] += f[v][0][0] + hp[v]; 
            for (int j = max(0ll,i-siz[u]); j <= min(i,siz[v]); j++) {
                if (j) f[u][i][1] = min(f[u][i][1],f[u][i-j][1]+min(f[v][j][0],f[v][j][1]));
                f[u][i][0] = min(f[u][i][0],f[u][i-j][0]+min(f[v][j][0]+hp[v],f[v][j][1]));
            }
        }
        siz[u] += siz[v];
    }
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            e[x].push_back(i);
        }
        for (int i = 1; i <= n; i++) cin >> hp[i];
        dfs(1);
        for (int i = 0; i <= n; i++) {
            if (i != n) cout << min(f[1][i][1],f[1][i][0]) << ' ';
            else cout << min(f[1][n][1],f[1][n][0]) << '\n';
        }
    }
    return 0;
}