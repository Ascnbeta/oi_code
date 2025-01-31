#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct edge{
    int to,nxt;
}e[20004];
int head[102],ind[103],tot;
inline void add(int u,int v) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    ind[v]++;
    head[u] = tot;
}
int pos[503],tgt[104][503];
queue<int> q;
inline void topo() {
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            ind[v]--;
            if (ind[v] == 0) {
                q.push(v);
                --ans;
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x,m;
        cin >> x >> m;
        pos[x] = i;
        tgt[i][0] = m;
        for (int j = 1; j <= m; j++) {
            int y;
            cin >> y;
            tgt[i][j] = y;
        }
        ++ans;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= tgt[i][0]; j++) {
            if (pos[tgt[i][j]] != 0) {
                add(i,pos[tgt[i][j]]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            --ans;
        }
    }
    topo();
    if (ans == 0) puts("YES");
    else cout << ans << '\n';
    return 0;
}