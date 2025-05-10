#include <bits/stdc++.h>
using namespace std;
const int maxn = 54;
const int maxm = 124;
const int mod = 45989;
int n,m,t,a,b;
struct edge{
    int u,v;
}e[maxm];
int tot = 1,ans = 0;
vector<int> out_edge[maxn];
struct matrix{
    int l,r,a[maxm][maxm];
    // matrix(){memset(a,0,sizeof(a));}
    void reset() {
        for (int i = 1; i <= l; i++) a[i][i] = 1;
    }
    matrix operator * (const matrix &y) {
        matrix c;c.l = l,c.r = r;

        assert(r==y.l);
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= r; j++) {
                for (int k = 1; k <= r; k++) {
                    c.a[i][j] += a[i][k]*y.a[k][j]%mod;
                    c.a[i][j] %= mod;
                }
            }
        }
        return c;
    }
}mat;
inline matrix binpow(matrix base,int b1) {
    matrix ret;ret.l = base.l,ret.r = base.r;

    ret.reset();
    while (b1) {
        if (b1&1) ret = ret * base;
        base = base * base;
        b1 >>= 1;
    }
    return ret;
}
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> t >> a >> b;
    ++a,++b;
    if (t == 0) {
        if (a == b) cout << 1 << '\n';
        else cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        ++u,++v;
        e[++tot].u = u,e[tot].v = v;
        out_edge[u].push_back(tot);
        e[++tot].u = v,e[tot].v = u;
        out_edge[v].push_back(tot);
    }
    mat.l = tot,mat.r = tot;
    for (int i = 2; i <= tot; i++) {
        int v = e[i].v;
        for (int j : out_edge[v]) {
            if (j != (i^1)) mat.a[i][j]++;
        }
    }
    matrix tmp; tmp.l = 1,tmp.r = tot;

    for (int i : out_edge[a]) {
        tmp.a[1][i]++;
    }    

    matrix ed;
    ed = tmp*(binpow(mat,t-1));

    for (int i = 2; i <= tot; i++) {
        if (e[i].v == b) {
            ans += ed.a[1][i];
            ans %= mod;
        }
    }
    cout << ans << '\n';
    return 0;
}