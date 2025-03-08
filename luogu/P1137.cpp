#include <bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
    int to,nxt;
}e[200004];
int ind[100004],head[100004],tot;
inline void add(int u,int v) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
    ind[v]++;
}
bool f[100003];
int dis[100003];
queue<int> q;
inline void topo() {
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = head[t]; i; i = e[i].nxt) {
            int v = e[i].to;
            ind[v]--;
            if (ind[v] == 0) dis[v] = dis[t] + 1,q.push(v);
        }
    }
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        add(u,v);
    }
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            dis[i] = 1;
        }
    }
    topo();
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << '\n';
    }
    return 0;
}