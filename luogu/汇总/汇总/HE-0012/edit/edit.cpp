#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;

int T, n, m, k, ans, p[2][N][2];
char a[N], b[N], s[N], t[N];

void work()
{
    scanf("%d", &n);
    scanf("%s%s", a + 1, b + 1);
    scanf("%s%s", s + 1, t + 1);

    ans = 0;
    m = k = 0;

    for(int i = 1; i <= n; ++ i)
        if(s[i] == '0' && t[i] == '0')
            ans += a[i] == b[i];
    int las = 0;
    for(int i = 1; i <= n; ++ i)
    {
        if(s[i] != '0')
            continue;
        if(i == las + 1)
        {
            las = i;
            continue;
        }
        ++ m;
        for(int j = las + 1; j < i; ++ j)
            p[0][m][a[j] - '0'] ++;
        for(int j = las + 1; j < i; ++ j)
        {
            if(t[j] != '0')
                continue;
            if(p[0][m][b[j] - '0'])
                p[0][m][b[j] - '0'] --, ans ++;
            else
                p[0][m][!(b[j] - '0')] --;
        }
        if(p[0][m][0] + p[0][m][1] == 0)
            -- m;
        las = i;
    }
    if(las != n)
    {
        ++ m;
        for(int j = las + 1; j <= n; ++ j)
            p[0][m][a[j] - '0'] ++;
        for(int j = las + 1; j <= n; ++ j)
        {
            if(t[j] != '0')
                continue;
            if(p[0][m][b[j] - '0'])
                p[0][m][b[j] - '0'] --, ans ++;
            else
                p[0][m][!(b[j] - '0')] --;
        }
        if(p[0][m][0] + p[0][m][1] == 0)
            -- m;
    }

    las = 0;
    for(int i = 1; i <= n; ++ i)
    {
        if(t[i] != '0')
            continue;
        if(i == las + 1)
        {
            las = i;
            continue;
        }
        ++ k;
        for(int j = las + 1; j < i; ++ j)
            p[1][k][b[j] - '0'] ++;
        for(int j = las + 1; j < i; ++ j)
        {
            if(s[j] != '0')
                continue;
            if(p[1][k][a[j] - '0'])
                p[1][k][a[j] - '0'] --, ans ++;
            else
                p[1][k][!(a[j] - '0')] --;
        }
        if(p[1][k][0] + p[1][k][1] == 0)
            -- k;
        las = i;
    }
    if(las != n)
    {
        ++ k;
        for(int j = las + 1; j <= n; ++ j)
            p[1][k][b[j] - '0'] ++;
        for(int j = las + 1; j <= n; ++ j)
        {
            if(s[j] != '0')
                continue;
            if(p[1][k][a[j] - '0'])
                p[1][k][a[j] - '0'] --, ans ++;
            else
                p[1][k][!(a[j] - '0')] --;
        }
        if(p[1][k][0] + p[1][k][1] == 0)
            -- k;
    }

    // printf("%d %d\n", m, k);
    // for(int i = 1; i <= m; ++ i)
    //     printf("%d %d\n", p[0][i][0], p[0][i][1]);
    // for(int i = 1; i <= k; ++ i)
    //     printf("%d %d\n", p[1][i][0], p[1][i][1]);

    int p1 = 1, p2 = 1, A, B;
    while(p1 <= m && p2 <= k)
    {
        if(p[0][p1][0] + p[0][p1][1] <= p[1][p2][0] + p[1][p2][1])
        {
            ans += min(p[0][p1][0], p[1][p2][0]) + min(p[0][p1][1], p[1][p2][1]);
            A = min(p[0][p1][0], p[1][p2][0]);
            B = min(p[0][p1][1], p[1][p2][1]);
            
            p[0][p1][0] -= A;
            p[1][p2][0] -= A;
            p[0][p1][1] -= B;
            p[1][p2][1] -= B;

            if(p[0][p1][0])
                p[1][p2][1] -= p[0][p1][0];
            if(p[0][p1][1])
                p[1][p2][0] -= p[0][p1][1]; 
            ++ p1;
        }
        else
        {
            ans += min(p[0][p1][0], p[1][p2][0]) + min(p[0][p1][1], p[1][p2][1]);
            A = min(p[0][p1][0], p[1][p2][0]);
            B = min(p[0][p1][1], p[1][p2][1]);
            
            p[0][p1][0] -= A;
            p[1][p2][0] -= A;
            p[0][p1][1] -= B;
            p[1][p2][1] -= B;

            if(p[1][p2][0])
                p[0][p1][1] -= p[1][p2][0];
            if(p[1][p2][1])
                p[0][p1][0] -= p[1][p2][1];
            ++ p2;
        }
    }

    printf("%d\n", ans);

    for(int i = 1; i <= m; ++ i)
        p[0][i][0] = p[0][i][1] = 0;
    for(int i = 1; i <= k; ++ i)
        p[1][i][0] = p[1][i][1] = 0;
}

int main()
{
    freopen("edit.in", "r", stdin);
    freopen("edit.out", "w", stdout);

    scanf("%d", &T);
    while(T --)
        work();

    return 0;
}