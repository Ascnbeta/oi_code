#include <bits/stdc++.h>
using namespace std;
const int maxn = 250;
const int maxm = 4e4+10;
int n,m,s,t;
struct edge{
    int to,nxt,f;
}e[maxm];
int cur[maxn],head[maxn],tot;
inline void add(int u,int v,int w) {
    e[tot].to = v;
    e[tot].f = w;
    e[tot].nxt = head[u];
    head[u] = tot++;
    e[tot].to = u;
    e[tot].f = 0;
    e[tot].nxt = head[v];
    head[v] = tot++;
}
int dep[maxn];
inline bool bfs() {
    memset(dep,0,sizeof(dep));
    queue<int> q;
    q.push(s);
    cur[s]=head[s];
    dep[s]=1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u];i != -1; i = e[i].nxt) {
            int v = e[i].to,f = e[i].f;
            if (dep[v] || f <= 0) continue;
            dep[v] = dep[u] + 1;
            cur[v] = head[v];
            q.push(v);
        }
    }
    return dep[t];
}
inline int dfs(int u,int flw) {
    if (u == t || flw <= 0) return flw;
    int lft = flw;
    for (int &i = cur[u]; i != -1; i = e[i].nxt) {
        int v = e[i].to,f = e[i].f;
        if (dep[v] == dep[u]+1 && f > 0) {
            int tmp = dfs(v,min(lft,f));
            if (tmp <= 0) dep[v] = 0;
            lft -= tmp;
            e[i].f -= tmp;
            e[i^1].f += tmp;
            if (lft <= 0) break;
        }
    }
    return flw-lft;
}
inline int dinic() {
    int ans = 0;
    while (bfs()) {
        ans += dfs(s,INT_MAX);
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> m >> n;
    s = n+1,t = s+1;
    for (int i = 1; i <= t; i++) head[i] = -1;
    while (1) {
        int x,y;
        cin >> x >> y;
        if (x == -1 && y == -1) break;
        add(x,y,1);
    }
    for (int i = 1; i <= m; i++) add(s,i,1);
    for (int i = m+1; i <= n; i++) add(i,t,1);
    cout << dinic() << '\n';
    for (int i = 1; i <= m; i++) {
        for (int j = head[i]; j != -1; j = e[j].nxt) {
            int v = e[j].to,f = e[j].f;
            if (m+1 <= v && v <= n && f == 0) {
                cout << i << ' ' << v << '\n';
            }
        }
    }
    return 0;
}