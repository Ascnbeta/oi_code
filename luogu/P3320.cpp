#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
struct edge {
    int to,nxt,w;
}e[maxn<<1];
int head[maxn],tot;
int n,m,ans;
inline void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
int dfn[maxn],dis[maxn],dep[maxn],cnt,son[maxn],siz[maxn],top[maxn],rnk[maxn],f[maxn];
void dfs1(int u,int fa)  {
    dep[u] = dep[fa] + 1;
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa) continue;
        dis[v] = dis[u] + e[i].w;
        f[v] = u;
        dfs1(v,u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u,int fa,int p) {
    top[u] = p;
    dfn[u] = ++cnt;
    rnk[cnt] = u;
    if (son[u]) dfs2(son[u],u,p);
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa || v == son[u]) continue;
        dfs2(v,u,v);
    }
}
inline int get_lca(int u,int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = f[top[u]];
        }else{
            v = f[top[v]];
        }
    }
    return dep[u]>dep[v]?v:u;
}
set<int> s;
bool c[maxn];
inline int calc(int x,int y) {
    int lca = get_lca(x,y);
    return dis[x]+dis[y]-dis[lca]*2;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w),add(v,u,w);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if (!c[x]) {
            s.insert(dfn[x]);
        }
        auto tmp1 = s.lower_bound(dfn[x]);
        auto tmp2 = s.upper_bound(dfn[x]);
        int lft = rnk[tmp1==s.begin()?(*(--s.end())):(*(--tmp1))];
        int rgt = rnk[tmp2==s.end()?(*(s.begin())):(*(tmp2))];
        if (c[x]) {
            s.erase(dfn[x]);
        }
        int dist = calc(lft,x)+calc(x,rgt)-calc(lft,rgt);
        if (c[x]) c[x] = false,ans -= dist;
        else c[x] = true,ans += dist;
        cout << ans << '\n';
    }
    return 0;
}