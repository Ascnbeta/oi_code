#include <bits/stdc++.h>
#define INF (1ll<<60)
#define int long long
using namespace std;
const int maxn = 2e2+10;
const int maxm = 1e4+30;
int n,m,s,t;
struct edge{
    int to,nxt,f;
}e[maxm];
inline int cv(int x) {
    if (x%2==1) return x+1;
    else return x-1;
}
int cur[maxn],head[maxn],tot;
inline void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].f = w;
    e[tot].nxt = head[u];
    head[u] = tot;
    e[++tot].to = u;
    e[tot].f = 0;
    e[tot].nxt = head[v];
    head[v] = tot;
}
int dep[maxn];
inline bool bfs() {
    memset(dep,0,sizeof(dep));
    queue<int> q;
    q.push(s);
    dep[s] = 1; 
    cur[s] = head[s];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (dep[v] || e[i].f <= 0) continue;
            dep[v] = dep[u] + 1;
            cur[v] = head[v];
            q.push(v);
        }
    }
    return dep[t];
}
inline int dfs(int u,int flow) {
    if (u == t || !flow) return flow;
    int lft = flow;
    for (int &i = cur[u]; i; i = e[i].nxt) {
        int v = e[i].to,f = e[i].f;
        if (dep[v] == dep[u] + 1 && f > 0) {
            int tmp = dfs(v,min(lft,e[i].f));
            if (tmp <= 0) dep[v] = 0;
            lft -= tmp;
            e[i].f -= tmp;
            e[cv(i)].f += tmp;
            if (lft <= 0) break;
        }
    }
    return flow-lft;
}
inline int dinic() {
    int ans = 0;
    while (bfs()) {
        ans += dfs(s,INF);
        //cout << ans << '\n';
    }
    return ans;
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
    }
    cout << dinic() << '\n';
    return 0;
}