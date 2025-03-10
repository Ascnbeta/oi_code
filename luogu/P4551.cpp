#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
int n,ans;
struct edge{
    int v,w;
};
vector<edge> e[maxn]; 
int dis[maxn];
int trie[maxn*35][2],ed[maxn*35],tot = 1;
void dfs (int u,int fa) {
    for (auto i : e[u]) {
        int v = i.v,w = i.w;
        if (fa == v) continue;
        dis[v] = dis[u]^w;
        dfs(v,u);
    }
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n; 
    for (int i = 1; i < n; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,0);
    for (int i = 1; i <= n; i++) {
        string s = "";
        for (int j = 31; j >= 0; j--) {
            if ((dis[i]>>j)&1 != 0) s += '1';
            else s += '0';
        }
        // cout << dis[i] << ' ' << s << '\n';
        int u = 1;
        for (int j = 0; j < s.size(); j++) {
            int v = s[j] - '0';
            if (!trie[u][v^1]) u = trie[u][v];
            else u = trie[u][v^1];
        }
        // cout << dis[i] << ' ' << (int)(ed[u]^dis[i]) << '\n';
        ans = max(ans,ed[u]^dis[i]);
        u = 1;
        for (int j = 0; j < s.size(); j++) {
            int v = s[j] - '0';
            if (!trie[u][v]) trie[u][v] = ++tot;
            u = trie[u][v];
        }
        ed[u] = dis[i];
    }
    cout << ans << '\n';
    return 0;
}