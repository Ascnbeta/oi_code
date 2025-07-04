#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4+10;
const int maxs = 3e5+10;
int n;string s[maxn];
int trie[maxs][26],tot,ed[maxs];
inline void insert(string t,int cnt) {
    int p = 0;
    for (int i = 0; i < t.size(); i++) {
        if (!trie[p][t[i]-'a']) {
            trie[p][t[i]-'a'] = ++tot;
        }
        p = trie[p][t[i]-'a'];
    }
    ed[p] = cnt;
}
vector<int> e[30];
bool f[maxn];int ans;
inline void check(int p) {
    int ind[30];memset(ind,0,sizeof(ind));
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        for (auto v : e[i]) {
            ++ind[v];
        }
    }
    for (int i = 0; i < 26; i++) if (!ind[i]) q.push(i);
    int cnt = 26;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        --cnt;
        for (auto v : e[u]) {
            --ind[v];
            if (ind[v] == 0) q.push(v);
        }
    }
    if (cnt == 0) f[p] = true,++ans;
}
void dfs(int u) {
    if (ed[u]) {
        check(ed[u]);
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (trie[u][i]) {
            for (int j = 0; j < 26; j++) {
                if (i != j && trie[u][j]) {
                    e[i].push_back(j);
                }
            }
            dfs(trie[u][i]);
            for (int j = 0; j < 26; j++) {
                if (i != j && trie[u][j]) {
                    e[i].pop_back();
                }
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i],insert(s[i],i);
    dfs(0);
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) if (f[i]) cout << s[i] << '\n';
    return 0;
}