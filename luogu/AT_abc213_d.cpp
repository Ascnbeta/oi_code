#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> e[200005],ans;
bool vis[200005];
void add(int u,int v) {
    e[u].push_back(v);
}
void dfs(int x) {
    ans.push_back(x);
    vis[x] = true;
    bool f1 = false;
    for (int i = 0; i < e[x].size(); i++) {
        if (vis[e[x][i]]) continue;
        dfs(e[x][i]);
        ans.push_back(x);
        f1 = true;
    }
    if (!f1) {
        return;
    }
}
int main () {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    for (int i = 1; i <= n; i++) {
        sort(e[i].begin(),e[i].end());
    }
    dfs(1);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}