#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 4e5+40;
const int maxm = 4e5+30;
int n,m,Q,k,s,lstans,T;
vector<int> to[maxn],lth[maxn];
struct edge{
    int u,v,w;
    bool operator < (const edge &y) const{
        return w > y.w;
    }
}e[maxn];
struct node{
    int p,w;
    bool operator < (const node &y) const{
        return w > y.w;
    }
};
priority_queue<node> q;
int dis[maxn];
bool vis[maxn];
inline void dijkstra(int s) {
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    q.push({s,0});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[t.p]) continue;
        vis[t.p] = true;
        for (int i = 0; i < to[t.p].size(); i++) {
            int v = to[t.p][i],w = lth[t.p][i];
            if (!vis[v] && dis[v] > dis[t.p] + w) {
                dis[v] = dis[t.p] + w;
                q.push({v,dis[v]});
            }
        }
    }
}
int father[maxn];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
vector<int> e1[maxn<<1];
int c[maxn<<1],tot = n;
inline void kruskal() {
    sort(e+1,e+m+1);
    for (int i = 1; i <= n*2; i++) father[i] = i,c[i] = 0;
    for (int i = 1; i <= n*2; i++) e1[i].clear();
    tot = n;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (cnt == n-1) break;
        int x = find(e[i].u),y = find(e[i].v);
        if (x == y) continue;
        e1[++tot].push_back(x);
        e1[tot].push_back(y);
        e1[x].push_back(tot);
        e1[y].push_back(tot);
        c[tot] = e[i].w;
        father[x] = father[y] = tot;
        ++cnt;
        // cout << i << ' ';
    }
    // cout << '\n';
}
int dfn[maxn<<1],out[maxn<<1],cnt;
int f[maxn<<1][30];
int st[maxn<<1][30];
void dfs(int u,int fa) {
    dfn[u] = ++cnt;
    st[dfn[u]][0] = dis[u];
    for (auto v : e1[u]) {
        if (v == fa) continue;
        f[v][0] = u;
        dfs(v,u);
    }
    out[u] = cnt;
}
inline void prepare() {
    for (int i = 1; i <= __lg(tot); i++) {
        for (int j = 1; j <= tot; j++) {
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
    for (int i = 1; i <= __lg(tot); i++) {
        for (int j = 1; j+(1<<i)-1 <= tot; j++) {
            st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
}
inline int query(int l,int r) {
    int j = __lg(r-l+1);
    return min(st[l][j],st[r-(1<<j)+1][j]);
}
inline int solve(int v,int p) {
    for (int i = __lg(tot); i >= 0; i--) {
        if (f[v][i] && c[f[v][i]] > p) v = f[v][i];
    }
   
    return query(dfn[v],out[v]);
}
signed main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
// #ifndef LOCAL
//     freopen("return.in","r",stdin);
//     freopen("return.out","w",stdout);
// #endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cnt = lstans = 0;
        for (int i  = 1; i <= n; i++) to[i].clear(),lth[i].clear();
        for (int i  = 1; i <= m; i++) {
            int l;
            cin >> e[i].u >> e[i].v >> l >> e[i].w;
            to[e[i].u].push_back(e[i].v);
            lth[e[i].u].push_back(l);
            to[e[i].v].push_back(e[i].u);
            lth[e[i].v].push_back(l);
        }
        dijkstra(1);
        // for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
        // cout << '\n';
        kruskal();
        // for (int i = 1; i <= tot; i++) {
        //     if (i > n) cout << c[i] << '\n';
        //     for (auto v : e1[i]) {
        //         cout << v << ' ';
        //     }
        //     cout << '\n';
        // }
        memset(f,0,sizeof(f));
        memset(st,0x3f,sizeof(st));
        dfs(tot,0);
        prepare();
        // for (int i = 1; i <= tot; i++) {
        //     for (int j = 0; j <= __lg(tot); j++) cout << f[i][j] << ' ';
        //     cout << '\n';
        // }
        cin >> Q >> k >> s;
        while (Q--) {
            int v0,p0;
            cin >> v0 >> p0;
            int v = (v0+k*lstans-1)%n+1;
            int p = (p0+k*lstans)%(s+1);
            // cout << v << ' ' << p << '\n';
            lstans = solve(v,p);
            cout << lstans << '\n';
            
        }
    }
    return 0;
}