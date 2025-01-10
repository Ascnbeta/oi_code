#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

inline int read()
{
    int f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return f * x;
}

const int NR = 5e5 + 10;
int dep[NR], f[NR][20];
bool line;

struct edge
{
    int nxt, to;
}e[NR * 2];

int head[NR], cnt;

void add(int x, int y)
{
    e[++cnt].nxt = head[x];
    e[cnt].to = y;
    head[x] = cnt;
}

void dfs(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    f[x][0] = fa;
    for (int i = 1; (1 << i) <= dep[x]; i ++)
    {
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    int cnt = 0;
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int y = e[i].to;
        if (y == fa) continue;
        cnt ++;
        dfs(y, x);
    }
    if (cnt > 1) line = false;
}

int lca(int x, int y)
{
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i --)
    {
        if ((1 << i) <= dep[x] - dep[y])
        {
            x = f[x][i];
        }
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i --)
    {
        if (f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int st[NR][20];
int lg[NR];

int query(int l, int r)
{
    int t = lg[r - l + 1];
    return lca(st[l][t], st[r - (1 << t) + 1][t]);
}

void work_line()
{
    int q = read();
    while (q --)
    {
        int l = read(), r = read(), k = read();
    }
}

int main()
{
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    int n = read();
    for (int i = 1; i < n; i ++)
    {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    line = true;
    dfs(1, 0);
    if (line && false)
    {
        work_line();
        return 0;
    }
    for (int i = 1; i <= n; i ++)
    {
        st[i][0] = i;
    }
    lg[1] = 0;
    for (int i = 2; i <= n; i ++)
    {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int j = 1; (1 << j) <= n; j ++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i ++)
        {
            st[i][j] = lca(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    int q = read();
    while (q --)
    {
        int l = read(), r = read(), k = read();
        int ans = 0;
        for (int i = l; i <= r; i ++)
        {
            if (i + k - 1 > r) break;
            int j = i + k - 1;
            int x = query(i, j);
            ans = max(ans, dep[x]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
