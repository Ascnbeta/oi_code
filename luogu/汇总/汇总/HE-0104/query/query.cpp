// g++ query.cpp -o query -O2 -std=c++14 -static
#include <bits/stdc++.h>

typedef long long ll;

const ll N = 5e5 + 10;

ll n, q;

std::vector<ll> G[N];

ll dep[N][21], size[N], fa[N], son[N];

void GetSon(ll u)
{
    dep[u][0] = dep[fa[u]][0] + 1;
    size[u] = 1;
    for (auto v : G[u])
    {
        if (v == fa[u])
            continue;
        fa[v] = u;
        GetSon(v);
        size[u] += size[v];
        if (size[son[u]] < size[v])
            son[u] = v;
    }
}

ll dfn[N], pos[N], top[N];

void GetTop(ll u, ll tp)
{
    dfn[u] = ++dfn[0];
    pos[dfn[u]] = u;
    top[u] = tp;
    if (son[u])
        GetTop(son[u], tp);
    for (auto v : G[u])
    {
        if (v == fa[u] || v == son[u])
            continue;
        GetTop(v, v);
    }
}

ll LCA(ll u, ll v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        std::swap(u, v);
    return u;
}

ll lca[N][21];

void GetST()
{
    for (ll j = 1; (1 << j) <= n; ++j)
        for (ll i = 1; i + (1 << j) - 1 <= n; ++i)
            dep[i][j] = std::min(dep[i][j - 1], dep[i + (1 << (j - 1))][j - 1]);
}

ll query(ll l, ll r)
{
    ll k = log2(r - l + 1);
    return std::min(dep[l][k], dep[r - (1 << k) + 1][k]);
}

int main()
{
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1, u, v; i < n; ++i)
        scanf("%lld%lld", &u, &v), G[u].push_back(v), G[v].push_back(u);
    fa[1] = 1;
    GetSon(1);
    GetTop(1, 1);
    GetST();
    scanf("%lld", &q);
    while (q--)
    {
        ll l, r, k;
        ll ans = 0;
        scanf("%lld%lld%lld", &l, &r, &k);
        for (ll i = l; i + k - 1 <= r; ++i)
            ans = std::max(ans, query(i, i + k - 1));
        printf("%lld\n", ans);
    }
    return 0;
}