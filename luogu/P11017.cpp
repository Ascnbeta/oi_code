#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+30;
int T,n,p,q;
vector<int> e[maxn];
int dep[maxn],deg[maxn],siz[maxn],top[maxn],son[maxn],f[maxn];
void dfs1(int u,int fa) {
    siz[u] = 1;
    son[u] = 0;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        f[v] = u;
        dfs1(v,u);
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u,int fa,int tp) {
    top[u] = tp;
    if (son[u]) dfs2(son[u],u,tp);
    for (auto v : e[u]) {
        if (v == fa || v == son[u]) continue;
        dfs2(v,u,v);
    }
}
int getlca(int x,int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]]) x = f[top[x]];
        else y = f[top[y]];
    }
    return dep[x] > dep[y] ? y : x;
}
bool check(int u,int fa,int d) {
    if (d == 0) return true;
    int cnt = 0;
    for (auto v : e[u]) {
        if (v == fa) continue;
        if (check(v,u,d-1)) {
            if (d == 2) ++cnt;
            else return true;
        }
        if (d == 2 && cnt == 3) return true;
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n >> p >> q;
        for (int i = 1; i <= n; i++) e[i].clear(),deg[i] = 0,dep[i] = 0;
        for (int i = 1; i < n; i++) {
            int u,v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            ++deg[u],++deg[v];
        }
        dfs1(1,0);
        dfs2(1,0,1);
        // for (int i = 1; i <= n; i++) {
        //     cout << dep[i] << '\n';
        // }    
        // cout << getlca(10,8) << '\n';
        bool f = false;
        for (int i = 1; i <= n; i++) {
            if (deg[i] >= 3) {
                int lcap = getlca(p,i);
                int lcaq = getlca(q,i);
                int disp = dep[p]+dep[i]-2*dep[lcap];
                int disq = dep[q]+dep[i]-2*dep[lcaq];
                if (disq + 2 <= disp) {
                    if (check(i,0,2)) {
                        f = true;break;
                    }
                }
            }
        }
        if (f) puts("Drifty");
        else puts("hgcnxn");
    }
    return 0;
}