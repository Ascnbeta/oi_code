#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s;
struct edge{
    int to,nxt,w;
}e[200005];
int tot,head[100004];
void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
struct node{
    int p,dist;
};
bool operator < (node x,node y) {
    return x.dist > y.dist;
}
priority_queue<node> q;
bool vis[100004];
int dist[100004];
void dij(int x) {
    for (int i = 1; i <= n; i++) dist[i] = LONG_LONG_MAX;
    dist[x] = 0;
    q.push(node{x,0});
    while(!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[t.p]) continue;
        vis[t.p] = true;
        for (int i = head[t.p];i;i = e[i].nxt) {
            int tmp = e[i].to;
            if (!vis[tmp] && dist[t.p] + e[i].w < dist[tmp]) {
                dist[tmp] = t.dist + e[i].w;
                q.push(node{tmp,dist[tmp]});
            }
        }
    }
}
signed main () {
    // freopen("hack_spfa1.out","r",stdin);
    // freopen("hack_spfa1.ans","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
    }
    dij(1);
    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
    return 0;
}