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
const int N = 5e5 + 5;
const int mod = 1e9 + 7;
int n, q;
int hh[N], to[N << 1], ne[N << 1], cnt;
int dep[N], rd[N];
namespace Wtask
{
    int wt[N];
    inline void Wdfs(int u, int fa)
    {
        dep[u] = dep[fa] + 1; wt[u] = dep[u];
        for(int i = hh[u]; i != -1; i = ne[i])
        {
            int v = to[i];
            if(v == fa) continue;
            Wdfs(v, u);
        }
    }
    int minn[N << 2];
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    #define mid ((l + r) >> 1)
    inline void Wpushup(int rt){minn[rt] = min(minn[ls], minn[rs]);}
    inline void Wbuild(int rt, int l, int r)
    {
        if(l == r)
        {
            minn[rt] = wt[l];
            return ;
        }
        Wbuild(ls, l, mid), Wbuild(rs, mid + 1, r);
        Wpushup(rt);
    }
    inline int Wq(int rt, int l, int r, int x, int y)
    {
        if(x <= l && r <= y) return minn[rt];
        int res = 1e9;
        if(x <= mid) res = Wq(ls, l, mid, x, y);
        if(y > mid) res = min(res, Wq(rs, mid + 1, r, x, y));
        return res;
    }
    short main()
    {
        Wdfs(1, 0);
        Wbuild(1, 1, n);
        q = qr;
        fo(i, 1, q)
        {
            int l = qr, r = qr, k = qr;
            printf("%d\n", Wq(1, 1, n, l, r));
        }
        return Ratio;
    }
}
namespace Wisadel
{
    inline void Wadd(int u, int v)
    {
        to[++cnt] = v;
        ne[cnt] = hh[u];
        hh[u] = cnt;
    }
    int lg[N], st[30][N];
    int dfn[N], dt;
    inline int Wget(int u, int v){return dfn[u] <dfn[v] ? u : v;}
    inline void Wdfs(int u, int fa)
    {
        dfn[u] = ++dt; st[0][dt] = fa; dep[u] = dep[fa] + 1;
        for(int i = hh[u]; i != -1; i = ne[i])
        {
            int v = to[i];
            if(v == fa) continue;
            Wdfs(v, u);
        }
    }
    inline int Wlca(int u, int v)
    {
        if(u == v) return u;
        if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
        int d = lg[v - u++];
        return Wget(st[d][u], st[d][v - (1 << d) + 1]);
    }
    int t[N << 2];
    inline void Wpushup(int rt){t[rt] = Wlca(t[ls], t[rs]);}
    inline void Wbuild(int rt, int l, int r)
    {
        if(l == r)
        {
            t[rt] = l;
            return ;
        }
        Wbuild(ls, l,mid), Wbuild(rs, mid + 1,r);
        Wpushup(rt);
    }
    inline int Wq(int rt, int l, int r, int x, int y)
    {
        if(x <= l && r <= y) return t[rt];
        int zc = -1;
        if(x <= mid) zc = Wq(ls, l,mid, x, y);
        if(y > mid)
        {
            if(zc == -1) zc =Wq(rs, mid + 1, r, x, y);
            else zc = Wlca(zc, Wq(rs, mid + 1,r,x, y));
        }
        return zc;
    }
    short main()
    {
        // freopen(".in", "r", stdin), freopen(".out", "w", stdout);
        freopen("query.in", "r", stdin), freopen("query.out", "w", stdout);
        n =qr;
        memset(hh, -1, sizeof hh);
        bool task = 1;
        fo(i,1, n - 1)
        {
            int a = qr, b = qr;
            rd[a]++, rd[b]++;
            if(rd[a]>2 || rd[b] > 2) task = 0;
            Wadd(a, b), Wadd(b,a);
        }
        if(task) return Wtask::main();
        Wdfs(1, 0);
        fo(i, 2, n) lg[i] = lg[i >> 1] + 1;
        fo(i, 1, lg[n]) fo(j, 1, n - (1 << i) + 1)
            st[i][j] = Wget(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        Wbuild(1, 1, n);
        q = qr;
        fo(i, 1, q)
        {
            int l = qr, r = qr, k = qr;
            int ans = 0;
            fo(L, l, r - k + 1)
            {
                int R = L + k - 1;
                int lca = Wq(1, 1, n, L, R);
                if(dep[lca] > ans) ans = dep[lca];
            }
            printf("%d\n", ans);
        }
        return Ratio;
    }
}
signed main(){return Wisadel::main();}