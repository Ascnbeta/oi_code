#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+30;
const int maxm = 2e5+30;
int n,m;
struct edge{
    int u,to,nxt,w;
}e[maxm<<1];
bool tr[maxm<<1];
int head[maxn],tot=1;
inline void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].u = u;
    e[tot].w = w;
    e[tot].nxt = head[u];
    head[u] = tot;
}
int dis[maxn];bool vis[maxn];
struct node{
    int p,w,num;
    bool operator < (const node &y) const {
        return w > y.w;
    }
};
priority_queue<node> q;
inline void dijkstra() {
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1] = 0;
    q.push({1,0,0});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[t.p]) continue;
        vis[t.p] = tr[t.num] = true;
        for (int i = head[t.p]; i; i = e[i].nxt) {
            int v = e[i].to,w = e[i].w;
            if (dis[v] > dis[t.p] + w) {
                dis[v] = dis[t.p] + w;
                q.push({v,dis[v],i});
            }
        }
    }
}
vector<pair<int,int>> e1[maxn];
int dfn[maxn],idx[maxn],dep[maxn],top[maxn],son[maxn],siz[maxn],f[maxn],cnt;
inline void dfs1(int u,int fa) {
    dep[u] = dep[fa] + 1;
    siz[u] = 1;
    for (auto i : e1[u]) {
        int v = i.first;
        if (v == fa) continue;
        f[v] = u;
        dfs1(v,u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
inline void dfs2(int u,int fa,int p ) {
    top[u] = p;
    dfn[u] = ++cnt;
    idx[cnt] = u;
    if (son[u]) dfs2(son[u],u,p);
    for (auto i : e1[u]) {
        int v = i.first;
        if (v == fa || v == son[u]) continue;
        dfs2(v,u,v);
    }
}
#define ls p<<1
#define rs p<<1|1
int val[maxn<<2];
inline void build(int p,int l,int r) {
    val[p] = 0x3f3f3f3f;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (s <= l && r <= e) {
        val[p] = min(val[p],v);
        return;
    }
    int mid = (l + r) >> 1;
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
}
// inline int getlca(int u,int v) {
//     while (top[u] != top[v]) {
//         if (dep[top[u]] > dep[top[v]]) {
//             u = f[top[u]];
//         }else{
//             v = f[top[v]];
//         }
//     }
//     return dep[u]>dep[v]?v:u;
// }
inline void modify_edge(int x,int y,int v) {
    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]]) {
            modify(1,dfn[top[x]],dfn[x],v,1,n);
            x = f[top[x]];
        }else{
            modify(1,dfn[top[y]],dfn[y],v,1,n);
            y = f[top[y]];
        }
    }
    if (dep[x] > dep[y]) swap(x,y);
    if (x != y) modify(1,dfn[x]+1,dfn[y],v,1,n);
}
int ans[maxn];
inline void query(int p,int l,int r) {
    if (l == r) {
        if (val[p] == 0x3f3f3f3f) ans[idx[l]] = -1;
        else ans[idx[l]]=val[p]-dis[idx[l]];
        return;
    }
    int mid = (l + r) >> 1;
    val[ls] = min(val[ls],val[p]);
    val[rs] = min(val[rs],val[p]);
    query(ls,l,mid);
    query(rs,mid+1,r); 
}
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a,b,t;
        cin >> a >> b >> t;
        add(a,b,t);
        add(b,a,t);
    }
    dijkstra();
    for (int i = 1; i <= tot; i++) {
        if (tr[i]) {
            e1[e[i].u].push_back({e[i].to,e[i].w});
            e1[e[i].to].push_back({e[i].u,e[i].w});
        }
    }
    dfs1(1,0);
    dfs2(1,0,1);
    // cout << getlca(3,4) << '\n';
    build(1,1,n);
    for (int i = 1; i <= tot; i++) {
        if (!tr[i]&&!tr[i^1]) {
            int tmp = dis[e[i].u]+dis[e[i].to]+e[i].w;
            modify_edge(e[i].u,e[i].to,tmp);
        }
    }
    query(1,1,n);
    for (int i = 2; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}