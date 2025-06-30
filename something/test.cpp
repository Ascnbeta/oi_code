#include <bits/stdc++.h>
using namespace std;
int n,m,s;
struct edge{
    int to,nxt,w;
}e[500004];
int head[10004],tot;
void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
deque<int> q;
int dis[10004];
bool vis[10004];
void spfa(int x) {
    for (int i = 1; i <= n; i++) dis[i] = 0x7fffffff;
    dis[x] = 0;
    vis[x] = true;
    q.push_back(x);
    while (!q.empty()) {
        int t = q.front();
        q.pop_front();
        vis[t] = false;
        for (int i = head[t];i;i = e[i].nxt) {
            if (dis[e[i].to] > dis[t] + e[i].w) {
                dis[e[i].to] = dis[t] + e[i].w;
                if (vis[e[i].to]) continue;
                vis[e[i].to] = true;
                int v = e[i].to;
                if (!q.empty() && dis[v] < dis[q.front()]) {
                    q.push_front(v);
                }else{
                    q.push_back(v);
                }
            }
        }
    }
} 
int main () {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
    }
    spfa(s);
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << '\n';
    return 0;
}