#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define file(x, y) freopen(#x".in", "r", stdin); freopen(#y".out", "w", stdout);
using namespace std;
const int N = 5e5 + 10;

template <typename T> T R(T &x) {
    x = 0; bool f = 0; char c = getchar(); while (!isdigit(c)) f = c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); return x = f ? -x : x;
}
template <typename T, typename... Tr> void R(T &x, Tr &...y) {R(x); R(y...);}

struct Edge {int y, nxt;} e[N << 1]; int ly[N], ltp;
void add(int x, int y) {e[++ltp] = {y, ly[x]}; ly[x] = ltp;}


int n, m;

struct QUERY{int l, r, k, id;} q[N];

int dep[N];
namespace HP {
    int fa[N], dfn[N], siz[N], son[N], top[N];
    void dfs1(int x) {
        siz[x] = 1;
        for (int i = ly[x], y; y = e[i].y, i; i = e[i].nxt) {
            if (y == fa[x]) continue;
            dep[y] = dep[x] + 1; fa[y] = x;
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
    void init() {dep[1] = 1; dfs1(1); dfs2(1, 1);}
}

bool sol1_flag;
namespace sol1 {
    int t[N << 2];
    #define mid (l + r >> 1)
    #define lrt (rt << 1)
    #define rrt (rt << 1 | 1)
    void build(int l = 1, int r = n, int rt = 1) {
        if (l == r) {t[rt] = l; return ;}
        build(l, mid, lrt); build(mid + 1, r, rrt);
        t[rt] = HP::Lca(t[lrt], t[rrt]);
    }
    int qry(int ll, int rr, int l = 1, int r = n, int rt = 1) {
        if (ll <= l && r <= rr) return t[rt];
        if (rr <= mid) return qry(ll, rr, l, mid, lrt);
        if (mid < ll) return qry(ll, rr, mid + 1, r, rrt);
        return HP::Lca(qry(ll, rr, l, mid, lrt), qry(ll, rr, mid + 1, r, rrt));
    }
    #undef mid
    #undef lrt
    #undef rrt
    void main() {
        build();
        rep(i, 1, m) {
            int ans = 0;
            rep(ll, q[i].l, q[i].r - q[i].k + 1) {
                int rr = ll + q[i].k - 1;
                ans = max(ans, dep[qry(ll, rr)]);
            }
            printf("%d\n", ans);
        }
    }
} // sol1

bool sol2_flag;
int deg[N];
namespace sol2 {
    struct Data {
        int sum, siz, mx, l, r;
        friend Data operator+(const Data &a, const Data &b) {
            Data c;
            c.sum = a.sum + b.sum;
            c.siz = a.siz + b.siz;
            c.mx = max({a.mx, b.mx, a.r + b.l});
            if (a.sum == a.siz) c.l = a.sum + b.l;
            else c.l = a.l;
            if (b.sum == b.siz) c.r = a.r + b.sum;
            else c.r = b.r;
            return c;
        }
    };
    Data t[N << 2];
    #define mid (l + r >> 1)
    #define lrt (rt << 1)
    #define rrt (rt << 1 | 1)
    void build(int l = 1, int r = n, int rt = 1) {
        if (l == r) {t[rt] = {0, 1, 0, 0, 0}; return ;}
        build(l, mid, lrt); build(mid + 1, r, rrt);
        t[rt] = t[lrt] + t[rrt];
    }
    void upd(int p, int v, int l = 1, int r = n, int rt = 1) {
        if (l == r) {t[rt] = {v, 1, v, v, v}; return ;}
        if (p <= mid) upd(p, v, l, mid, lrt);
        else upd(p, v, mid + 1, r, rrt);
        t[rt] = t[lrt] + t[rrt];
    }
    Data qry(int ll, int rr, int l = 1, int r = n, int rt = 1) {
        if (ll <= l && r <= rr) return t[rt];
        if (rr <= mid) return qry(ll, rr, l, mid, lrt);
        if (mid < ll) return qry(ll, rr, mid + 1, r, rrt);
        return qry(ll, rr, l, mid, lrt) + qry(ll, rr, mid + 1, r, rrt);
    }
    #undef mid
    #undef lrt
    #undef rrt

    int rnk[N];
    int ans[N];
    QUERY Temp[N];
    void solve(int l, int r, int ql, int qr) {
        if (l > r) return ; if (ql > qr) return ;
        int mid = l + r >> 1;
        per(i, r, mid) {
            upd(rnk[i], 1);
        }
        int j = ql, k = qr;
        rep(i, ql, qr) {
            if (qry(q[i].l, q[i].r).mx >= q[i].k)
                ans[q[i].id] = mid, Temp[k--] = q[i];
            else Temp[j++] = q[i];
        }
        rep(i, ql, qr) q[i] = Temp[i];
        solve(l, mid - 1, ql, j - 1);
        rep(i, mid, r) upd(rnk[i], 0);
        solve(mid + 1, r, k + 1, qr); 
    }
    void main() {
        rep(i, 1, n)
            rnk[dep[i]] = i;
        build();
        solve(1, n, 1, m);
        rep(i, 1, m)
            printf("%d\n", ans[i]);
    }
} // sol2

int main() {
    file(query, query);

    sol1_flag = 1;
    sol2_flag = 1;
    R(n);
    rep(i, 1, n - 1) {
        int x, y; R(x, y);
        add(x, y); add(y, x);
        ++deg[x]; ++deg[y];
    }
    rep(i, 1, n) if (deg[i] > 2) sol2_flag = 0;
    HP::init();
    R(m);
    rep(i, 1, m) {
        R(q[i].l, q[i].r, q[i].k); q[i].id = i;
        if (q[i].r - q[i].l + 1 != q[i].k) sol1_flag = 0;
    }
    if (n <= 5000 || sol1_flag)
        sol1::main();
    else if (sol2_flag)
        sol2::main();
    else sol1::main();
    return 0;
}
