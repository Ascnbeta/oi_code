#include <bits/stdc++.h>
using namespace std;
int n,m;
double ans;
struct edge{
    int to,nxt,f,c;
}e[2004];
int tot,head[1005];
void add(int u,int v,int f,int c) {
    e[++tot].nxt = head[u];
    e[tot].to = v;
    e[tot].f = f;
    e[tot].c = c;
    head[u] = tot;
}
int vis[1004],dis[1004];
struct node{
    int d,p;
};
bool operator < (node x,node y) {return x.d > y.d;}
priority_queue<node> q;
void dij(int f) {
    vis[1] = true;
    q.push(node{0,1});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        vis[t.p] = true;
        for (int i = head[t.p];i;i = e[i].nxt) {
            if (vis[e[i].to] || e[i].f < f) continue;
            if (dis[e[i].to] > t.d + e[i].c) {
                dis[e[i].to] = t.d + e[i].c;
                q.push(node{dis[e[i].to],e[i].to});
            }
        }
    }
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x,y,f,c;
        cin >> x >> y >> c >> f;
        add(x,y,f,c);
        add(y,x,f,c);
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= n; j++) {
            vis[j] = false;
            dis[j] = 0x3f3f3f3f;
        }
        dis[1] = 0;
        dij(i);
        if (dis[n] == 0x3f3f3f3f) continue;
        double t = 1.0 * i / dis[n];
        ans = max(ans,t);
    }
    int ans1 = ans * 1000000;
    cout << ans1 << '\n';    
    return 0;
}