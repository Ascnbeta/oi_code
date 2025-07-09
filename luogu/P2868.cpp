#include <bits/stdc++.h>
using namespace std;
const int maxn = 1003;
const int maxm = 5003;
const double eps = 1e-5;
int n,m;
int f[maxn];
struct edge{
    int v;double w;
};
vector<edge> e[maxn];
double dis[maxn];bool vis[maxn];int cnt[maxn];
inline bool check(double x) {
    for (int i = 1; i <= n; i++) dis[i] = 1e9;
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (auto i : e[u]) {
            int v = i.v;double w = x*i.w-1.0*f[v];
            if (i.w == 0) w = 0;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;cnt[v] = cnt[u]+1;
                if (!vis[v]) q.push(v),vis[v] = true;
                if (cnt[v] > n+2) return true;
            }
        }
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= m; i++) {
        int u,v;double w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
    }
    for (int i = 1; i <= n; i++) e[0].push_back({i,0});
    double l = 0,r = 1003;
    while (r-l>eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }else{
            r = mid;
        }
    }
    printf("%.2lf",r);
    return 0;
}