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

const int NR = 1e5 + 10;
char s1[NR], s2[NR], t1[NR], t2[NR];
int b1[NR], c1, h1[NR][2];
int b2[NR], c2, h2[NR][2];
char r1[NR], r2[NR];

int main()
{
    freopen("edit.in", "r", stdin);
    freopen("edit.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T --)
    {
        int n = read();
        scanf("%s", s1 + 1);
        scanf("%s", s2 + 1);
        scanf("%s", t1 + 1);
        scanf("%s", t2 + 1);
        memset(h1, 0, sizeof(h1));
        memset(h2, 0, sizeof(h2));
        t1[0] = '0';
        t2[0] = '0';
        memset(b1, 0, sizeof(b1));
        memset(b2, 0, sizeof(b2));
        c1 = 0;
        c2 = 0;
        r1[0] = r2[0] = '2';
        for (int i = 1; i <= n; i ++)
        {
            r1[i] = '2';
            r2[i] = '2';
            if (t1[i] == '0') r1[i] = s1[i];
            if (t2[i] == '0') r2[i] = s2[i];
        }
        for (int i = 1; i <= n; i ++)
        {
            if (t1[i] == '1' && t1[i - 1] == '0')
            {
                c1 ++;
            }
            if (t1[i] == '1')
            {
                b1[i] = c1;
                h1[c1][s1[i] - '0'] ++;
            }
        }
        for (int i = 1; i <= n; i ++)
        {
            if (t2[i] == '1' && t2[i - 1] == '0')
            {
                c2 ++;
            }
            if (t2[i] == '1')
            {
                b2[i] = c2;
                h2[c2][s2[i] - '0'] ++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (t1[i] == '0' && t2[i] == '0')
            {
                if (r1[i] == r2[i]) ans ++;
            }
            else if (t1[i] == '0')
            {
                if (h2[b2[i]][r1[i] - '0'] > 0)
                {
                    r2[i] = r1[i];
                    ans ++;
                    h2[b2[i]][r1[i] - '0'] --;
                }
                else
                {
                    int num = (r1[i] - '0') ^ 1;
                    r2[i] = '0' + num;
                    h2[b2[i]][num] --;
                }
            }
        }
        for (int i = 1; i <= n; i ++)
        {
            if (t2[i] == '0')
            {
                if (h1[b1[i]][r2[i] - '0'] > 0)
                {
                    r1[i] = r2[i];
                    ans ++;
                    h1[b1[i]][r2[i] - '0'] --;
                }
                else
                {
                    int num = (r2[i] - '0') ^ 1;
                    r1[i] = '0' + num;
                    h1[b1[i]][num] --;
                }
            }
        }
        for (int i = 1; i <= n; i ++)
        {
            if (r1[i] != '2' || r2[i] != '2') continue;
            if (h1[b1[i]][0] > 0 && h2[b2[i]][0] > 0)
            {
                ans ++;
                r1[i] = '0';
                r2[i] = '0';
                h1[b1[i]][0] --;
                h2[b2[i]][0] --;
            }
            else if (h1[b1[i]][1] > 0 && h2[b2[i]][1] > 0)
            {
                ans ++;
                r1[i] = '1';
                r2[i] = '1';
                h1[b1[i]][1] --;
                h2[b2[i]][1] --;
            }
            else
            {
                if (h1[b1[i]][0] > 0)
                {
                    r1[i] = '0';
                    h1[b1[i]][0] --;
                }
                else
                {
                    r1[i] = '1';
                    h1[b1[i]][1] --;
                }
                if (h2[b2[i]][0] > 0)
                {
                    r2[i] = '0';
                    h2[b2[i]][0] --;
                }
                else
                {
                    r2[i] = '1';
                    h2[b2[i]][1] --;
                }
            }
        }
        /*printf("%s\n", r1 + 1);
        printf("%s\n", r2 + 1);*/
        printf("%d\n", ans);
    }
    return 0;
}
