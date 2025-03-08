#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
struct edge{
    int to,nxt;
}e[200005];
int tot,head[10005];
int vis[10005];
int cnt[3];
void add(int u,int v) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}
void dfs(int x,int c) {
    vis[x] = c;
    cnt[c]++;
    for (int i = head[x];i;i = e[i].nxt) {
        if (vis[e[i].to] == c) {
            cout << "Impossible" << '\n';
            exit(0);
        }
        if (vis[e[i].to] == 0) {
            dfs(e[i].to,(c==1)?2:1);
        }
    }
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= m;i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i,1);
            ans = min(cnt[1],cnt[2]);
            cnt[1] = cnt[2] = 0;
        }
        
    }
    cout << ans << '\n';
    return 0;
}