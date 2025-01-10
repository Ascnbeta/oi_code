#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[100004],dy[100004],tot = 1;
bool vis[403][403];
int ans[403][403];
struct node{
    int x,y,cnt;
};
queue<node> q;
void bfs(int sx,int sy,int s) {
    vis[sx][sy] = true;
    q.push(node{sx,sy,s});
    while(!q.empty()) {
        node t = q.front();
        q.pop();
        for (int i = 1; i <= tot; i++) {
            int tx = t.x + dx[i],ty = t.y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > n) continue;
            if (vis[tx][ty]) continue;
            vis[tx][ty] = true;
            ans[tx][ty] = t.cnt+1;
            q.push(node{tx,ty,t.cnt+1});
        }
    }
}
int main () {
    cin >> n >> m;
    for (int i = 1; i * i <= m; i++) {
        double tmp = sqrt(m-i*i);
        double t = floor(tmp);
        if (t == tmp) {
            dx[tot] = i;
            dy[tot++] = tmp;
            dx[tot] = tmp;
            dy[tot++] = i;
            dx[tot] = -i;
            dy[tot++] = tmp;
            dx[tot] = -tmp;
            dy[tot++] = i;
            dx[tot] = -tmp;
            dy[tot++] = -i;
            dx[tot] = -i;
            dy[tot++] = -tmp;
            dx[tot] = i;
            dy[tot++] = -tmp;
            dx[tot] = tmp;
            dy[tot++] = -i;
        }
    }
    --tot;
    bfs(1,1,0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1&&j == 1) {
                cout << 0 << ' ';
                continue;
            }
            if (ans[i][j] == 0) {
                cout << -1 << ' ';
                continue;
            } 
            cout << ans[i][j] <<' ';
        }
        cout << '\n';
    }
    return 0;
}