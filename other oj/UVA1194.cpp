#include <bits/stdc++.h>
using namespace std;
const int maxn = 103;
const int maxm = 103;
const int maxk = 1003;
int n,m,k;
vector<int> e[504];
int match[503],vis[503];
inline bool hungary(int u,int cur) {
    if (vis[u] == cur) return false;
    vis[u] = cur;
    for (auto v : e[u]) {
        if (!match[v] || hungary(match[v],cur)) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    while (1) {
        cin >> n;
        if (n == 0) return 0;
        cin >> m >> k;
        int ans = 0;
        for (int i = 1; i <= n+m;i++ ) e[i].clear(),match[i] = vis[i] = 0;
        for (int i = 1; i <= k; i++) {
            int p,x,y;
            cin >> p >> x >> y;
            if (x == 0 || y == 0) continue;
            e[x].push_back(y+n);
        }
        for (int i = 1; i < n; i++) {
            if (hungary(i,i)) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}