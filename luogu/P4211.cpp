#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+4;
const int maxm = 5e4+5;
int n,m;
vector<int> e[maxn];
int dep[maxn],siz[maxn],son[maxn];
inline void dfs1(int u,int fa) {
    siz[u] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
int top[maxn],dfn[maxn],idx[maxn],cnt;
inline void dfs2(int u,int fa,int p) {
    dfn[u] = ++cnt;
    idx[cnt] = u;
    top[u] = p;
    if (son[u]) dfs2(son[u],u,p);
    for (auto v : e[u]) {
        if (v == fa || v == son[u]) continue;
        dfs2(v,u,v);
    }
}
struct ask{
    int l,r,z,id;
}q[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int x;cin >> x;
        ++x;
        e[x].push_back(i),e[i].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r >> q[i].z;
        q[i].id = i;
    }
    return 0;
}