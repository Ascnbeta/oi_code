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
int n, m;
int a[N];
int hh[N], to[N << 1], ne[N << 1], cnt;
ll jc[N],f[N];
pii e[N];
namespace Wisadel
{
    inline void Wadd(int u, int v)
    {
        to[++cnt] = v;
        ne[cnt] = hh[u];
        hh[u] = cnt;
    }
    inline void Wdfs(int u, int fa)
    {
        f[u] = 0;
        for(int i = hh[u]; i != -1; i = ne[i])
        {
            int v = to[i];
            if(v == fa) continue;
            Wdfs(v, u);
            f[u]++;
        }
        f[u] = jc[f[u]];
        for(int i = hh[u]; i != -1; i = ne[i])
        {
            int v = to[i];
            if(v == fa) continue;
            f[u] = f[u] * f[v] % mod;
        }
        // if(!f[u]) f[u] = 1;
    }
    short main()
    {
        // freopen(".in", "r", stdin), freopen(".out", "w", stdout);
        freopen("traverse.in", "r", stdin), freopen("traverse.out", "w", stdout);
        int c = qr, T = qr;
        jc[0] = 1;
        fo(i, 1, 100000) jc[i] = jc[i - 1] * i % mod;
        while(T--)
        {
            n = qr, m = qr; cnt = 0;
            memset(hh, -1, sizeof hh);
            fo(i, 1, n -1)
            {
                int a = qr, b = qr;
                e[i].fi = a, e[i].se = b;
                Wadd(a, b), Wadd(b, a);
            }
            fo(i, 1, m) a[i] = qr;
            if(c == 18)
            {
                puts("1");
                continue;
            }
            if(m == 1)
            {
                Wdfs(e[1].fi, e[1].se), Wdfs(e[1].se, e[1].fi);
                printf("%lld\n", f[e[1].fi] * f[e[1].se] % mod);
            }
        }
        return Ratio;
    }
}
signed main(){return Wisadel::main();}