#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+30;
const int maxm = 4e6+30;
int n,m;
struct edge{
    int to,nxt;
}e[maxm];
int head[maxn],tot = 1;
inline void add(int u,int v ) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}
int dfn[maxn],low[maxn],cnt;
bool f[maxm];
inline void tarjan(int u,int num) {
    dfn[u] = low[u] = ++cnt;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (!dfn[v]) {
            tarjan(v,i);
            low[u] = min(low[u],low[v]);
            if (low[v] > dfn[u]) f[i] = f[i^1] = true;
        }else if(i != (num^1)) {
            low[u] = min(low[u],dfn[v]);
        }
    }
}
bool vis[maxn];
int cntt;
vector<int> ans[maxn];
void dfs(int u,int p) {
    vis[u] = true;
    ans[p].push_back(u);
    for (int i = head[u]; i; i = e[i].nxt) {
        if (f[i]) continue;
        int v = e[i].to;
        if (vis[v]) continue;
        dfs(v,p);
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        add(u,v);
        add(v,u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i,0);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ++cntt;
            dfs(i,cntt);
        }
    }
    cout << cntt << '\n';
    for (int i = 1; i <= cntt; i++) {
        cout << ans[i].size() << ' ';
        for (auto x : ans[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}