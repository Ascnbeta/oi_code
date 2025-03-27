#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
int n;
vector<int> e[maxn];
int c[maxn],siz[maxn],son[maxn],ans[maxn],cnt[maxn],p,maxx,ret;
void kaito(int u,int fa) {
    siz[u] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        kaito(v,u);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
   }
}
void shirabe(int u,int fa,int val) {
    cnt[c[u]] += val;
    if (cnt[c[u]] > maxx) ret = c[u],maxx = cnt[c[u]];
    else if (cnt[c[u]] == maxx) ret += c[u];
    for (auto v : e[u]) {
        if (v == fa || v == p) continue;
        shirabe(v,u,val);
    }
}
void hikari(int u,int fa,int tp) {
    for (auto v : e[u]) {
        if (v == fa || v == son[u]) continue;
        hikari(v,u,v);
    }
    if (son[u]) hikari(son[u],u,tp),p = son[u];
    shirabe(u,fa,1);
    p = 0;
    ans[u] = ret;
    if (u == tp) shirabe(u,fa,-1),ret = maxx = 0;
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    kaito(1,0);
    hikari(1,0,1);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}