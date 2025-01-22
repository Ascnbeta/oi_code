#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct edge{
    int to,nxt,w;
}e[50004];
int head[1506],tot;
void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot; 
}
struct node{
    int p,w;
};
bool operator <(node x,node y) {
    return x.w < y.w;
}
int dis[1506];
bool vis[1506];
queue<node> q;
void spfa(int s) {
    for (int i = 1; i <= n; i++) dis[i] = -1000000000;
    dis[s] = 0;
    vis[s] = true;
    q.push(node{s,0});
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        vis[t.p] = false;
        for (int i = head[t.p];i;i = e[i].nxt) {
            int y = e[i].to;
            if (dis[t.p] + e[i].w > dis[y]) {
                dis[y] = dis[t.p] + e[i].w;
                if (!vis[y]) {
                    vis[y] = true;
                    q.push(node{y,dis[y]});
                }
            }
        }
    }
}
signed main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
    }
    spfa(1);
    if (dis[n] == -1000000000) cout << -1 << '\n';
    else{
        cout << dis[n] << '\n';
    } 
    return 0;
}