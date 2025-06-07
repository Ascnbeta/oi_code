#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+30;
int n,m,k;
vector<pair<int,int>> e[maxn];
int s,t;
struct node{
    int p,w;
    bool operator < (const node &y) const{
        return w > y.w;
    }
};
priority_queue<node> q;
int dis[maxn];bool f[maxn];
inline void dijkstra() {
    memset(dis,0x3f,sizeof(dis));
    memset(f,0,sizeof(f));
    dis[s] = 0;
    q.push({s,0});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (f[t.p]) continue;
        f[t.p] = true;
        for (auto i : e[t.p]) {
            int v = i.first,w = i.second;
            if (dis[v] > dis[t.p] + w) {
                dis[v] = dis[t.p] + w;
                q.push({v,dis[v]});
            }
        } 
    }
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    cin >> s >> t;
    ++s,++t;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        ++u,++v;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        for (int j = 1; j <= k; j++) {
            e[u+n*j].push_back({v+n*j,w});
            e[v+n*j].push_back({u+n*j,w});
            e[u+(j-1)*n].push_back({v+n*j,0});
            e[v+(j-1)*n].push_back({u+n*j,0});
        }
    }
    dijkstra();
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; i++) ans = min(ans,dis[i*n+t]);
    cout << ans << '\n';
    return 0;
}