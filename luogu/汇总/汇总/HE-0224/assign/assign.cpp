#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

inline long long read()
{
    long long f = 1, x = 0;
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

struct Conditions
{
    long long c, d;
    bool operator < (const Conditions &b) const
    {
        if (c == b.c) return d < b.d;
        return c < b.c;
    }
};

const int MR = 1e5 + 10;
const long long mod = 1e9 + 7;
long long n, m, v;
Conditions con[MR];

long long quick_power(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}
/*
int ord[15];
int ch[15];
long long ans = 0;

void dfs(int x, int c[])
{
    bool f1 = false;
    for (int i = 1; i <= v; i ++)
    {
        if (ord[x] && i != ord[x]) c[i] = 0;
        if (c[i] == 1) f1 = true;
    }
    if (!f1) return;
    if (x == n)
    {
        ans ++;
        if (ans >= mod) ans -= mod;
        return;
    }
    int b[15];
    for (int i = 1; i <= v; i ++)
    {
        b[i] = 0;
    }
    for (int i = 1; i <= v; i ++)
    {
        for (int j = 1; j <= v; j ++)
        {
            if (c[i] == 1) b[j] = 1;
            bool flag = false;
            for (int k = 1; k <= v; k ++)
            {
                if (k != i && c[k] == 1)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                for (int k = 1; k <= v; k ++)
                {
                    b[k] = 1;
                }
            }
            dfs(x + 1, b);
        }
    }
}

void work1()
{
    memset(ord, 0, sizeof(ord));
    for (int i = 1; i <= m; i ++)
    {
        ord[con[i].c] = con[i].d;
    }
    ans = 0;
    for (int i = 1; i <= v; i ++)
    {
        ch[i] = 1;
    }
    dfs(1, ch);
    printf("%lld\n", ans);
}
*/
int main()
{
    freopen("assign.in", "r", stdin);
    freopen("assign.out", "w", stdout);
    int T = read();
    while (T --)
    {
        n = read();
        m = read();
        v = read();
        con[0].c = con[m + 1].c = -1;
        for (int i = 1; i <= m; i ++)
        {
            con[i].c = read();
            con[i].d = read();
        }
        sort(con + 1, con + m + 1);
        long long prev = -1, val = -1;
        bool flag = true;
        for (int i = 1; i <= m; i ++)
        {
            if (con[i].c != con[i - 1].c)
            {
                prev = con[i].c;
                val = con[i].d;
            }
            if (con[i].c != con[i + 1].c)
            {
                if (con[i].d != val)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag)
        {
            puts("0");
            continue;
        }
        /*if (n <= 12 && m <= 12)
        {
            work1();
            continue;
        }*/
        long long ans = 1;
        long long now, times;
        now = v * v;
        now %= mod;
        times = con[1].c - 1;
        ans *= quick_power(now, times);
        ans %= mod;
        for (int i = 2; i <= m; i ++)
        {
            if (con[i].c == con[i - 1].c + 1)
            {
                now = v * v - (v - 1);
                now %= mod;
                times = 1;
                ans *= quick_power(now, times);
                ans %= mod;
            }
            else if (con[i].c != con[i - 1].c)
            {
                now = v * v;
                now %= mod;
                times = con[i].c - con[i - 1].c;
                ans *= quick_power(now, times);
                ans %= mod;
            }
        }
        now = v * v;
        now %= mod;
        times = n - con[m].c;
        ans *= quick_power(now, times);
        ans %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}
