// g++ assign.cpp -o assign -O2 -std=c++14 -static
#include <bits/stdc++.h>

typedef long long ll;

const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int T;
ll n, m, v;
bool flag;
ll c[N], d[N];
std::map<ll, ll> x;
ll ans;

int main()
{
    freopen("assign.in", "r", stdin);
    freopen("assign.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        flag = false;
        x.clear();
        ans = 1;
        scanf("%lld%lld%lld", &n, &m, &v);
        for (int i = 1; i <= m; ++i)
        {    
            scanf("%lld%lld", &c[i], &d[i]);
            if (x.count(c[i]) && x[c[i]] != d[i])
                flag = true;
            x[c[i]] = d[i];
        }
        if (flag)
        {
            printf("0\n");
            continue;
        }
        for (int i = 1; i < n; ++i)
        {
            if (x.count(i) && x.count(i + 1))
                ++(ans *= (v - 1) * v % mod) %= mod;
            else
                (ans *= v * v % mod) %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}