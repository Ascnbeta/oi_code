// g++ traverse.cpp -o traverse -O2 -std=c++14 -static
#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e5 + 1;

int t;
int n, k;
std::vector<int> G[N];

struct edge
{
    int u, v;
} e[N];

int ek[N];

int size[N], fa[N];

ll qpow(ll x, int y)
{
    ll res = 1;
    while (y)
    {
if (y & 1)
(res *= x) %=mod;
(x *= x) %= mod;
    }
    return res;
}

int main()
{
    freopen("traverse.in", "r", stdin);
    freopen("traverse.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1, u, v; i < n; ++i)
            scanf("%d%d", &e[i].u, &e[i].v);
        for (int i = 1; i <= k; ++i)
            scanf("%d", &ek[i]);
        printf("%lld", qpow(2, k));
    }
    return 0;
}