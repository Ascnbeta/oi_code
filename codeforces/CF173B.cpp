#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
vector<int> e[maxn<<1];
int n,m;
queue<int> q;int dis[maxn<<1];
inline void bfs(int s) {
    q.push(s);
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            if (!dis[v]) dis[v] = dis[u] + 1,q.push(v);
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
            char ch;
            cin >> ch;
            if (ch == '#') {
                e[i].push_back(j+n);
                e[j+n].push_back(i);
            }
        }
    }
    bfs(1);
    if (dis[n] == 0) cout << -1 << '\n';
    else cout << dis[n] << '\n';
    return 0;
}