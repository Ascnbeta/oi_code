#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
ll mod,a,c,x,n,g;
struct matrix {
    ll a[3][3];
    int n,m;
    inline void init(int _n,int _m) {
        memset(a,0,sizeof(a));
        n = _n,m = _m;
    }
    inline void reset() {
        for (int i = 1; i <= n; i++) a[i][i] = 1;
    }
    matrix operator* (const matrix &y) const{
        assert(m==y.n);
        matrix c;c.init(n,m);
        c.a[1][1] = ((i128)a[1][1]*y.a[1][1]+(i128)a[1][2]*y.a[2][1])%mod;
        c.a[1][2] = ((i128)a[1][1]*y.a[1][2]+(i128)a[1][2]*y.a[2][2])%mod;
        c.a[2][1] = ((i128)a[2][1]*y.a[1][1]+(i128)a[2][2]*y.a[2][1])%mod;
        c.a[2][2] = ((i128)a[2][1]*y.a[1][2]+(i128)a[2][2]*y.a[2][2])%mod;
        return c;
    }
};
inline matrix binpow(matrix base,ll b) {
    matrix ret;ret.init(base.n,base.m);ret.reset();
    while (b) {
        if (b&1ll) ret = ret * base;
        base = base * base;
        b >>= 1ll;
    }
    return ret;
}
matrix ans,trans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> mod >> a >> c >> x >> n >> g;
    ans.init(1,2);
    ans.a[1][1] = x,ans.a[1][2] = c;
    trans.init(2,2);
    trans.a[1][1] = a,trans.a[1][2] = 0;
    trans.a[2][1] = 1,trans.a[2][2] = 1;
    ans = ans * binpow(trans,n);
    cout << ans.a[1][1] % g << '\n';
    return 0;
}