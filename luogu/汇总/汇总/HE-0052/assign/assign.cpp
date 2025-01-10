#include<bits/stdc++.h>
#define fo(x, y, z) for(int (x) = (y); (x) <= (z); (x)++)
#define fu(x, y, z) for(int (x) = (y); (x) >= (z); (x)--)
using namespace std;
typedef long long ll;
#define lx ll
inline lx qr()
{
    char ch = getchar(); lx x = 0, f = 1;
    for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    return x * f;
}
#undef lx
#define qr qr()
#define fi first
#define se second
#define pii pair<int, int>
const int Ratio = 0;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, m, v;
pii d[N];
namespace Wisadel
{
    inline ll Wqp(ll x, int y)
    {
        ll res = 1;
        while(y){if(y & 1) res = res * x % mod; x = x * x % mod; y >>= 1;}
        return res;
    }
    short main()
    {
        // freopen(".in", "r", stdin), freopen(".out", "w", stdout);
        freopen("assign.in", "r", stdin), freopen("assign.out", "w", stdout);
        int T = qr;
        while(T--)
        {
            n = qr, m = qr, v = qr;
            fo(i, 1, m) d[i].fi = qr, d[i].se = qr;
            sort(d + 1, d + 1 + m, [](pii A, pii B){return A.fi == B.fi ? A.se < B.se : A.fi < B.fi;});
            ll ans = Wqp(Wqp(v, 2), d[1].fi - 1);
            fo(i, 1, m - 1)
            {
                if(d[i].fi == d[i + 1].fi)
                {
                    if(d[i].se != d[i + 1].se)
                    {
                        ans = 0;
                        break;
                    }
                }
                else
                {
                    ll zc = Wqp(Wqp(v, 2), d[i + 1].fi - d[i].fi);
                    zc = (zc - Wqp(v, d[i + 1].fi - d[i].fi - 1) * (v -1) % mod + mod) % mod;
                    ans = ans * zc % mod;
                }
            }
            if(!ans) puts("0");
            else
            {
                ans = ans * Wqp(Wqp(v, 2), n - d[m].fi) % mod;
                printf("%lld\n", ans);
            }
        }
        return Ratio;
    }
}
signed main(){return Wisadel::main();}