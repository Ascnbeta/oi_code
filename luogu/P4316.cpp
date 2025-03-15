#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
int n,m;
struct edge{
    int v,w;
};
vector<edge> e[maxn];
int ind[maxn],ou[maxn];
queue<int> q;
double f[maxn];
inline void topo() {
    f[n] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto i : e[u]) {
            int v = i.v,w = i.w;
            f[v] += 1.0/ou[v]*(f[u]+w);
            --ind[v];
            if (!ind[v]) q.push(v);
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        e[v].push_back({u,w});
        ind[u]++;
        ou[u]++;
    }
    q.push(n);
    topo();
    cout << fixed << setprecision(2) << f[1] << '\n';
    return 0;
}