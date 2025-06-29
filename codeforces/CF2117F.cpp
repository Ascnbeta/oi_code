#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e5+30;
const ll mod = 1e9+7;
int T;int n;
vector<int> e[maxn];int deg[maxn],cnt,cnt1;
inline ll binpow(ll base,int b) {
    ll ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}
ll ans = 0;bool f = true;int dep[maxn];
int dfs2(int u,int fa) {
    dep[u] = dep[fa] + 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        return dfs2(v,u);
    }
    return dep[u];
}
void dfs(int u,int fa) {
    if (f) ++cnt;
    if (deg[u] == 3) {
        f = false,ans = binpow(2,cnt);
        int tot = 0,a,b;
        dep[u] = 0;
        for (auto v : e[u]) {
            if (v == fa) continue;
            int tmp = dfs2(v,u);
            ++tot;
            if (tot == 1) {
                a = tmp;
            }else if(tot == 2){
                b = tmp;
            }else{
                assert(0);
            }
        }
        if (a == b) {
            ans = ans*2%mod;return;
        }
        if (a > b) swap(a,b);
        ans = ans*((binpow(2,(b-a-1))+binpow(2,(b-a)))%mod)%mod;
        return;
    }else{
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v,u);
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n;ans = cnt = cnt1 = 0;
        for (int i = 1; i <= n; i++) e[i].clear(),deg[i] = 0,dep[i] = 0;
        for (int i = 1; i < n; i++) {
            int u,v;
            cin >> u >> v;
            e[u].push_back(v),e[v].push_back(u);
            ++deg[u],++deg[v];
            if (deg[u] == 3) ++cnt;
            if (deg[v] == 3) ++cnt;
        }
        for (int i = 2; i <= n; i++) if (deg[i] == 1) ++cnt1;
        if (cnt > 1 || cnt1 > 2) {
            puts("0");
        }else if(cnt == 0 && deg[1] != 2) {
            printf("%lld\n",binpow(2,n));
        }else{
            cnt = 0;
            f = true;
            if (deg[1] == 2) deg[1] = 3;
            dfs(1,0);
            printf("%lld\n",ans);
        }
        
    }
    return 0;
}