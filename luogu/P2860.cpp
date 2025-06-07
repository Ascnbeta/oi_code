#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;
const int maxn = 5e3+30;
const int maxm = 1e4+30;
int n,m;
vector<pair<int,int>> e[maxn];
int dfn[maxn],low[maxn],father[maxn],cnt;
bool b[maxm<<1];
void tarjan(int u,int fa) {
    dfn[u]=low[u]=++cnt;
    bool f = false;
    for (auto v : e[u]) {
        if (!dfn[v.fi]) {
            tarjan(v.fi,u);
            low[u]=min(low[u],low[v.fi]);
            if (low[v.fi] > dfn[u]) {
                b[v.se] = b[v.se^1] = true;
            }
        }else{
            if (v.fi != fa || f) {
                low[u]=min(low[u],dfn[v.fi]);
            }else{
                f=true;
            }
        }
    }
}
int idx[maxn],ans;
bool vis[maxn];
int dcc = 0;
void dfs(int u) {
    idx[u] = dcc;
    vis[u] = true;
    for (auto v : e[u]) {
        if (vis[v.fi] || b[v.se]) continue;
        dfs(v.fi);
    }
}
int dg[maxn];
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    int tmp = 1;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back({v,++tmp});
        e[v].push_back({u,++tmp});
    }
    tarjan(1,0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ++dcc;
            dfs(i);
        }
    }
    for (int u = 1; u <= n; u++) {
        for (auto v : e[u]) {
            if (idx[v.fi] == idx[u]) continue;
            dg[idx[v.fi]]+=1;
            dg[idx[u]]+=1;
        }
    }
    for (int i = 1; i <= dcc; i++) if (dg[i] == 2) ++ans;
    cout << (ans+1)/2 << '\n';
    return 0;
}