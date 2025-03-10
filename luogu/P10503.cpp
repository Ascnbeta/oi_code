#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e7+7;

struct matrix{
    int a[15][15];

    int n,m;
    matrix operator * (const matrix &y) const{
        matrix c(n,m);
        
        assert(m == y.n);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= m; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k]*y.a[k][j] % mod) % mod;
                }
            }
        }
        return c;
    }
    matrix(int x,int y) {
        n = x,m = y;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                a[i][j] = 0;
            }
        }
    }
};
int N,M;
inline matrix binpow(matrix base,int b) {
    matrix ret(base.n,base.m);
    for (int i = 0; i <= ret.n; i++) {
        ret.a[i][i] = 1;
    }
    // for (int i = 0; i <= ret.n; i++) {
    //     for (int j = 0; j <= ret.m; j++)
    // }
    while (b) {
        if (b&1) ret = ret * base;
        base = base * base;
        b >>= 1;
    }

    return ret;
} 
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    while (cin >> N >> M) {
        matrix a(0,N+1);
        a.a[0][0] = 23;
        for (int i = 1; i <= N; i++) cin >> a.a[0][i];
        a.a[0][N+1] = 1;

        matrix tr(N+1,N+1);
        for (int i = 0; i <= N+1; i++) {
            for (int j = 0; j <= N+1; j++) {
                if (i == 0) {
                    if (j != N+1) tr.a[i][j] = 10;
                    else tr.a[i][j] = 0;
                }else if (i == N+1) {
                    if (j != N+1) tr.a[i][j] = 3;
                    else tr.a[i][j] = 1;
                }else{
                    if (j < i) tr.a[i][j] = 0;
                    else if (j != N+1)tr.a[i][j] = 1;
                    else tr.a[i][j] = 0;
                }
            }
        }

        if (M == 0) cout << a.a[0][N] << '\n';
        else {
            a = a * binpow(tr,M);

            cout << a.a[0][N] << '\n';
        }
    }
    return 0;
}