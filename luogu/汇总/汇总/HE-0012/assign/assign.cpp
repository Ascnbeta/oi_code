#include <map>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

const ll mod = 1000000007;

ll T, n, m, V;

map <ll, ll> val;

ll Pow(ll x, ll y)
{
    ll r = 1;
    for(; y; y >>= 1, x = x * x % mod)
        if(y & 1)
            r = r * x % mod;
    return r;
}

void work()
{
    bool flag = 1;
    val.clear();

    scanf("%lld%lld%lld", &n, &m, &V);
    for(ll i = 1, x, y; i <= m; ++ i)
    {
        scanf("%lld%lld", &x, &y);
        if(val[x] && val[x] != y)
            flag = 0;
        val[x] = y;
    }

    if(!flag)
        return printf("0\n"), void();

    ll las = 0, ans = 1;
    for(auto x : val)
    {
        ll u = x.first, v = x.second;
        if(!las)
        {
            ans = ans * Pow(V, 2 * (u - 1)) % mod;
            las = u;
        }
        else if(u == las + 1)
            ans = ans * (V * V % mod - (V - 1)) % mod, las = u;
        else
            ans = ans * (Pow(V, 2 * (u - las)) - (V - 1) * Pow(V, u - las - 1) % mod) % mod, las = u;
    }
    if(las != n)
        ans = ans * Pow(V, 2 * (n - las)) % mod;

    printf("%lld\n", (ans % mod + mod) % mod);
}

int main()
{
    freopen("assign.in", "r", stdin);
    freopen("assign.out", "w", stdout);

    scanf("%lld", &T);
    while(T --)
        work();

    return 0;
}