#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define file(x, y) freopen(#x".in", "r", stdin); freopen(#y".out", "w", stdout);
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const LL mod = 1e9 + 7;

template <typename T> T R(T &x) {
    x = 0; bool f = 0; char c = getchar(); while (!isdigit(c)) f = c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); return x = f ? -x : x;
}
template <typename T, typename... Tr> void R(T &x, Tr &...y) {R(x); R(y...);}

LL Pow(LL x, LL y, LL res = 1) {
    for (; y; y >>= 1, x = x * x % mod)
        if (y & 1) res = res * x % mod;
    return res;
}

LL fac[N];

int n, k;

namespace sol1 {
    int deg[N];
    void main() {
        memset(deg, 0, sizeof deg);
        assert(k == 1);
        rep(i, 1, n - 1) {
            int x, y; R(x, y);
            ++deg[x]; ++deg[y];
        }
        rep(i, 1, k) {
            int x; R(x);
        }
        LL ans = 1;
        rep(i, 1, n) {
            ans = ans * fac[deg[i] - 1] % mod;
        }
        printf("%lld\n", ans);
    }
}

namespace solA {
    void main() {
        rep(i, 1, n - 1) {
            int x, y; R(x, y);
        }
        rep(i, 1, k) {
            int x; R(x);
        }
        puts("1");
    }
}

namespace solB {
    void main() {
        rep(i, 1, n - 1) {
            int x, y; R(x, y);
        }
        rep(i, 1, k) {
            int x; R(x);
        }
        LL ans = 0;
        rep(i, 1, k) {
            ans = (ans + fac[n - 2]) % mod;
            if (i > 1) ans = (ans - (i - 1) * (fac[n - 3]) % mod + mod) % mod;
        }
        printf("%lld\n", ans);
    }
}

namespace sol2 {
    struct Edges {int x, y;} edg[N];

    struct Edge {int y, nxt;} e[N << 1]; int ly[N], ltp;
    void add(int x, int y) {e[++ltp] = {y, ly[x]}; ly[x] = ltp;}
    int fa[N], siz[N], son[N], dep[N], top[N];
    void dfs1(int x) {
        siz[x] = 1; son[x] = 0;
        for (int i = ly[x], y; y = e[i].y, i; i = e[i].nxt) {
            if (y == fa[x]) continue;
            fa[y] = x; dep[y] = dep[x] + 1;
            dfs1(y); siz[x] += siz[y];
            if (siz[y] > siz[son[x]]) son[x] = y;
        }
    }
    void dfs2(int x, int tp) {
        top[x] = tp;
        if (son[x]) dfs2(son[x], tp);
        for (int i = ly[x], y; y = e[i].y, i; i = e[i].nxt)
            if (y != fa[x] && y != son[x]) dfs2(y, y);
    }
    int Lca(int x, int y) {
        while (top[x] != top[y])
            dep[top[x]] > dep[top[y]] ? x = fa[top[x]] : y = fa[top[y]];
        return dep[x] < dep[y] ? x : y;
    }
    LL deg[N];
    int vip[N];
    void main() {
        if (k == 1) return sol1::main();
        assert(k == 2);
        memset(deg, 0, sizeof deg);
        memset(ly, 0, sizeof ly); ltp = 0;
        rep(i, 1, n - 1) {
            int x, y; R(x, y);
            add(x, y); add(y, x);
            ++deg[x]; ++deg[y];
            edg[i] = {x, y};
        }
        dfs1(1); dfs2(1, 1);
        rep(i, 1, n - 1) {
            if (dep[edg[i].x] > dep[edg[i].y]) swap(edg[i].x, edg[i].y);
        }
        LL Val = 1, ans = 0;
        rep(i, 1, n) Val = Val * fac[deg[i] - 1] % mod;
        ans = 2 * Val % mod;
        rep(i, 1, k) {
            R(vip[i]);
        }
        int lca = Lca(edg[vip[1]].y, edg[vip[2]].y);
        if (dep[edg[vip[1]].y] < dep[edg[vip[2]].y]) swap(vip[1], vip[2]);
        int u = edg[vip[1]].y;
        u = fa[u];
        while (u && dep[u] >= dep[lca])
            Val = Val * Pow(fac[deg[u] - 1], mod - 2) % mod * fac[deg[u] - 2] % mod,
            u = fa[u];
        u = edg[vip[2]].y;
        u = fa[u];
        while (u && dep[u] > dep[lca])
            Val = Val * Pow(fac[deg[u] - 1], mod - 2) % mod * fac[deg[u] - 2] % mod,
            u = fa[u];
        ans = (ans - Val + mod) % mod;
        printf("%lld\n", ans);
    }
}

int main() {
    file(traverse, traverse)

    fac[0] = 1;
    rep(i, 1, 1e5) fac[i] = fac[i - 1] * i % mod;
    int c, T; R(c, T); while (T--) {
        R(n, k);
        if (1 <= c && c <= 6) sol1::main();
        else if (c == 18) solA::main();
        else if (19 <= c && c <= 21) solB::main();
        else if (7 <= c && c <= 10) sol2::main();
    }
    return 0;
}