#include <bits/stdc++.h>
using namespace std;
int n,m,s;
struct edge{
    int to,nxt,w;
}e[500004];
int head[200004],tot;
void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
queue<int> q;
int dis[200004];
bool vis[200004];
void spfa(int x) {
    memset(dis,0x3f,sizeof(dis));
    dis[x] = 0;
    vis[x] = true;
    q.push(x);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        vis[t] = false;
        for (int i = head[t];i;i = e[i].nxt) {
            if (dis[e[i].to] > dis[t] + e[i].w) {
                dis[e[i].to] = dis[t] + e[i].w;
                if (vis[e[i].to]) continue;
                vis[e[i].to] = true;
                q.push(e[i].to);
            }
        }
    }
} 
int main () {
    freopen("hack_spfa1.out","r",stdin);
    freopen("hack_spfa1.ans","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
    }
    spfa(1);
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 0x3f3f3f3f) {
            cout << INT_MAX << ' ';
            continue; 
        }
        cout << dis[i] << ' ';
    }
    cout << '\n';
    return 0;
}