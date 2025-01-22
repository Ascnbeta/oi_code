#include <bits/stdc++.h>
using namespace std;
int d,p,c,f,s;//d->max dollar p -> path c -> city f -> flight s -> start
long long ans;
struct edge{
    int to,nxt,w;
}e[550];
int head[204],tot;
void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].w = w;
    e[tot].nxt = head[u];
    head[u] = tot;
}
int dis[224],cnt[224];
bool vis[224];
queue<int> q;
void spfa(int st) {
    for (int i = 1; i <= c; i++) {
        dis[i] = 0;
    }
    dis[st] = d;
    vis[st] = true;
    q.push(st);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        vis[t] = false;
        for (int i = head[t];i;i = e[i].nxt) {
            int tmp = e[i].to;
            if (dis[tmp] < dis[t] + e[i].w) {
                dis[tmp] = dis[t] + e[i].w;
                cnt[tmp] = cnt[t] + 1;
                if (cnt[tmp] > p + f) {
                    cout << -1 << '\n';
                    exit(0);
                }
                if (!vis[tmp]) {
                    vis[tmp] = true;
                    q.push(tmp);
                }
            }
        }
    }
}
int main () {
    cin >> d >> p >> c >> f >> s;
    for (int i = 1; i <= p; i++) {
        int x,y;
        cin >> x >> y;
        add(x,y,d);
    }
    for (int i = 1; i <= f; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,d-z);
    }
    spfa(s);
    for (int i = 1; i <= c; i++) {
        ans = max(ans,(long long)dis[i]);
    }
    cout << ans << '\n';
    return 0;
}