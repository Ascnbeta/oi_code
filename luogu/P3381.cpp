#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 5e3+30;
const int maxm = 1e5+30;
int n,m,s,t;
struct egde{
    int to,nxt,f,cst;
}e[maxm];
int head[maxn],tot = 1;
inline void add(int u,int v,int w,int cst) {
    e[++tot].to = v;
    e[tot].f = w;
    e[tot].cst = cst;
    e[tot].nxt = head[u];
    head[u] = tot;
    e[++tot].to = u;
    e[tot].f = 0;
    e[tot].cst = -cst;
    e[tot].nxt = head[v];
    head[v] = tot;
}
int dis[maxn];
bool vis[maxn];
inline bool spfa(int s,int t) {
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();

        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to,w = e[i].cst,f = e[i].f;
            if (f > 0 && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (!vis[v]) vis[v] = true,q.push(v);
            }
        }
        q.pop();
        vis[u] = false;
    }
    return dis[t] < inf;
}
inline int dfs(int s,int flw,int t) {
    if (s == t || flw <= 0) return flw;
    int rst = flw;
    vis[s] = true;
    for (int i = head[s]; i ; i = e[i].nxt) {
        int v = e[i].to,w = e[i].cst,f = e[i].f;
        if (f > 0 && dis[s] + w == dis[v] && !vis[v]) {
            int tmp = dfs(v,min(rst,f),t);
            rst -= tmp;
            e[i].f -= tmp;
            e[i^1].f += tmp;
            if (rst <= 0) break;
        }
    }
    vis[s] = false;
    return flw - rst;
}
inline pair<int,int> dinic(int s,int t) {
    pair<int,int> ans = {0,0};
    while (spfa(s,t)) {
        int tmp = dfs(s,inf,t);
        ans.first += tmp;
        ans.second += tmp*dis[t];
    }
    return ans;
    // cout << ans << '\n';
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u,v,w,c;
        cin >> u >> v >> w >> c;
        add(u,v,w,c);
    }
    pair<int,int> ans = dinic(s,t);
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}