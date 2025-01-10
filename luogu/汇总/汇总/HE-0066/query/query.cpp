#include<bits/stdc++.h>
//#include<bits/extc++.h>
namespace {
using namespace std;
//using namespace __gnu_pbds;
#define fiin(x) freopen(x".in", "r", stdin)
#define fiout(x) freopen(x".out", "w", stdout)
#define file(x) fiin(x), fiout(x)
#define ll long long
#define db double
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
#define fir first
#define sec second
#define hap cc_hash_table
// #define 
const int man = 5e5+10, mam = 5e5+10, mop = 1e9+7;
class Graph {
public:
    int len, hed[man];
    int ver[mam<<1], nxt[mam<<1];
    void Ins (int u, int v) {
        ver[++len] = v;
        nxt[len] = hed[u];
        hed[u] = len;
        return void();
    } 
    void DIns (int u, int v) {
        return Ins(u, v), Ins(v, u);
    }
} G;
}

int n, mad, q;
int deg[man];
pii dep[man];
int req (int, int, int);
void dfs (int, int);
int main () {
    file("query");
    scanf("%d", &n);
    for (int u, v, i = 1; i < n; ++ i) {
        scanf("%d%d", &u, &v);
        G.DIns(u, v), ++ deg[u], ++ deg[v];
        mad = max(mad, max(deg[u], deg[v]));
    } scanf("%d", &q);
    dfs(1, 1);
    if (mad <= 2) {
        sort(dep+1, dep+n+1, greater<pii >());
        for (int l, r, k, i = 1; i <= q; ++ i) {
            scanf("%d%d%d", &l, &r, &k);
            while (dep[k].fir < l || r < dep[k].fir) ++ k;
            printf("%d\n", k);
        } 
    } else if (n <= 5000) {
        for (int l, r, k, i = 1; i <= q; ++ i) {
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", req(l, r, k));
        } 
    }
    return 0;
}

void dfs (int x, int d) {
    dep[x] = {d, x};
    for (int i = G.hed[x]; i; i = G.nxt[i]) {
        dfs(G.ver[i], d+1);
    } return void();
}

bool check (int l, int r, int k, int m) {
    return 1;
}

int req (int l1, int r1, int k) {
    int l = 1, r = mad, mid = (mad+1)>>1;
    while (l < r) {
        if (check(l1, r1, k, mid)) l = mid;
        else r = mid-1;
        mid = (l+r)>>1;
    } return mid;
}
