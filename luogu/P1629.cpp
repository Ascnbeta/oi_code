#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int dis[1004][1004];
bool vis[1004][1004];
struct edge{
    int to,nxt,w;
}e[100005];
int head[1003],tot;
struct node{
    int p,w;
};
bool operator < (const node x,const node y) {
    return x.w > y.w;
}
priority_queue<node> q;
inline void dij(int x) {
    while (!q.empty()) q.pop();
    q.push(node{x,0});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        vis[x][t.p] = true;
        if (t.p == 1 && x != 1) return;
        for (int i = head[t.p];i;i = e[i].nxt) {
            if (vis[x][e[i].to]) continue;
            if (dis[x][e[i].to] > dis[x][t.p] + e[i].w) {
                dis[x][e[i].to] = dis[x][t.p] + e[i].w;
                q.push(node{e[i].to,dis[x][e[i].to]});
            }
        }
    }
}
void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
    }
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
        dij(i);
    }
    for (int i = 2; i <= n; i++) {
        ans += dis[1][i];
        ans += dis[i][1];
    }
    cout << ans << '\n';
    return 0;
}