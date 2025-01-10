#include <bits/stdc++.h>
#define int long long
using namespace std;
const double eps = 1e-8;
int T, n, m, L, V, ans1, ans2;
struct car
{
    int v, a, d;
} c[100005];
int p[100005];
struct zone
{
    int l, r;
} z[100005];
int tot = 0;
void solve1(int x)
{
    if (c[x].d > p[m])
        return;
    long double vi = sqrt(c[x].v * c[x].v + 2 * c[x].a * (p[m] - c[x].d));
    if (vi <= V)
        return;
    ++ans1;
    int l = 1, r = m;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (p[mid] >= c[x].d)
        {
            vi = sqrt(c[x].v * c[x].v + 2 * c[x].a * (p[mid] - c[x].d));
            if (vi > V)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            l = mid + 1;
        }
    }

    z[++tot].l = r, z[tot].r = m;
    // cout << x << ' ' << z[tot].l << ' ' << z[tot].r << '\n';
}
void solve2(int x)
{
    if (c[x].d > p[m])
        return;
    int l = 1, r = m;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (p[mid] >= c[x].d)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }//找区间左端点
    if (c[x].v * c[x].v + 2 * c[x].a * (p[l] - c[x].d) < 0) return;
    long double vi = sqrt(c[x].v * c[x].v + 2 * c[x].a * (p[l] - c[x].d));
    if (vi <= V)
        return;
    ++ans1;
    z[++tot].l = l;
    r = m;
    long double s = 1.0 * (V * V - c[x].v * c[x].v) / (2 * c[x].a) + c[x].d;
    r = lower_bound(p+l,p+r+1,s) - p - 1;//区间右端点
    if (r < l) r = l;
    z[tot].r = r;
    // cout << x << ' ' << z[tot].l << ' ' << z[tot].r << '\n';
}// a < 0
bool cmp(zone x, zone y)
{
    if (x.r == y.r)
        return x.l < y.l;
    return x.r < y.r;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);
    //freopen("detect2.in","r",stdin);
    //freopen("detect.out","w",stdout);
    cin >> T;
    while (T--)
    {
        tot = 0, ans1 = 0, ans2 = 0;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i].d >> c[i].v >> c[i].a;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (c[i].a == 0)
            {
                if (c[i].v > V && c[i].d <= p[m])
                {
                    ++ans1;
                    int l = 1, r = m;
                    while (l < r)
                    {
                        int mid = l + (r - l) / 2;
                        if (p[mid] >= c[i].d)
                        {
                            r = mid;
                        }
                        else
                        {
                            l = mid + 1;
                        }
                    }
                    z[++tot].l = l, z[tot].r = m;
                    // cout << i << ' ' << z[tot].l << ' ' << z[tot].r << '\n';
                }
            }
            else if (c[i].a > 0)
            {
                solve1(i);
            }
            else
            {
                solve2(i);
            }
        }
        cout << ans1 << ' ';
        if (ans1 == 0)
        {
            cout << m << '\n';
            continue;
        }
        sort(z + 1, z + tot + 1, cmp);
        ans2 = 1;
        int tmp = z[1].r;
        for (int i = 2; i <= tot; i++)
        {
            if (z[i].l > tmp)
            {
                ++ans2;
                tmp = z[i].r;
            }
        }
        cout << m - ans2 << '\n';
    }
    return 0;
}