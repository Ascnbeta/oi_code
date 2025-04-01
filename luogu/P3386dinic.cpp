#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
const int maxm = 2e5+30;
int n1,n2,m,s,t;
struct edge{
    int to,nxt,f;
}e[maxm];
int cur[maxn],head[maxn],tot;
inline void add(int u,int v,int w) {
    e[tot].to = v;
    e[tot].nxt = head[u];
    e[tot].f = w;
    head[u] = tot++;
    e[tot].to = u;
    e[tot].nxt = head[v];
    e[tot].f = 0;
    head[v] = tot++;
}
int dep[maxn];
inline bool bfs() {
    memset(dep,0,sizeof(dep));
    queue<int> q;
    q.push(s);
    cur[s] = head[s];
    dep[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i =e[i].nxt) {
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
    if (u == t || !flw) return flw;
    int lft = flw;
    for (int &i = cur[u]; i != -1&& lft; i = e[i].nxt) {
        int v = e[i].to,f = e[i].f;
        if (dep[v] == dep[u] + 1 && f > 0) {
            int tmp = dfs(v,min(lft,f));
            if (tmp <= 0) dep[v] = 0;
            lft -= tmp;
            e[i].f -= tmp;
            e[i^1].f += tmp;
            if (lft <= 0) break;
        }
    }
    return flw - lft;
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
    cin >> n1 >> n2 >> m;
    s = n1+n2+1,t = s + 1;
    for (int i = 1; i <= n1+n2+3; i++) head[i] = -1;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        v += n1;
        add(u,v,1);
    }
    for (int i = 1; i <= n1; i++) {
        add(s,i,1);
    }
    for (int i = n1+1; i <= n1+n2; i++) {
        add(i,t,1);
    }
    cout << dinic() << '\n';
    return 0;
}