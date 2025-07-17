#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 3e5+4;
struct edge{
    int to,nxt;ll w;
}e[maxn<<1];
int head[maxn],tot;
inline void add(int u,int v,ll w) {
    e[++tot].to = v;
    e[tot].w = w;
    e[tot].nxt = head[u];
    head[u] = tot;
}
int n,m;int pos[maxn],f[maxn][20],siz[maxn],lst[maxn],tmp;
ll dis[maxn];
void dfs(int u,int fa) {
    siz[u] = 1;
    lst[u] = tmp;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;ll w = e[i].w;
        if (v == fa) continue;
        dis[v] = dis[u] + w;
        f[v][0] = u;
        if (u == 1) tmp = v;
        dfs(v,u);
        siz[u] += siz[v];
    }
}
void pre() {
    for (int i = 1; i <= __lg(n); i++) {
        for (int j = 1; j <= n; j++) f[j][i] = f[f[j][i-1]][i-1];
    }
}bool vis[maxn];
bool dfs2(int u,int fa) {
    if (vis[u]) return true;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa) continue;
        if (!dfs2(v,u)) return false;
    }
    if (siz[u] == 1) return false;
    return true;
}
struct node{
    int id;ll w;
    bool operator < (const node &y) const{
        return w < y.w;
    }
};
vector<node> t1;bool ned[maxn];
priority_queue<ll,vector<ll>,greater<ll>> q1,q2;
inline bool check(ll x) {
    int p[maxn];
    memcpy(p,pos,sizeof(p));
    memset(ned,0,sizeof(ned));
    memset(vis,0,sizeof(vis));
    t1.clear();
    for (int i = 1; i <= m; i++) {
        for (int j = __lg(n); j >= 0; j--) {
            if (dis[pos[i]]-dis[f[p[i]][j]]>x) continue;
            p[i] = f[p[i]][j];
        }
        if (p[i] == 1) t1.push_back({lst[pos[i]],x-dis[pos[i]]});
        else vis[p[i]] = true;
    }
    for (int i = head[1]; i ;i = e[i].nxt) {
        int v = e[i].to;
        if (!dfs2(v,1)) ned[v] = true;
    }
    sort(t1.begin(),t1.end());
    q1 = q2 = {};
    for (auto i : t1) {
        if (ned[i.id] && i.w < dis[i.id]) ned[i.id] = false;
        else q1.push(i.w);
    }
    for (int i = head[1]; i ;i = e[i].nxt) {
        int v = e[i].to;
        if (ned[v]) q2.push(dis[v]);
    }
    while (!q2.empty()) {
        while (!q1.empty()&&q1.top()<q2.top()) q1.pop();
        if (q1.empty()) return false;
        q1.pop(),q2.pop();
    }
    return true;
}
ll sum;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u,v;ll w;
        cin >> u >> v >> w;sum += w;
        add(u,v,w);add(v,u,w);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> pos[i];
    dfs(1,0);
    dis[0] = -1e18;
    pre();
    ll l = 0,r = sum,ans = 5e13+3;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    if (ans != 5e13+3) cout << ans << '\n';
    else cout << -1 << '\n';
    return 0;
}