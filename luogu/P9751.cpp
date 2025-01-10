#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
    int to,nxt,w;
}e[20005];
int tot,head[10004];
void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
struct node{
    int p,t;
};
bool operator < (node x,node y) {
    return x.t > y.t;
}
bool vis[10004][105];
int dist[10004][105];
priority_queue<node> q;
void dij(int x) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dist[i][j] = LONG_LONG_MAX;
        }
    }
    dist[x][0] = 0;
    q.push(node{x,0});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[t.p][t.t%k]) continue;
        vis[t.p][t.t%k] = true;
        for (int i = head[t.p];i;i = e[i].nxt) {
            int tmp = t.t;
            if (t.t < e[i].w) {
                if ((e[i].w - t.t) % k != 0) {
                    tmp = ((e[i].w - t.t)/k + 1) * k + t.t;
                }else{
                    tmp = (e[i].w - t.t)/k*k+t.t;
                }
            }
            if(dist[e[i].to][(tmp + 1)%k] > tmp + 1){
				dist[e[i].to][(tmp + 1)%k] = tmp + 1;
				q.push({e[i].to,tmp + 1});
			}
        }
    }
}
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("bus2.in","r",stdin);
    //freopen("ans.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
    }
    dij(1);
    if (vis[n][0] == false) puts("-1");
    else cout << dist[n][0] << '\n';
    return 0;
}