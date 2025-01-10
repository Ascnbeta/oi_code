#include <bits/stdc++.h>
using namespace std;
int T,n,m;
struct edge{
    int to,nxt,w;
}e[6004];
int head[2004],tot;
void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
queue<int> q;
bool vis[2004];
int cnt[2004],dis[2004];
bool spfa(int x) {
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
                cnt[e[i].to] = cnt[t] + 1;
                if (cnt[e[i].to] > n) return false;
                if (!vis[e[i].to]) {
                    vis[e[i].to] = true;
                    q.push(e[i].to);
                }
            }
        }
    }
    return true;
}
void init() {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        cnt[i] = 0;
        dis[i] = 0x3f3f3f3f;
        head[i] = 0;
        tot = 0;
        q = {};
    }
}
int main () {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; i++) {
            int x,y,z;
            cin >> x >> y >> z;
            if (z >= 0) {
                add(x,y,z);
                add(y,x,z);
            }else{
                add(x,y,z);
            }
        }
        if (spfa(1)) {
            cout << "NO" << '\n';
        }else{
            cout << "YES" << '\n';
        }
    }
    return 0;
}