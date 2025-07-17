#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e3+3;
int n,m,st,ed;
int l;
int id[maxn];
struct matrix {
    int n,m;int data[102][102];
    inline void init(int _n,int _m) {
        n = _n,m = _m;
        memset(data,0x3f,sizeof(data));
    }
    inline void reset() {
        for (int i = 1; i <= n; i++) data[i][i] = 0;
    }
    int* operator [] (int p) {
        return data[p];
    }
    matrix operator * (matrix y) {
        matrix c;c.init(y.n,y.m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= m; k++) {
                    c[i][j] = min(c[i][j],data[i][k]+y[k][j]);
                }
            }
        }
        return c;
    }
}e;
inline matrix binpow(matrix base,int b) {
    matrix ret;ret.init(base.n,base.m);ret.reset();
    while (b) {
        if (b&1) ret = ret * base;
        base = base * base;
        b >>= 1;
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> l >> m >> st >> ed;
    e.init(m,m);
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> w >> u >> v;
        if (!id[u]) id[u] = ++n;
        u = id[u];
        if (!id[v]) id[v] = ++n;
        v = id[v];
        e[u][v] = e[v][u] = min(e[u][v],w);
    }
    e = binpow(e,l);
    st = id[st],ed = id[ed];
    cout << e[st][ed] << '\n';
    return 0;
}