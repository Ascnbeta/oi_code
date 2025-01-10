#include <bits/stdc++.h>
using namespace std;
int n,k,m,ans;
struct edge{
    int to,nxt;
}e[5006];
int tot,head[103];
void add(int u,int v) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}
int c[103];
bool check(int p,int x) {
    for (int i = head[p];i;i = e[i].nxt) {
        if (c[e[i].to] == x) return false;
    }
    return true;
}
void dfs(int cnt) {
    if (cnt == n + 1) {
        ++ans;
        return;
    }
    for (int i = 1; i <= m; i++) {
        if (check(cnt,i)) {
            c[cnt] = i;
            dfs(cnt+1);
            c[cnt] = 0;
        }
    }
}
int main () {
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    dfs(1);
    cout << ans << '\n';
    return 0;
}