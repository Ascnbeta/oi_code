#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+10;
const int maxm = 4e5+20;
int n,m,k;
struct edge{
    int to,nxt,w;
}e[maxm];
int head[maxn],tot;
inline void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
struct node{
    int w,p;
    bool operator < (const node &y) const{
        return w > y.w;
    }
};
priority_queue<node> q;
int dis[maxn];
bool vis[maxn];
inline void dij() {
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    q.push({0,1});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[t.p]) continue;
        vis[t.p] = true;
        for (int i = head[t.p]; i; i = e[i].nxt) {
            int v = e[i].to,w = e[i].w;
            if (vis[v]) continue;
            if (dis[v] > dis[t.p] + w) {
                dis[v] = dis[t.p] + w;
                q.push({dis[v],v});
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int j = 0; j <= k; j++) {
        ans = min(ans,dis[n+j*n]);
    }
    cout << ans << '\n';
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        for (int j = 0; j <= k; j++) {
            add(u+j*n,v+j*n,w);
            add(v+j*n,u+j*n,w);
        }
        for (int j = 0; j < k; j++) {
            add(u+j*n,v+(j+1)*n,w/2);
            add(v+j*n,u+(j+1)*n,w/2);
        }
    }
    dij();
    return 0;
}