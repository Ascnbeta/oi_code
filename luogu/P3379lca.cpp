#include <bits/stdc++.h>
using namespace std;
int n,m,s;
struct edge{
    int to,nxt;
}e[1000005];
int tot,head[500004];
void add(int u,int v) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}
int d[500004],f[500004][24];
void dfs(int x,int p) {
    d[x] = d[p] + 1;
    for (int i = head[x];i;i = e[i].nxt) {
        if (e[i].to == p) continue;
        f[e[i].to][0] = x;
        dfs(e[i].to,x);
    }
}
void pre() {
    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[j][i-1] == 0) continue;
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
}
int lca(int x,int y) {
    if (d[y] < d[x]) swap(x,y);
    int k = log2(d[y])+1;
    for (int i = k; i >= 0; i--) {
        if (d[y] - (1 << i) < d[x]) continue;
        y = f[y][i];
    }
    if (x == y) return x;
    for (int i = k; i >= 0; i--) {
        if (f[y][i] != 0 && f[y][i] != f[x][i]) {
            y = f[y][i];
            x = f[x][i];
        }
    }
    return f[x][0];
}
int main () {
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    dfs(s,0);
    pre();
    while (m--) {
        int x,y;
        cin >> x >> y;
        cout << lca(x,y) << '\n';
    }
    return 0;
}