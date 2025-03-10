#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+30;
const int maxm = 5e5+30;
int m,n;
int trie[maxm][2],ed[maxm],tot = 1;
int siz[maxm];
void dfs(int u) {
    siz[u] = ed[u];
    if (trie[u][1]) dfs(trie[u][1]),siz[u] += siz[trie[u][1]];
    if (trie[u][0]) dfs(trie[u][0]),siz[u] += siz[trie[u][0]];
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        int u = 1;
        for (int j = 1; j <= k; j++) {
            int v;
            cin >> v;
            if (!trie[u][v]) trie[u][v] = ++tot;
            u = trie[u][v];
        }
        ed[u]++;
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int f = false;
        int u = 1;
        int ans = 0;
        for (int j = 1; j <= k; j++) {
            int v;
            cin >> v;
            if (!f && trie[u][v] == 0) {
                f = true;
            }else if (!f && trie[u][v] != 0) {
                u = trie[u][v];
                if (j == k) ans += siz[u];
                else ans += ed[u];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}