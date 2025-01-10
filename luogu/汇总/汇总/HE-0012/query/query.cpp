#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000005;

int n, m, cnt, p[N], id[N], siz[N], dep[N], Max[N][20], Min[N][20], f[N][21];

vector <int> e[N];

void dfs(int u, int fa)
{
    siz[u] = 1;
    dep[u] = dep[fa] + 1;
    p[id[u] = ++ cnt] = u;
    for(int v : e[u])
        if(v != fa)
            dfs(v, u), p[++ cnt] = u, siz[u] += siz[v];
}

int get(int l, int r)
{
    int len = __lg(r - l + 1);
    int x = min(Min[l][len], Min[r - (1 << len) + 1][len]);
    int y = max(Max[l][len], Max[r - (1 << len) + 1][len]);
    len = __lg(y - x + 1);
    return min(f[x][len], f[y - (1 << len) + 1][len]);
}

int main()
{
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1, u, v; i < n; ++ i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; ++ i)
        Max[i][0] = Min[i][0] = id[i];
    for(int j = 1; j < 20; ++ j)
    {
        for(int i = 1; i + (1 << j) - 1 <= n; ++ i)
        {
            Max[i][j] = max(Max[i][j - 1], Max[i + (1 << j - 1)][j - 1]);
            Min[i][j] = min(Min[i][j - 1], Min[i + (1 << j - 1)][j - 1]);
        }
    }

    for(int i = 1; i <= cnt; ++ i)
        f[i][0] = dep[p[i]];
    for(int j = 1; j <= 20; ++ j)
        for(int i = 1; i + (1 << j) - 1 <= cnt; ++ i)
            f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);

    scanf("%d", &m);
    for(int i = 1, l, r, k; i <= m; ++ i)
    {
        scanf("%d%d%d", &l, &r, &k);
        int ans = 0;
        for(int x = l, y = l + k - 1; y <= r; ++ x, ++ y)
            ans = max(ans, get(x, y));
        printf("%d\n", ans);
    }

    return 0;
}