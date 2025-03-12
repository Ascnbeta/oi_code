#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+30;
const int maxm = 2e5+30;
int n,m,x;
vector<int> e[maxn<<1],w[maxn<<1];
int dis[maxn<<1];
bool vis[maxn<<1];
struct node{
    int p,w;
    bool operator < (const node &y) const {
        return w > y.w;
    }
};
priority_queue<node> q;
inline void dij(int s) {
    for (int i = 1; i <= 2*n; i++) dis[i] = 1e18;
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    q.push({s,0});
    while (q.size()) {
        node t = q.top();
        q.pop();
        int u = t.p;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i],W = w[u][i];
            if (dis[v]>dis[u]+W) {
                dis[v]=dis[u]+W;
                q.push({v,dis[v]});
            }
        }
    }
    cout << min(dis[n],dis[n+n]) << '\n';
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        w[u].push_back(1);
        e[v+n].push_back(u+n);
        w[v+n].push_back(1);
    }
    for (int i = 1; i <= n; i++) {
        e[i].push_back(i+n);
        w[i].push_back(x);
        e[i+n].push_back(i);
        w[i+n].push_back(x);
    }
    dij(1);
    return 0;
}