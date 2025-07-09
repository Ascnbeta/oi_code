#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1503;
const int maxm = 3e5+4;
int n,m;
int s1,e1,s2,e2;
struct edge{
    int v,w;bool f;
};
vector<edge> e[maxn]; 
ll dis[6][maxn];bool vis[6][maxn];
struct node{
    int p;ll w;
    bool operator < (const node &y) const{
        return w > y.w;
    }
};

inline void dijkstra(int id,int s) {
    memset(dis[id],0x3f,sizeof(dis[id]));
    priority_queue<node> q;
    q.push({s,0});
    dis[id][s] = 0;
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[id][t.p]) continue;
        vis[id][t.p] = true;
        int u = t.p;
        for (auto i : e[u]) {
            int v = i.v,w = i.w;
            if (dis[id][v] > dis[id][u] + w) {
                dis[id][v] = dis[id][u] + w;
                q.push({v,dis[id][v]});
            }
        }
    }
}
bool tag[maxm];int ind[maxn];
ll f[maxn],g[maxn],ans;
queue<int> q;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    cin >> s1 >> e1 >> s2 >> e2;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back({v,w,0}),e[v].push_back({u,w,0});
    }
    dijkstra(1,s1),dijkstra(2,e1),dijkstra(3,s2),dijkstra(4,e2);
    for (int u = 1; u <= n; u++) {
        for (auto &i : e[u]) {
            int v = i.v,w = i.w;
            if (dis[1][u]+dis[2][v]+w==dis[1][e1]) i.f = true,ind[v]++;
        }
    }
    q.push(s1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans = max({ans,f[u],g[u]});
        for (auto i : e[u]) {
            if (i.f) {
                int v=i.v,w=i.w;
                ind[v]--;
                if (dis[3][u]+dis[4][v]+w==dis[3][e2]) f[v] = max(f[v],f[u]+w);
                if (dis[4][u]+dis[3][v]+w==dis[3][e2]) g[v] = max(g[v],g[u]+w);
                if (!ind[v]) q.push(v);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}