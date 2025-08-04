#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 504;
int n,m,t,q,K;
ll f[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("E:/OI/exe/a.in","r",stdin);
    freopen("E:/OI/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    memset(f,0x3f,sizeof(f));
    for (int i = 1; i <= m; i++) {
        int u,v;ll c;
        cin >> u >> v >> c;
        f[u][v] = min(f[u][v],c);
        f[v][u] = min(f[v][u],c); 
    }
    cin >> K >> t;
    for (int i = 1; i <= K; i++) {
        int u;cin >> u;
        f[u][n+1] = 0,f[n+1][u] = t;
    }
    for (int i = 1; i <= n+1; i++) f[i][i] = 0;
    for (int k = 1; k <= n+1; k++) {
        for (int i = 1; i <= n+1; i++) {
            for (int j = 1; j <= n+1; j++) {
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u,v;ll w;
            cin >> u >> v >> w;
            f[u][v] = min(f[u][v],w),f[v][u] = min(f[v][u],w);
            for (int i = 1; i <= n+1; i++) {
                for (int j = 1; j <= n+1; j++) {
                    f[i][j] = min({f[i][j],f[i][u]+f[v][j]+w,f[i][v]+f[u][j]+w});
                }
            }
        }else if(op == 2) {
            int x;
            cin >> x;
            f[x][n+1] = 0,f[n+1][x] = t;
            for (int i = 1; i <= n+1; i++) {
                for (int j = 1; j <= n+1; j++) {
                    f[i][j] = min({f[i][j],f[i][x]+f[n+1][j]+0,f[i][n+1]+f[x][j]+t});
                }
            }
        }else{
            ll ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (f[i][j] != 0x3f3f3f3f3f3f3f3f) ans += f[i][j];
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}