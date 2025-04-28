#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 2e5+30;
vector<int> e[maxn];
int T,n,k;
int x[maxn];
int dfn[maxn],cnt,dep[maxn],out[maxn],son[maxn];
void dfs(int u,int fa) {
    dfn[u] = ++cnt;
    dep[u] = dep[fa] + 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        ++son[u];
        dfs(v,u);
    }
    out[u] = cnt;
}
int st[maxn][25],f[maxn];
inline void init() {
    for (int i = 2; i <= n; i++) f[i] = f[i/2]+1;
    for (int i = 1; (1<<i) <= n; i++) {
        for (int j = 1; j+(1<<i)-1 <= n; j++) {
            st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
}
inline int query(int l,int r) {
    int j = f[r-l+1];
    return min(st[l][j],st[r-(1<<j)+1][j]);
}
bool f1 = false;
void dfs2(int u,int fa) {
    if (query(dfn[u],out[u])-dep[u] <= dep[u]-1) return;
    if (son[u] == 0) {
        cout << "YES" << '\n';
        f1 = true;
        return;
    }
    
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs2(v,u);
        if (f1) return;
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cnt = 0;
        f1 = false;
        for (int i = 1; i <= n; i++) {
            son[i] = 0,e[i].clear(),st[i][0] = 0x3f3f3f3f;
        }
        for (int i = 1; i <= k; i++) cin >> x[i];
        for (int i = 1; i < n; i++) {
            int u,v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1,0);
        for (int i = 1; i <= k; i++) {
            st[dfn[x[i]]][0] = dep[x[i]];
        }
        // for (int i = 1; i <= n; i++) cout << st[i][0] << ' ';
        // cout << '\n';
        init();
        dfs2(1,0);
        if (!f1) cout << "NO" << '\n';
    }
    return 0;
}