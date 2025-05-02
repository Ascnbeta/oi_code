#include <bits/stdc++.h>
using namespace std;
const int maxn = 54;
const int maxm = 124;
int n,m,t,a,b;
struct edge{
    int u,v;
}e[maxm];
int tot = 1;
vector<int> out_edge[maxn],e1[maxn];
struct matrix{
    int l,r,a[maxm][maxm];
    void reset() {
        for (int i = 1; i <= l; i++) a[i][i] = 1;
    }
}mat;
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> t >> a >> b;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        ++u,++v;
        e1[u].push_back(v);
        e1[v].push_back(u);
        e[++tot].u = u,e[tot].v = v;
        e[++tot].u = v,e[tot].v = u;
        out_edge[u].push_back(tot^1);
        out_edge[v].push_back(tot);
    }
    mat.l = 2*m,mat.r = 2*m;
    for (int i = 2; i <= tot; i++) {
        int u = e[i].u,v = e[i].v;
        for (int j : out_edge[v]) {
            if (j != (i^1)) mat.m[i][j] = 1;
        }
    }
    matrix tmp; tmp.l = n,tmp.r = 1;
    for (int i : e1[a]) {
        tmp.m[1][i] = 1;
    }
    matrix ed = tmp*binpow(mat,)
    return 0;
}