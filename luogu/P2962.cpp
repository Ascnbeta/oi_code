#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m;
ll e[40];int ans = 0x3f3f3f3f;
map<ll,int> mp;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        e[u] |= (1ll<<(v-1)),e[v] |= (1ll<<(u-1));
    }
    for (int i = 1; i <= n; i++) e[i] |= (1ll<<(i-1));
    for (ll i = 0; i < (1ll<<(n>>1)); i++) {
        ll tmp = 0;int cnt = 0;
        for (ll j = 1; j <= (n>>1); j++) {
            if (i>>(j-1)&1ll) tmp ^= e[j],++cnt;
        }
        if (!mp.count(tmp)) mp[tmp] = cnt;
        else mp[tmp] = min(mp[tmp],cnt);
    }
    for (ll i = 0; i < (1ll<<(n-(n>>1))); i++) {
        ll tmp = 0;int cnt = 0;
        for (ll j = 1; j <= (n-(n>>1)); j++) {
            if (i>>(j-1)&1ll) tmp ^= e[j+(n>>1)],++cnt;
        }
        if (mp.count(((1ll<<n)-1)^tmp)) {
            ans = min(ans,mp[((1ll<<n)-1)^tmp]+cnt);
        }
    }
    cout << ans << '\n';
    return 0;
}