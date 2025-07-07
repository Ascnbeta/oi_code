#include <bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
    int u,v,w;
}e[2003];
int f[1<<13][13],g[1<<13],cst[1<<13][1<<13],road[1<<13][13];
inline bool check(int from,int to) {
    return ((to&from)==from)&&((to&g[from])==to);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        e[i] = {u,v,w};
        e[i+m] = {v,u,w};
    }
    m <<= 1;
    memset(f,0x3f,sizeof(f));
    memset(road,0x3f,sizeof(road));
    for (int i = 1; i <= n; i++) f[1<<(i-1)][1] = 0;
    for (int i = 1; i < (1<<n); i++) {
        g[i] = i;
        for (int j = 1; j <= m; j++) {
            int u = e[j].u,v = e[j].v,w = e[j].w;
            if ((i>>(u-1))&1) {
                road[i][u] = 0;
                g[i] |= 1<<(v-1);
                road[i][v] = min(road[i][v],w);
            }
        }
    }
    for (int i = 1; i < (1<<n); i++) {
        int k = i;
        while (k) {
            if (check(k,i)) {
                int sum = 0;
                for (int j = 1; j <= n; j++) {
                    if (((i^k)>>(j-1))&1) sum += road[k][j];
                }
                cst[k][i] = sum;
            }
            k = (k-1)&i;
        }
    }
    for (int i = 1; i < (1<<n); i++) {
        for (int j = 1; j <= n; j++) {
            if (f[i][j] == 0) continue;
            int k = i;
            while (k) {
                if (check(k,i)) f[i][j] = min(f[i][j],f[k][j-1]+(j-1)*cst[k][i]);
                k = (k-1)&i;
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) ans = min(ans,f[(1<<n)-1][i]);
    cout << ans << '\n';
    return 0;
}