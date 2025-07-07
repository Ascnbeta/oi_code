#include <bits/stdc++.h>
using namespace std;
int n,m;
int mp[53][53];//0->空 1->水 2->岩石
int sx,sy,ex,ey;
int dx[5]={0,0,0,-1,1},dy[5]={0,-1,1,0,0};
struct node{
    int x,y,dis;
};
queue<node> q;
int dis[53][53];
bool vis[53][53];
inline void pre(int x,int y) {
    dis[x][y] = 0;
    memset(vis,0,sizeof(vis));
    q.push({x,y,0});
    vis[x][y] = true;
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        dis[t.x][t.y] = min(dis[t.x][t.y],t.dis);
        for (int i = 1; i <= 4; i++) {
            int tx = t.x+dx[i],ty = t.y+dy[i];
            if (tx<=0||tx>n||ty<=0||ty>m||vis[tx][ty]||mp[tx][ty]!=0) continue;
            if ((tx==sx&&ty==sy)||(tx==ex&&ty==ey)) continue;
            q.push({tx,ty,t.dis+1});
            vis[tx][ty] = true;
        }
    }
}
int dep[53][53];
inline void bfs() {
    dep[sx][sy] = 0;
    memset(vis,0,sizeof(vis));
    q.push({sx,sy,0});
    vis[sx][sy] = true;
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        dep[t.x][t.y] = t.dis;
        if (t.x == ex && t.y == ey) {
            cout << t.dis << '\n';
            exit(0);
        }
        for (int i = 1; i <= 4; i++) {
            int tx = t.x+dx[i],ty = t.y+dy[i];
            if (tx<=0||tx>n||ty<=0||ty>m||vis[tx][ty]||mp[tx][ty]!=0) continue;

            if (t.dis+1 >= dis[tx][ty]) continue;
            q.push({tx,ty,t.dis+1});
            vis[tx][ty] = true;
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;cin >> ch;
            if (ch == 'S') {
                sx = i,sy = j;
            }else if(ch == 'D') {
                ex = i,ey = j;
            }else if(ch == '*') {
                mp[i][j] = 1;
            }else if(ch == 'X') {
                mp[i][j] = 2;
            }
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 1) pre(i,j);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    bfs();
    puts("KAKTUS");
    return 0;
}