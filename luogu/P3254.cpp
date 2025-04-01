#include <bits/stdc++.h>
using namespace std;
const int maxn = 503;
const int maxm = 1e5+10;
int m,n,s,t,totc;
struct edge{
    int to,nxt,f;
}e[maxm];
int cur[maxn],head[maxn],tot;
vector<int> p[maxn];
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
    dep[s] = 1;
    cur[s] = head[s];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt) {
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
    for (int &i = cur[u]; i != -1 && lft; i = e[i].nxt) {
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
    s = m+n+1,t = s+1;
    for (int i = 1; i <= t; i++) head[i] = -1;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        totc += x;
        add(s,i,x);
    }
    for (int i = m+1; i <= m+n; i++) {
        int x;
        cin >> x;
        add(i,t,x);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = m+1; j <= m+n; j++) {
            add(i,j,1);
        }
    }
    // cerr << totc << '\n';
    if (dinic() < totc) puts("0");
    else{
        puts("1");
        for (int i = 1; i <= m; i++) {
            for (int j = head[i]; j != -1; j = e[j].nxt) {
                int v = e[j].to,f = e[j].f;
                if (m+1 <= v && v <= m+n && f == 0) { 
                    p[i].push_back(v);
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j : p[i]) cout << j-m << ' ';
            cout << '\n';
        }
    }
    return 0;
}