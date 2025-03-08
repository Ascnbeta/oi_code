#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
    int u,v,w;
    bool operator < (const edge &y) const{
        return w < y.w;
    }
}e[20004];
int tot = 0;
inline void add(int u,int v,int w) {
    e[++tot].u = u;
    e[tot].v = v;
    e[tot].w = w;
}
int father[1004],rk[1004];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline bool merge(int x,int y) {
    int p = find(x),q = find(y);
    if (p == q) return false;
    if (rk[p] <= rk[q]) father[p] = q,rk[q] = max(rk[q],rk[p]+1);
    else father[q] = p,rk[p] = max(rk[p],rk[q]+1);
    return true;
}
inline void kruskal() {
    int cnt = 0,ans = 0;
    for (int i = 1; i <= tot; i++) {
        if (merge(e[i].u,e[i].v)) {
            ++cnt;
            ans += e[i].w;
        }
        if (cnt == n - k) {
            cout << ans << '\n';
            return;
        }
    }
    cout << "No Answer" << '\n';
}
int main () {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    sort(e+1,e+tot+1);
    kruskal();
    return 0;
}