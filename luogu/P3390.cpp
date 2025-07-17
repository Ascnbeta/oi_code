#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
int n;ll k;
struct matrix {
    int n;ll data[103][103];
    inline void init(int _n) {
        n = _n;memset(data,0,sizeof(data));
    }
    inline void reset() {
        for (int i = 1; i <= n; i++) data[i][i] = 1;
    }
    ll* operator [] (int p) {
        return data[p];
    }
    friend matrix operator * (matrix &x,matrix &y) {
        assert(x.n==y.n);
        matrix tmp = y;
        for (int i = 1; i <= x.n; i++) {
            for (int j = 1; j <= x.n; j++) {
                tmp[i][j] = y[j][i];
            }
        }
        matrix c = x;c.init(x.n);
        for (int i = 1; i <= x.n; i++) {
            for (int j = 1; j <= x.n; j++) {
                for (int k = 1; k <= x.n; k++) {
                    c[i][j] += (x[i][k]*tmp[j][k]%mod);
                    c[i][j] %= mod;
                }
            }
        }
        return c;
    }
    inline void print() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) cout << data[i][j] << ' ';
            cout << '\n';
        }
    }
}A;
inline matrix binpow(matrix base,ll b) {
    matrix ret;ret.init(base.n);ret.reset();
    while (b) {
        if (b&1ll) ret = ret * base;
        base = base * base;
        b >>= 1ll;
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k;
    A.init(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> A[i][j];
    }
    binpow(A,k).print();
    return 0;
}