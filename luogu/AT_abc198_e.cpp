#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct edge{
    int to,nxt;
}e[200005];
int c[100005],head[100005],h[100005],tot = 1;
bool vis[100005];
vector<int> v;
void add(int u, int v) {
    e[tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot++;
}
void dfs(int cur) {
    vis[cur] = true;
    if (h[c[cur]] == 0) v.push_back(cur);
    h[c[cur]]++;
    for (int i = head[cur];i;i = e[i].nxt) {
        if (vis[e[i].to]) continue;
        dfs(e[i].to);
    }
    vis[cur] = false;
    h[c[cur]]--;
}
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n-1; i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    dfs(1);
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
    return 0;
}