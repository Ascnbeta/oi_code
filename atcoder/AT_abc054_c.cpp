#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
struct edge{
    int to,nxt;
}e[60];
int head[10],tot = 1;
void add(int u,int v) {
    e[tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot++;
}
bool vis[10];
void dfs(int cur,int cnt) {
    vis[cur] = true;
    if (cnt == n) {
        ++ans;
        vis[cur] = false;
        return;
    }
    for (int i = head[cur];i;i = e[i].nxt) {
        if (vis[e[i].to]) continue;
        dfs(e[i].to,cnt+1);
    }
    vis[cur] = false;
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    dfs(1,1);
    cout << ans;
    return 0;
}