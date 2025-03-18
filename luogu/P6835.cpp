#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+30;
const int mod = 998244353;
int id,n,m;
vector<int> e[maxn];
int f[maxn],oud[maxn],sum[maxn];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> id >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        oud[u]++;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = oud[i]+1;
        for (auto v : e[i]) {
            f[i] = (((f[i] + sum[i-1]) % mod - sum[v-1]) % mod + mod) % mod;
        }
        sum[i] = (sum[i-1] + f[i]) % mod;
    }
    cout << sum[n] << '\n'; 
    return 0;
}