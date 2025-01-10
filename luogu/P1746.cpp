#include <bits/stdc++.h>
using namespace std;
int n,mp[1004][1004],sx,sy,ex,ey;
struct node{
    int x,y,cnt;
};
queue<node> q;
bool vis[1004][1004];
int dx[5] = {0,1,-1,0,0},dy[5] = {0,0,0,1,-1};
void bfs(int sx1,int sy1) {
    vis[sx1][sy1] = true;
    q.push(node{sx1,sy1,0});
    while (!q.empty()) {
        node t = q.front();
        if (t.x == ex && t.y == ey) {
            cout << t.cnt << '\n';
            exit(0);
        }
        q.pop();
        for (int i = 1; i <= 4; i++) {
            int tx = t.x + dx[i],ty = t.y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > n) continue;
            if (vis[tx][ty]) continue;
            if (mp[tx][ty] == 1) continue;
            vis[tx][ty] = true;
            q.push(node{tx,ty,t.cnt+1});
        }
    }
}
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            mp[i][j] = ch - '0';
        }
    }
    cin >> sx >> sy >> ex >> ey;
    bfs(sx,sy);
    return 0;
}