#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+30;
const int mod = 1e9+9;
int T,n,a[maxn];
inline void read(int &v) {
    int x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    v = x*f;
    return;
}
vector<int> e[maxn];
bool vis[maxn];
int cnt = 0;
void dfs(int u) {
    ++cnt;
    vis[u] = true;
    for (auto v : e[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}
int num[maxn],tot;
ll ans = 1,jc[maxn],jc_inv[maxn];
inline ll binpow(ll base,ll b) {
    ll ret = 1;
    while (b) {
        if (b&1ll) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(T);
    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        jc[i] = jc[i-1] * i % mod;
        jc_inv[i] = binpow(jc[i],mod-2);
    }
    while (T--) {
        read(n);
        tot = 0;ans = 1;
        memset(vis,0,sizeof(vis));
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            e[i].push_back(a[i]);
            e[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            cnt = 0;
            if (!vis[i]) {
                dfs(i);
                num[++tot] = cnt;
                ans = ans * (cnt>=2?binpow(cnt,cnt-2):1) % mod;
            }
        }
        ans = ans * jc[n-tot] % mod;
        for (int i = 1; i <= tot; i++) {
            ans = ans * jc_inv[num[i]-1] % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}