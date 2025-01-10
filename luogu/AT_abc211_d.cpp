#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n,m,cnt[200005],dis[200005];
struct edge{
    int to,nxt;
}e[400005];
int head[200005],tot = 1;
void add(int u,int v) {
    e[tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot++;
}
queue<int> q;
bool vis[200005];
void bfs(int st) {
    vis[st] = true;
    q.push(st);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = head[t];i;i = e[i].nxt) {
            if (!vis[e[i].to]) {
                dis[e[i].to] = dis[t] + 1;
                cnt[e[i].to] += cnt[t];
                q.push(e[i].to);
                vis[e[i].to] = true;
            }else if (dis[e[i].to] == dis[t] + 1){
                cnt[e[i].to] += cnt[t];
                cnt[e[i].to] %= mod;
            }
        }
    }
}
int main () {
    cin >> n >> m;
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1; i <= m; i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    dis[1] = 0;
    cnt[1] = 1;
    bfs(1);
    cout << cnt[n] % mod << endl;
    return 0;
}