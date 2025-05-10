#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
int n,m,q;
int sum[maxn<<1],b[maxn<<1],c[maxn<<1];
struct edge{
    int u,v,w;
    bool operator < (const edge &y) const{
        return w < y.w;
    }
}e[maxn];
int father[maxn<<1],tot;
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
int f[maxn<<1][25],fc[maxn<<1][25];
inline void kruskal() {
    for (int i = 1; i <= 2*n; i++) father[i] = i;
    sort(e+1,e+m+1);
    int cnt = 0;tot = n;
    for (int i = 1; i <= m; i++) {
        int p = find(e[i].u),q = find(e[i].v);
        if (p == q) continue;
        ++cnt;
        ++tot;
        fc[p][0] = e[i].w-sum[p];
        fc[q][0] = e[i].w-sum[q];
        f[p][0] = f[q][0] = tot;
        sum[tot] = sum[p] + sum[q];
        father[p] = father[q] = tot;
        if (cnt == n-1) break;
    } 
}

inline void pre() {
    for (int i = 1; i <= __lg(tot)+1; i++) {
        for (int j = 1; j <= tot; j++) {
            f[j][i] = f[f[j][i-1]][i-1],fc[j][i] = max(fc[j][i-1],fc[f[j][i-1]][i-1]);
        }
    }
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> sum[i];
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        e[i] = {u,v,w};
    }
    kruskal();
    // for (int i = 1; i <= tot; i++) cout << b[i] << '\n';
    sum[0] = sum[tot];
    pre();
    while (q--) {
        int x,k;
        cin >> x >> k;
        for (int i = __lg(tot)+1; i >= 0; i--) {
            if (fc[x][i] <= k) {
                x = f[x][i];
            }
        }
        cout << sum[x]+k << '\n';
    }
    return 0;
}