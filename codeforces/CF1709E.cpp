#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+30;
int n,ans;
int a[maxn];
vector<int> e[maxn];
set<int> s[maxn];
int dis[maxn];
void dfs(int u,int fa) {
    bool f = false;
    s[u].insert(dis[u]);
    for (auto v : e[u]) {
        if (v == fa) continue;
        dis[v] = dis[u]^a[v];
        dfs(v,u);
        if (s[u].size() < s[v].size()) swap(s[u],s[v]);
        for (auto i : s[v]) if (s[u].find(i^a[u]) != s[u].end()) f = true;
        for (auto i : s[v]) s[u].insert(i);
    }
    if (f) ++ans,s[u].clear();
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dis[1] = a[1];
    dfs(1,0);
    cout << ans << '\n';
    return 0;
}