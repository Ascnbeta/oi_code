#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;
const int maxe = 302;
int n,m,v,e;
int c[maxn],d[maxn];
double k[maxn],f[maxn][maxn][2],ans = 1e9;
int dis[maxe][maxe];
inline double calc(int i,int j,int x,int y) {
    if (x == 0 && y == 0) return dis[c[i]][c[j]];
    if (x == 0 && y == 1) return k[j]*dis[c[i]][d[j]]+(1-k[j])*dis[c[i]][c[j]];
    if (x == 1 && y == 0) return k[i]*dis[d[i]][c[j]]+(1-k[i])*dis[c[i]][c[j]];
    if (x == 1 && y == 1) return k[i]*k[j]*dis[d[i]][d[j]]+k[i]*(1-k[j])*dis[d[i]][c[j]]+(1-k[i])*k[j]*dis[c[i]][d[j]]+(1-k[i])*(1-k[j])*dis[c[i]][c[j]];
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> v >> e;
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1; i <= n; i++) cin >> c[i];
    // cout << c[1] << '\n';
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) cin >> k[i];
    for (int i = 1; i <= e; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v],w);
        dis[v][u] = min(dis[v][u],w);
    }
    for (int i = 1; i <= v; i++) dis[i][i] = 0;
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v ; j++) {
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    // cout << dis[1][2] << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) f[i][j][0] = f[i][j][1] = 1e9;
    }
    f[1][0][0] = 0;
    f[1][1][1] = 0;
    for (int i = 2; i <= n; i++) {
        f[i][0][0] = f[i-1][0][0] + calc(i-1,i,0,0);
        for (int j = 1; j <= m; j++) {
            f[i][j][0] = min(f[i-1][j][0]+calc(i-1,i,0,0),f[i-1][j][1]+calc(i-1,i,1,0));
            f[i][j][1] = min(f[i-1][j-1][0]+calc(i-1,i,0,1),f[i-1][j-1][1]+calc(i-1,i,1,1));
            //cout << i << ' ' << j << ' ' << f[i][j][0] << ' ' << f[i][j][1] << '\n';
        }
        
    }
    // cout << calc(1,2,0,1) << '\n';
    for (int i = 0; i <= m; i++) ans = min(ans,min(f[n][i][0],f[n][i][1]));
    printf("%.2f",ans);
    return 0;
}