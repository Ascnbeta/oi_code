#include <bits/stdc++.h>
using namespace std;
int n,m,Q;
int mp[32][32];
int dx[5] = {0,0,0,-1,1},dy[5] = {0,-1,1,0,0};
int dis[32][32];
struct node{
    int x,y,cnt;
};
inline int f(int x,int y,int tp) { //tp:0->left 1->right 2->up 3->down
    return (((x-1)*m+y)-1)*4+tp;
}
bool vis[32][32];
inline int bfs1(int sx,int sy,int tx,int ty,int bx,int by) {
    if (sx<=0||sx>n||sy<=0||sy>m||mp[sx][sy]==0) return -1;
    queue<node> q;
    q.push({sx,sy,0});
    memset(vis,0,sizeof(vis));
    vis[sx][sy] = true;
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if (t.x == tx&&t.y == ty) return t.cnt;
        for (int i = 1; i <= 4; i++) {
            int nx = t.x+dx[i],ny = t.y+dy[i];
            if (vis[nx][ny]) continue;
            if (nx<=0||nx>n||ny<=0||ny>m||mp[nx][ny]==0) continue;
            if (nx == bx && ny == by) continue;
            q.push({nx,ny,t.cnt+1});
            vis[nx][ny] = true;
        }
    }
    return -1;
}
struct edge {
    int v,w;
};
vector<edge> e[4003];
int dist[4003];
struct node1{
    int first,second;
    bool operator < (const node1 &y) const {
        return second > y.second;
    }
};
priority_queue<node1> q;
inline void dijkstra(int s) {
    memset(dist,0x3f,sizeof(dist));
    bool vis[4003];
    memset(vis,0,sizeof(vis));
    dist[s] = 0;
    q.push({s,dist[s]});
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (vis[t.first]) continue;
        vis[t.first] = true;
        for (auto i : e[t.first]) {
            int v = i.v,w = i.w;
            if (!vis[v]&&dist[v]>dist[t.first]+w) {
                dist[v] = dist[t.first] + w;
                q.push({v,dist[v]});
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> Q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j ++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 0) continue;
            for (int p = 1; p <= 4; p++) {
                for (int q = 1; q <= 4; q++) {
                    if (p == q) continue;
                    int t = bfs1(i+dx[p],j+dy[p],i+dx[q],j+dy[q],i,j);
                    if (t != -1) e[f(i,j,p-1)].push_back({f(i,j,q-1),t});
                }
            }
            for (int p = 1; p <= 4; p++) {
                int nx = i+dx[p],ny = j+dy[p];
                if (nx<=0||nx>n||ny<=0||ny>m||mp[nx][ny]==0) continue;
                e[f(i,j,p-1)].push_back({f(nx,ny,(p-1)^1),1});
            }
        }
    }
    while (Q--) {
        int ex,ey,sx,sy,tx,ty;
        cin >> ex >> ey >> sx >> sy >> tx >> ty;
        if (sx == tx && sy == ty) {
            cout << 0 << '\n';
            continue;
        }
        if (!mp[sx][sy]||!mp[tx][ty]||!mp[ex][ey]) {
            cout << -1 << '\n';
            continue;
        } 
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= 4; i++) {
            int nx = sx+dx[i],ny = sy+dy[i];
            if (nx<=0||nx>n||ny<=0||ny>m||mp[nx][ny]==0) continue;
            int cnt1 = bfs1(ex,ey,nx,ny,sx,sy);
            if (cnt1 == -1) continue;
            dijkstra(f(sx,sy,i-1));
            ans = min({ans,cnt1+dist[f(tx,ty,0)],cnt1+dist[f(tx,ty,1)],cnt1+dist[f(tx,ty,2)],cnt1+dist[f(tx,ty,3)]});
        }
        if (ans != 0x3f3f3f3f) cout << ans << '\n';
        else cout << -1 << '\n';
    }
    return 0; 
}