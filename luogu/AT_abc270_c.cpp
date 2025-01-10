#include <bits/stdc++.h>
using namespace std;
int n,x,y,ans[200005];
struct edge {
    int pre,nxt;
}e[400005];
int head[200005],tot = 1;
bool vis[200005];
void add(int u,int v) {
    e[tot].pre = v;
    e[tot].nxt = head[u];
    head[u] = tot++;
}
void dfs(int p,int cnt) {
    ans[cnt] = p;
    vis[p] = true;
    if (p == y) {
        for (int i = 1; i <= cnt; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        exit(0);
    }
    int tmp = head[p];
    for (;tmp != 0; tmp = e[tmp].nxt) {
        if (vis[e[tmp].pre]) continue;
        dfs(e[tmp].pre,cnt+1);
    }
    vis[p] = false;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    for (int i = 1; i <= n-1; i++) {
        int p,q;
        cin >> p >> q;
        add(p,q);
        add(q,p);
    }
    dfs(x,1);
    return 0;
}