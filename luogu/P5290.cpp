#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n,a[maxn];
vector<int> e[maxn];
priority_queue<int> q[maxn];
vector<int> tmp;
void dfs(int u,int fa) {
    for (auto v : e[u]) {
        if (v ==fa) continue;
        dfs(v,u);
        if (q[u].size() < q[v].size()) swap(q[u],q[v]);
        while (!q[v].empty()) {
            int x = q[u].top(),y = q[v].top();
            tmp.push_back(max(x,y));
            q[u].pop(),q[v].pop();
        }
        for (auto i : tmp) q[u].push(i);
        tmp.clear();
    }
    q[u].push(a[u]);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        int x;cin >> x;
        e[x].push_back(i);
    }
    dfs(1,0);
    long long ans = 0;
    while (!q[1].empty()) ans += q[1].top(),q[1].pop();
    cout << ans << '\n';
    return 0;
    return 0;
}