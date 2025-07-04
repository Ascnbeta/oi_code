#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template <typename T>
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
const int maxn = 5e5+10;
const int maxm = 1e6+40;
const ll mod = 1e9+7;
int n,m;
vector<pair<int,int>> e[maxn];
int dfn[maxn],low[maxn],cnt;
bool cut[maxm],vis[maxm];
inline void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    for (auto i : e[u]) {
        int v = i.first,id = i.second;
        if (!dfn[v]) {
            vis[id] = true;
            tarjan(v);
            low[u] = min(low[u],low[v]);
            if (low[v] > dfn[u]) cut[id] = true;
        }else if(!vis[id]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
}
int ecc[maxn],siz[maxn],cnte[maxn];
bool visv[maxn];
inline void dfs(int u) {
    ecc[u] = cnt;visv[u] = true;
    ++siz[cnt];
    for (auto i : e[u]) {
        int v = i.first,id = i.second;
        if (cut[id]) continue;
        if (!vis[id]) ++cnte[cnt],vis[id] = true;
        if (visv[v]) continue;
        dfs(v);
    }
}
vector<int> e1[maxn];
ll f[maxn][2],ans;
ll s[maxn];
inline ll binpow(ll base,int b) {
    ll ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}
void dfs2(int u,int fa) {
    f[u][0] = binpow(2,cnte[u]);
    f[u][1] = (binpow(2,cnte[u]+siz[u])-f[u][0]+mod)%mod;
    s[u] = cnte[u];
    for (auto v : e1[u]) {
        if (v == fa) continue;
        dfs2(v,u);
        s[u] += s[v] + 1;
        f[u][1] = (f[u][0] * f[v][1] + f[u][1] * (2 * f[v][0] + f[v][1]) % mod) % mod;
        f[u][0] = f[u][0] * f[v][0] * 2 % mod;
    }
    if (u != 1) ans = (ans + f[u][1] * binpow(2,m-s[u]-1) % mod) % mod;
    else ans = (ans + f[1][1]) % mod;
}
// inline void calc(int u,int fa) {
//     for (auto v : e1[u]) {
//         if (v == fa) continue;
//         calc(v,u);
//     }
   
// }
int main() {
#ifdef LOCAL
    freopen("E:/OI/exe/a.in","r",stdin);
    freopen("E:/OI/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= m; i++) {
        int u,v;
        read(u),read(v);
        e[u].push_back({v,i});
        e[v].push_back({u,i});
    }
    tarjan(1);
    memset(vis,0,sizeof(vis));cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visv[i]) {
            ++cnt;
            dfs(i);
        }
    }
    for (int u = 1; u <= n; u++) {
        for (auto i : e[u]) {
            int v = i.first;
            if (ecc[u] == ecc[v]) continue;
            e1[ecc[u]].push_back(ecc[v]);
        }
    }
    dfs2(1,0);
    // calc(1,0);
    printf("%lld",ans);
    return 0;
}