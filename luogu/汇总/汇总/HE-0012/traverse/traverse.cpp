#include <map>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100005;

int ID, T, n, m, a[N], b[N];

namespace Sub1
{
    int ans, id, q[40], f[10][10];
    vector <int> e[50];
    vector < pair <int, int> > t;
    map < vector < pair <int, int> >, int > vis;

    void solve(int u)
    {
        q[u] = 1;
        for(int v : e[u])
            if(!q[v])
                t.push_back({min(u, v), max(u, v)}), solve(v);
    }

    void dfs(int x)
    {
        if(x > 35)
        {
            t.clear();
            memset(q, 0, sizeof(q));
            solve(id);
            if(!vis[t])
                vis[t] = 1, ++ ans;
            return;
        }
        do
        {
            dfs(x + 1);
        }
        while(next_permutation(e[x].begin(), e[x].end()));
    }

    void work()
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i < n; ++ i)
        {
            scanf("%d%d", &a[i], &b[i]);
            f[a[i]][b[i]] = f[b[i]][a[i]] = 1;
        }

        for(int u = 1; u <= n; ++ u)
        {
            for(int v = 1; v <= n; ++ v)
            {
                for(int w = 1; w <= n; ++ w)
                {
                    if(f[u][v] && f[u][w])
                    {
                        int x = min(u, v) * (n + 1) + max(u, v);
                        int y = min(u, w) * (n + 1) + max(u, w);
                        e[x].push_back(y);
                        e[y].push_back(x);
                    }
                }
            }
        }

        scanf("%d", &id);
        int x = a[id], y = b[id], z = min(x, y) * (n + 1) + max(x, y);
        id = z;

        dfs(1);

        vis.clear();
        for(int i = 1; i <= 36; ++ i)
            e[i].clear();
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= n; ++ j)
                f[i][j] = 0;
    }
}

int main()
{
     freopen("traverse.in", "r", stdin);
     freopen("traverse.out", "w", stdout);

    scanf("%d%d", &ID, &T);
    while(T --)
    {
        if(ID <= 3)
            Sub1::work();
    }

    return 0;
}
