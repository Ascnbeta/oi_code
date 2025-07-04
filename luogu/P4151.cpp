#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e4+5;
const int maxm = 1e5+5;
int n,m;
ll p[66];
inline void insert(ll x) {
    for (int i = 62; i >= 0; i--) {
        if ((x>>(i)&1ll)^1ll) continue;
        if (!p[i]) return p[i] = x,void();
        x ^= p[i];
    }
}
inline ll querymax(ll ret) {
    for (int i = 62; i >= 0; i--) {
        ret = max(ret,ret^p[i]);
    }
    return ret;
}
struct edge{
    int v; ll w;
};
vector<edge> e[maxn];
ll dis[maxn];bool vis[maxn];
void dfs(int u,ll sum) {
    dis[u] = sum,vis[u] = true;
    for (auto i : e[u]) {
        int v = i.v;ll w = i.w;
        if (!vis[v]) dfs(v,sum^w);
        else insert(sum^w^dis[v]);
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v; ll w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,0);
    cout << querymax(dis[n]) << '\n';
    return 0;
}