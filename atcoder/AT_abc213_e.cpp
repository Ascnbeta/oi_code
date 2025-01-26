#include <bits/stdc++.h>
using namespace std;
int h,w;
int mp[504][504],dis[504][504];
bool vis[504][504];
struct node {
    int x,y,cnt;
};
deque <node> q;
int dx[5] = {0,0,0,1,-1},dy[5] = {0,1,-1,0,0};
void bfs(int sx,int sy,int c) {
    vis[sx][sy] = true;
    q.push_front(node{sx,sy,c});
    while (!q.empty()) {
        node t = q.front();
        q.pop_front();
        for (int i = 1; i <= 4; i++) {
            int tx = t.x + dx[i],ty = t.y + dy[i];
            if (tx < 1 || tx > h || ty < 1 || ty > w) continue;
            if (mp[tx][ty] == 1) continue;
            if (dis[tx][ty] <= dis[t.x][t.y]) continue;
            q.push_front(node{tx,ty,t.cnt});
            dis[tx][ty] = t.cnt;
        }
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (i == -2 && j == -2) continue;
                if (i == -2 && j == 2) continue;
                if (i == 2 && j == -2) continue;
                if (i == 2 && j == 2) continue;
                int tx = t.x + i,ty = t.y + j;
                if (tx < 1 || tx > h || ty < 1 || ty > w) continue;
                if (dis[tx][ty] <= dis[t.x][t.y] + 1) continue;
                q.push_back(node{tx,ty,t.cnt+1});
                dis[tx][ty] = t.cnt+1;
            }
        }
    }
}
int main () {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') mp[i][j] = 1;
        }
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1][1] = 0;
    bfs(1,1,0);
    cout << dis[h][w] << endl;
    return 0;
}