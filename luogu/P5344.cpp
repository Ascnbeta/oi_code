#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template <typename T>
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
template <typename T>
inline void write(T x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 5e4+10;
const int maxm = 1e6+5;
int n,m,s;
int father[maxn];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
struct action{
    int u1,v1,u2,v2;ll w;
}q[maxm];int tot;
vector<pair<int,ll>> e[maxn<<6];int cnt;
int f[maxn][20],dep[maxn];
void dfs(int u,int fa) {
    dep[u] = dep[fa] + 1;
    for (auto i : e[u]) {
        int v = i.first;
        if (v == fa) continue;
        f[v][0] = u;
        dfs(v,u);
    }
}
int id1[maxn][20],id2[maxn][20];
void pre() {
    for (int i = 1; i <= __lg(n); i++) {
        for (int j = 1; j <= n; j++) {
            f[j][i] = f[f[j][i-1]][i-1];
            if (id1[j][i-1]||id1[f[j][i-1]][i-1]) {
                id1[j][i] = ++cnt,id2[j][i] = ++cnt;
            }else continue;
            e[id1[j][i]].push_back({id1[j][i-1],0}),e[id1[j][i]].push_back({id1[f[j][i-1]][i-1],0});
            e[id2[j][i-1]].push_back({id2[j][i],0}),e[id2[f[j][i-1]][i-1]].push_back({id2[j][i],0});
        }
    }
}
inline int getlca(int x,int y) {
    if (dep[x] > dep[y]) swap(x,y);
    for (int i = 15; i >= 0; i--) {
        if (dep[f[y][i]]>=dep[x]) y = f[y][i];
    }
    if (x == y) return x;
    for (int i = 15; i >= 0; i--) {
        if (f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
    }
    return f[x][0];
}

inline void add1(int u,int top,int w) {
    if (u == top) return e[u].push_back({cnt,w}),void();
    int i = 0;
    while (i <= __lg(n)&&f[u][i+1]&&dep[f[u][i+1]]>=dep[top]-1) ++i;
    e[id2[u][i]].push_back({cnt,w});
    if (f[u][i] != f[top][0]) {
        int d = dep[f[u][i]]-dep[top]+1;
        for (int j = __lg(n); j >= 0; j--) {
            if ((d>>j)&1) u = f[u][j];
        }
        e[id2[u][i]].push_back({cnt,w});
    }
}
inline void add2(int u,int top) {
    if (u == top) return e[cnt].push_back({u,0}),void();
    int i = 0;
    while (i <= __lg(n)&&f[u][i+1]&&dep[f[u][i+1]]>=dep[top]-1) ++i;
    e[cnt].push_back({id1[u][i],0});
    if (f[u][i] != f[top][0]) {
        int d = dep[f[u][i]]-dep[top]+1;
        for (int j = __lg(n); j >= 0; j--) {
            if ((d>>j)&1) u = f[u][j];
        }
        e[cnt].push_back({id1[u][i],0});
    }
}
struct node{
    int p;ll w;
    bool operator < (const node &y) const {
        return w > y.w;
    }
};
priority_queue<node> q1;
ll dis[maxn<<6];bool vis[maxn<<6];
void dij() {
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
    q1.push({s,0ll});
    while (!q1.empty()) {
        node t = q1.top();
        q1.pop();
        if (vis[t.p]) continue;
        vis[t.p] = true;
        int u = t.p;
        for (auto i : e[t.p]) {
            int v = i.first,w = i.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q1.push({v,dis[v]});
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m),read(s);
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= m; i++) { 
        int op;read(op);
        if (op == 1) {
            int u1,v1,u2,v2,w;
            read(u1),read(v1),read(u2),read(v2),read(w);
            if (find(u1)==find(v1)&&find(u2)==find(v2)) q[++tot] = {u1,v1,u2,v2,w};
        }else{
            int u,v,w;
            read(u),read(v),read(w);
            int p = find(u),q = find(v);
            if (p != q) e[u].push_back({v,w}),e[v].push_back({u,w}),father[p] = q;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) dfs(i,0);
    }
    cnt = n;
    for (int i = 1; i <= n; i++) id1[i][0]=id2[i][0]=i;
    pre();
    for (int i = 1; i <= tot; i++) {
        ++cnt;
        int u = q[i].u1,v = q[i].v1,w = q[i].w;
        int lca = getlca(u,v);
        add1(u,lca,w),add1(v,lca,w);
        u = q[i].u2,v = q[i].v2;
        lca = getlca(u,v);
        add2(u,lca),add2(v,lca);
    }
    dij();
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 0x3f3f3f3f3f3f3f3f) {
            write(-1),putchar(' ');
        }else{
            write(dis[i]),putchar(' ');
        }
    }
    return 0;
}