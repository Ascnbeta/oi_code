#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+50;
int n,m;
double ans;
vector<int> e[maxn];
double p;
double f[maxn];
bool t[maxn];
int lst = 0;
void dfs(int u,int fa,int lst) {
    for (auto v : e[u]) {
        if (v == fa) continue;
        if (lst) f[v] = min(f[u]+1,p*(f[lst]+1)+(1-p)*(f[u]+1));
        else f[v] = f[u]+1;
        dfs(v,u,t[u]?u:lst);
    }
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> p;
    p = 1-p;
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        t[x] = true;
    }
    dfs(1,0,0);
    for (int i = 1; i <= n; i++) {
        // cout << f[i] << ' ';
        ans += f[i]/n;
    }
    // cout << '\n';
    cout << fixed << setprecision(2) << ans << '\n';
    return 0;
}